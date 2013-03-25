#include "webcamget.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	webcamGet w;
	w.show();
	return a.exec();
}
