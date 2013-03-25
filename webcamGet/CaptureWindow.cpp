#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>


#include "CaptureWindow.h"


CaptureWindow::CaptureWindow(void) : smooth(true)
{
	QTimer *timer = new QTimer(this);
	//timer->moveToThread(thread);
	connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
	timer->start(33);

	#ifdef Q_WS_WIN
	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
    hDesktopWnd = GetDesktopWindow();
    hDesktopDC = GetDC(hDesktopWnd);
    hCaptureDC = CreateCompatibleDC(hDesktopDC);
    hCaptureBitmap =CreateCompatibleBitmap(hDesktopDC, 
                            nScreenWidth, nScreenHeight);
    SelectObject(hCaptureDC,hCaptureBitmap); 
	#endif
}

void CaptureWindow::setSmooth(bool smooth)
{
	this->smooth = smooth;
	
}

void CaptureWindow::release()
{
	#ifdef Q_WS_WIN
	ReleaseDC(hDesktopWnd,hDesktopDC);
    DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);
	#endif
}

void CaptureWindow::refresh()
{
	QPixmap screen;

	#ifdef Q_WS_WIN
    BitBlt(hCaptureDC,0,0,nScreenWidth,nScreenHeight,
           hDesktopDC,0,0,SRCCOPY|CAPTUREBLT); 


	screen = QPixmap::fromWinHBITMAP(hCaptureBitmap);
	

	#else
	screen = QPixmap::grabWindow(QApplication::desktop()->winId(), 0, 0, 1920/2, 1080);
	#endif

	if (smooth)
		screen = screen.scaled(9, 5, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	else
		screen = screen.scaled(9, 5, Qt::IgnoreAspectRatio);
	emit sendImg(screen.toImage());
}