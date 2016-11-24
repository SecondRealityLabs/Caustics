// Caustics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "OpenGL.h"
#include "Scene.h"
#include "main.h"

void keyboard(unsigned char, int, int);
void render(void);

int main(int argC, char* argV[])
{

	// vars
	OpenGL openGL;

	Shader shCaustic;
	Shader shCube;
	Shader shDrop;
	Shader shNormal;
	Shader shSphere;
	Shader shUber;
	Shader shUpdate;
	Shader shWater;
	
		// init OpenGL
		openGL.init();
		openGL.setTitle("Caustics (c) SciVFX 2016");
		openGL.setWindow(640, 480);
//		openGL.setFullScreen(true);
//		openGL.setWideScreen(true);

		// init GLEW
		GLenum res = glewInit();

		if (res != GLEW_OK)
		{
			fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
			return 1;
		}

		// setup callbacks
		glutDisplayFunc(&render);
		glutIdleFunc(&render);
		glutKeyboardFunc(&keyboard);

		// check Shaders
		shCaustic.compileShaders("d:\\caustic.frag", "d:\\caustic.vert");
		shCube.compileShaders("d:\\cube.frag", "d:\\cube.vert");
		shDrop.compileShaders("d:\\drop.frag", "d:\\drop.vert");
		shNormal.compileShaders("d:\\normal.frag", "d:\\normal.vert");
		shSphere.compileShaders("d:\\sphere.frag", "d:\\sphere.vert");
		shUber.compileShaders("d:\\uber.frag", "d:\\uber.vert");
		shUpdate.compileShaders("d:\\update.frag", "d:\\update.vert");
		shWater.compileShaders("d:\\water.frag", "d:\\water.vert");
	
		// main loop			
		glutMainLoop();

		// shut OpenGL
		openGL.shut();

	// exit	
	return 0;

}

void render(void)
{
	// clear color
	glClearColor(0.0, 0.0, 0.0, 1.0);






		// update scene





	// swap buffers
	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{

	if (key == 27)
		exit(0);

}


				
	

























