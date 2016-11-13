#pragma once
#include "stdafx.h"

class Window
{

public:
	Window();
	~Window();
	void clearColorAndDepthBuffers();
	void createWindow(int width, int height);
	void update();
	void close();
	void swapBuffersPollEvents();
	bool isClosed();

private:
	static double startX, startY, xoffset, yoffset;
	static GLfloat deltaTime;
	static GLfloat lastFrame;

	GLFWwindow* Wnd;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void window_resize_callback(GLFWwindow* window, int width, int height);

	void setCallbacks();
};