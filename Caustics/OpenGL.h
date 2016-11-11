#pragma once

class OpenGL
{
	
	private:

		bool isWideScreen;
		bool isFullScreen;

		float windowHeight;
		float windowWidth;

		float viewportHeight;
		float viewportWidth;

		char* windowTitle;

	public:
	
		OpenGL();
		~OpenGL();

		bool init(void);
		bool shut(void);

		void setTitle(const char* title);
		void setWindow(int x0, int y0, int x1, int y1);
		void setViewport(int x0, int y0, int x1, int y1);
		void setFullScreen(bool isOn);
		void setWideScreen(bool isOn);

		void setMouse();










};

