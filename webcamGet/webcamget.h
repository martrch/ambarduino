#ifndef WEBCAMGET_H
#define WEBCAMGET_H

#include <QtGui/QMainWindow>
#include "ui_webcamget.h"
#include "qextserialport.h"
#include "qextserialenumerator.h"
#include "CaptureWindow.h"

class webcamGet : public QMainWindow
{
	Q_OBJECT

public:
	webcamGet(QWidget *parent = 0, Qt::WFlags flags = 0);
	~webcamGet();

private slots:
	void averageColorCalculation(QImage img);
	void on_comboBox_currentIndexChanged(int);
	void on_smooth_stateChanged(int state);
	void on_openButton_clicked();
	void on_saveButton_clicked();

private:
	void sendColor(const QColor&);

	Ui::webcamGetClass ui;

	QextSerialPort serial;
	QList<QextPortInfo> ports;

	CaptureWindow *capture;
	QextSerialPort* port;
};

#endif // WEBCAMGET_H
