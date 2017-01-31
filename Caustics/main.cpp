// Caustics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "OpenGL.h"
#include "Scene.h"
#include "main.h"

// Global vars
static float rotX, rotY, rotZ;
GLuint VBO;
GLuint EBO;
GLuint WVP;
GLuint sampler;
GLuint ShaderProgram;
GLuint gSampler;
Mesh* EntityMesh;
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
	/*glutKeyboardFunc(&keyboard);
	glutMouseFunc(&mouse);*/



	// check Shaders
	/*shCaustic.compileShaders("Shaders/caustic.frag", "Shaders/caustic.vert");
	shCube.compileShaders("Shaders/cube.frag", "Shaders/cube.vert");
	shDrop.compileShaders("Shaders/drop.frag", "Shaders/drop.vert");
	shNormal.compileShaders("Shaders/normal.frag", "Shaders/normal.vert");
	shSphere.compileShaders("Shaders/sphere.frag", "Shaders/sphere.vert");
	shUber.compileShaders("Shaders/uber.frag", "Shaders/uber.vert");
	shUpdate.compileShaders("Shaders/update.frag", "Shaders/update.vert");
	shWater.compileShaders("Shaders/water.frag", "Shaders/water.vert");*/

	ShaderProgram = shUber.compileShaders("Shaders/uber.frag", "Shaders/uber.vert"); //shCaustic.compileShaders("Caustic.fs.glsl", "Caustic.vs.glsl");
	
	gSampler = glGetUniformLocation(ShaderProgram, "gSampler");
	//assert(gSampler != 0xFFFFFFFF);

	glUniform1i(gSampler, 0);

	EntityMesh = new Mesh();
	EntityMesh->load("Resources", "submarine.obj");
	EntityMesh->setTextures("Resources/", { "txt-subm-1.jpg" });

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
{}

void render(void)
{
	EntityMesh->render();

	glValidateProgram(ShaderProgram);
	glUseProgram(ShaderProgram);

	// swap 
	glutSwapBuffers();
}