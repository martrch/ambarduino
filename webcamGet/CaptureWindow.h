#ifndef CAPTUREWINDOW_H
#define CAPTUREWINDOW_H

#include <QObject>

#ifdef Q_WS_WIN
#include <windows.h>
#endif

#include "capturestream.h"

class CaptureWindow :
	public  QObject
{
	Q_OBJECT
public:
	CaptureWindow(void);
	virtual void release();
	virtual void setSmooth(bool);

private slots:
	virtual void refresh();

signals:
	void sendImg(QImage);

private:
	bool smooth;

	int balance;

	#ifdef Q_WS_WIN
	int nScreenWidth;
    int nScreenHeight;
    HWND hDesktopWnd;
    HDC hDesktopDC;
    HDC hCaptureDC;
	HBITMAP hCaptureBitmap;
	#endif
};

#endif