#include "stdafx.h"
#include "OpenGL.h"

OpenGL::OpenGL()
{
}

OpenGL::~OpenGL()
{
}

int OpenGL::GDC(int a, int b)
{
	
	return (b == 0) ? a : GDC(b, a%b);
	
}

int OpenGL::scaleW(int width, float ratio)
{
	int ret;
		
		ret = (int) (width * ratio);

	return ret;
}

int OpenGL::scaleH(int height, float ratio)
{
	int ret;

		ret = (int) (height * ratio);

	return ret;
}

bool OpenGL::init(void)
{
	
	return false;

}

bool OpenGL::shut(void)
{
	return false;
}

void OpenGL::setMode(long mode)
{
	winMode = mode;
}

void OpenGL::setTitle(char * title)
{
//	strcpy(winTitle, title);
}

void OpenGL::setWindow(int width, int height)
{
	winW = width;
	winH = height;
}

void OpenGL::setViewport(int width, int height)
{
	viewH = width;
	viewW = height;
}

void OpenGL::setFullScreen(bool isOn)
{

	isFull = isOn;

//	glutFullScreen();

}

void OpenGL::setWideScreen(bool isOn)
{

	int ratio;

		isWide = isOn;

		// setup 4:3
		ratio = (int)(winW / 4);
		winW = 4 * ratio;
		winH = 3 * ratio;

		// setup 16:9
		ratio = (int)(winW / 16);
		winW = 16 * ratio;
		winH = 9 * ratio;

	return;

}


























