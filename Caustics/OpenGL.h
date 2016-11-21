#pragma once

#include "GL/glew.h"

#include "GL/freeglut.h"

class OpenGL
{

	private:

		bool isFull;

		bool isWide;

		char* winTitle;

		long winMode;

		int viewW, viewH;

		int winW, winH;

		int ratioW, ratioH;
		
		int viewX0, viewX1, viewY0, viewY1;
		
		int winX0, winX1, winY0, winY1;

		static int GDC(int a, int b);
		
		static int LDC(int a, int b);

		int scaleW(int width, float ratio);
		
		int scaleH(int height, float ratio);

	public:
	
		OpenGL();

		~OpenGL();

		bool init(void);

		bool shut(void);

		void setMode(long mode);

		void setRatio(int width, int height);

		void setTitle(char* title);

		void setViewport(int width, int height);

		void setWindow(int width, int height);

		void setFullScreen(bool isOn);

		void setWideScreen(bool isOn);

		void setFullHD(void);

		void setUltraHD(void);

};

