// Caustics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "OpenGL.h"
#include "Scene.h"
#include "main.h"

// Global vars
static float rotX, rotY, rotZ;
Vertex vertices[4];
unsigned int edges[12];
GLuint VBO;
GLuint EBO;
GLuint WVP;
GLuint sampler;

// Global funcs
void initEdgeBuffer(void);
void initVertexBuffer(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void render(void);

// Main 
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
		glutMouseFunc(&mouse);

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

void keyboard(unsigned char key, int x, int y)
{
	// escape
	//	if (key == 27)
	//		exit(0);


	// rotate x
	//	if (key == )
	//		rotX += 0.001f;


	// rotate y
	//	if (key == )
	//		rotY += 0.001f;


	// rotate z
	//	if (key == )
	//		rotZ += 0.001f;

}

void mouse(int button, int state, int x, int y)
{






//	if (button == GLUT_DOWN)
//		Camera.;


	
//	if (button == GL)
//		Camera.;






}

void render(void)
{
	// setup
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

		// update

	// swap 
	glutSwapBuffers();
}

void initEdgeBuffer(void)
{

	// edges
	edges[0x0] = 0; edges[0x1] = 3; edges[0x2] = 1;
	edges[0x3] = 1; edges[0x4] = 3; edges[0x5] = 2;
	edges[0x6] = 2; edges[0x7] = 3; edges[0x8] = 0;
	edges[0x9] = 0; edges[0xA] = 1; edges[0xB] = 2;

	// bind
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(edges), edges, GL_STATIC_DRAW);

}

void initVertexBuffer(void)
{

	// vertices
	vertices[0].x = -1.00f; vertices[0].y = -1.00f; vertices[0].z = +0.57f; 
	vertices[0].u = +0.0f; vertices[0].v = +0.0f;

	vertices[1].x = +0.00f; vertices[1].y = -1.00f; vertices[1].z = -1.15f; 
	vertices[1].u = +0.5f; vertices[1].v = +0.0f;
	
	vertices[2].x = +1.00f; vertices[2].y = -1.00f; vertices[2].z = +0.57f; 
	vertices[2].u = +1.0f; vertices[2].v = +0.0f;
	
	vertices[3].x = +0.00f; vertices[3].y = +1.00f; vertices[3].z = +0.57f; 
	vertices[3].u = +0.5f; vertices[3].v = +1.0f;
		
	// bind
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}



				
	
















































