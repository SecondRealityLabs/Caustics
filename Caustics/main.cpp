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

	//shCaustic.compileShaders("Caustic.fs.glsl", "Caustic.vs.glsl");

	EntityMesh = new Mesh();
	EntityMesh->load("Resources", "submarine.obj");
	EntityMesh->setTextures("Resources/", { "txt-subm-1.jpg" });

	//vec3 Vertices[3];
	/*EntityMesh->render();*/
	//Vertices[0] = vec3(-0.5f, 0.0f, 0.0f);
	//Vertices[1] = vec3(0.5f, 0.0f, 0.0f);
	//Vertices[2] = vec3(0.0f, 0.5f, 0.0f);

	//GLuint VBO;
	//glGenBuffers(1, &VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); //size in bytes, target same as in binding, not changing contents-?static draw

	ShaderProgram = glCreateProgram();
	GLuint vertexShaderObj = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderObj = glCreateShader(GL_FRAGMENT_SHADER);

	string vertexShaderText;
	string fragmentShaderText;
	const GLchar* fs, *vs;
	const char* vsFileName = "Shaders/Caustic.vs.glsl";
	const char* fsFileName = "Shaders/Caustic.fs.glsl";

	Shader::readFile(vsFileName, vertexShaderText);
	Shader::readFile(fsFileName, fragmentShaderText);
	vs = vertexShaderText.c_str();
	fs = fragmentShaderText.c_str();

	GLint Lengths[2];
	Lengths[0] = strlen(vertexShaderText.c_str());
	Lengths[1] = strlen(fragmentShaderText.c_str());

	glShaderSource(vertexShaderObj, 1, &vs, &Lengths[0]);
	glShaderSource(fragmentShaderObj, 1, &fs, &Lengths[1]);

	glCompileShader(vertexShaderObj);
	glCompileShader(fragmentShaderObj);

	GLint success;
	glGetShaderiv(vertexShaderObj, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar InfoLog[1024];
		glGetShaderInfoLog(vertexShaderObj, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, InfoLog);
	}

	glGetShaderiv(fragmentShaderObj, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar InfoLog[1024];
		glGetShaderInfoLog(fragmentShaderObj, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, InfoLog);
	}

	glAttachShader(ShaderProgram, vertexShaderObj);
	glAttachShader(ShaderProgram, fragmentShaderObj);
	glLinkProgram(ShaderProgram);

	glDeleteShader(vertexShaderObj);
	glDetachShader(ShaderProgram, vertexShaderObj);
	glDeleteShader(fragmentShaderObj);
	glDetachShader(ShaderProgram, fragmentShaderObj);

	int Success;
	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0)
	{
		GLchar ErrorLog[1024];
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
	}
	glValidateProgram(ShaderProgram);
	glUseProgram(ShaderProgram);

	gSampler = glGetUniformLocation(ShaderProgram, "gSampler");
	//assert(gSampler != 0xFFFFFFFF);

	glUniform1i(gSampler, 0);


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


	//glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	
	//glDisableVertexAttribArray(0);


	// swap 
	glutSwapBuffers();
}