#include "stdafx.h"
#include "Window.h"

double Window::startX = 0.0f;
double Window::startY = 0.0f;
double Window::xoffset = 0.0f;
double Window::yoffset = 0.0f;

GLfloat Window::deltaTime = 0.1f;
GLfloat Window::lastFrame = 0.0f;


Window::Window()
{}

Window::~Window()
{}

void Window::clearColorAndDepthBuffers()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::createWindow(int width, int height)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Couldn't initialize GLFW library.\n");
		return;
	}

	/* Create a windowed mode window and its OpenGL context */
	Wnd = glfwCreateWindow(width, height, "Caustics", NULL, NULL);
	if (!Wnd)
	{
		glfwTerminate();
		fprintf(stderr, "Couldn't create window.\n");
		return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(Wnd);

	glewExperimental = GL_TRUE;

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setCallbacks();
}

void Window::update()
{
	GLfloat currentFrame = (GLfloat)glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Window::close()
{
	glfwTerminate();
}

void Window::swapBuffersPollEvents()
{
	glfwSwapBuffers(Wnd);

	glfwPollEvents();
}


bool Window::isClosed()
{
	return glfwWindowShouldClose(Wnd);
}

void Window::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

}

void Window::window_resize_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::setCallbacks()
{
	glfwSetKeyCallback(Wnd, this->key_callback);
	glfwSetWindowSizeCallback(Wnd, this->window_resize_callback);
}
