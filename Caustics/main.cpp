// Caustics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "OpenGL.h"
#include "Scene.h"
#include "main.h"

int main(int argC, char* argV[])
{

	// vars
	OpenGL openGL;
	Shader shCube;
	
		// init OpenGL
		openGL.init();
		openGL.setTitle("Caustics (c) SciVFX 2016");
		openGL.setWindow(1920, 1440);
		openGL.setFullScreen(true);
		openGL.setWideScreen(true);

		glutInit(&argC, argV);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(1024, 768);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Tutorial 04"); 

		// init GLEW
		GLenum res = glewInit();

		if (res != GLEW_OK)
		{
			fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
			return 1;
		}

		// check Shaders

		shCube.addFS(0, "d:\\raytrace.vs");
		shCube.addFS(1, "d:\\raytrace.fs");
		shCube.addFS(2, "d:\\cube.fs");
		shCube.addVS(0, "d:\\raytrace.vs");
		shCube.addVS(1, "d:\\cube.vs");

		shCube.compile();
		shCube.link();

		shCube.printLogs();
		_getch();

		// shut OpenGL
		openGL.shut();

	// exit	
	return 0;

}

							


				
	





