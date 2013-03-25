#include "webcamget.h"
#include "opencv2\opencv.hpp"
#include <QMessageBox>
#include <QTimer>
#include <QInputDialog>
#include <qDebug>


webcamGet::webcamGet(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags), port(NULL)
{
	capture = new CaptureWindow();

	ui.setupUi(this);

	ports = QextSerialEnumerator::getPorts();
	for (int i = 0; i < ports.size(); i++)
		this->ui.comboBox->addItem(ports[i].physName + " " + ports[i].enumName);

	connect(capture, SIGNAL(sendImg(QImage)), this, SLOT(averageColorCalculation(QImage)));

	ui.comboBox->setCurrentIndex(ports.size() - 1);
}

void webcamGet::on_comboBox_currentIndexChanged(int id)
{
	port =  new QextSerialPort(ports[id].portName);
	port->setBaudRate(BAUD38400);
	port->open(QIODevice::WriteOnly);
}

void webcamGet::on_smooth_stateChanged(int)
{
	if (ui.smooth->isChecked())
		capture->setSmooth(true);
	else
		capture->setSmooth(false);
}

void webcamGet::on_openButton_clicked()
{
}

void webcamGet::on_saveButton_clicked()
{

}

void webcamGet::sendColor(const QColor& color)
{
	if (port != NULL)
	{
		char r = color.red() - 128;
		char g = color.green() - 128;
		char b = color.blue() - 128;

		QByteArray ar;
		ar.append((char*)&r);
		ar.append((char*)&g);
		ar.append((char*)&b);
		port->write(ar, 3);
	}
}

void webcamGet::averageColorCalculation(QImage img)
{

	QList<QColor> pixels; //QQueue unaviable but the doc says qqueues Inherits QList.
	QPixmap px;

	//Construct a list of colors, one for each leds in this order :
	//
	//    1  2  3  4  5  6  7  8  9
	//   24                      10
	//   23                      11
	//   22                      12
	//   21 20 19 18 17 16 15 14 13
	//
	for (int i = 0; i < 9; i++)
		pixels << QColor::fromRgb(img.pixel(i ,0));
	pixels << QColor::fromRgb(img.pixel(8 ,1));
	pixels << QColor::fromRgb(img.pixel(8 ,2));
	pixels << QColor::fromRgb(img.pixel(8 ,3));
	for (int i = 8; i >= 0; i--)
		pixels << QColor::fromRgb(img.pixel(i ,3));
	pixels << QColor::fromRgb(img.pixel(0 ,3));
	pixels << QColor::fromRgb(img.pixel(0 ,2));
	pixels << QColor::fromRgb(img.pixel(0 ,1));

	//Send the list of pixel to the arduino with the custom saturation
	for (QList<QColor>::Iterator it = pixels.begin(); it != pixels.end(); ++it)
	{
		it->setHsv(it->hue(), it->saturation() + ui.saturation->value() > 255 ? 255 : it->saturation() + ui.saturation->value(), it->value());
		sendColor(*it);
	}

	if (port != NULL)
	{
		//Send 1 byte with 42 as a arbitrary value for synchronisation correction
		QByteArray ar;
		ar.append(42);
		port->write(ar, 1);
		port->flush();
	}
	img = img.scaled(320, 180, Qt::IgnoreAspectRatio);
	this->ui.label->setPixmap(QPixmap::fromImage(img));
}

webcamGet::~webcamGet()
{
	for (int i= 0; i < 24; i++)
		sendColor(QColor(0, 0, 0));
	capture->release();
	delete capture;
}