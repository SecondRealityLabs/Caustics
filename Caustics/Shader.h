#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "OpenGL.h"

using namespace std;

class Shader
{

	private:

		int noOfFS;								// number of fragment shaders
		int noOfGS;								// number of geometry shaders
		int noOfVS;								// number of vertex shaders

		vector<char*> fragNames;				// fragment shaders names
		vector<char*> geomNames;				// geometry shaders names
		vector<char*> vertNames;				// vertex shaders names

		vector<GLchar*> fragDatas;				// fragment shaders datas
		vector<GLchar*> geomDatas;				// geometry shaders datas
		vector<GLchar*> vertDatas;				// vertex shaders datas

		vector<GLint> fragSizes;				// fragment shaders sizes
		vector<GLint> geomSizes;				// geometry shaders sizes
		vector<GLint> vertSizes;				// vertex shaders sizes

		vector<GLuint> fragObjects;				// fragment shaders objects
		vector<GLuint> geomObjects;				// geometry shaders objects
		vector<GLuint> vertObjects;				// vertex shaders objects

		GLuint program;							// program

		GLchar compileLog[1024];				// compile logs
		GLchar linkLog[1024];					// link logs

	public:
	
		Shader();								// shader constructor
		~Shader();								// shader detructor

		bool addFS(int id, char* path);			// add fragment shader
		bool addGS(int id, char* path);			// add geometry shader
		bool addVS(int id, char* path);			// add vertex shader

		bool delFS(int id, char* path);			// del fragment shader
		bool delGS(int id, char* path);			// del geometry shader
		bool delVS(int id, char* path);			// del vertex shader
		
		bool compileFS(int id);					// compile fragment shader
		bool compileGS(int id);					// compile geometry shader
		bool compileVS(int id);					// compile vertex shader

		bool uncompileFS(int id);				// uncompile fragment shader
		bool uncompileGS(int id);				// uncompile geometry shader
		bool uncompileVS(int id);				// uncompile vertex shader

		bool linkFS(int id);					// link fragment shader
		bool linkGS(int id);					// link geometry shader
		bool linkVS(int id);					// link vertex shader

		bool unlinkFS(int id);					// unlink fragment shader
		bool unlinkGS(int id);					// unlink geometry shader
		bool unlinkVS(int id);					// unlink vertex shader

		bool compile();							// compile all shaders
		bool link();									// link all shaders

		bool uncompile();								// uncompile all shaders
		bool unlink();									// unlink all shaders

		bool printLogs();								// print logs
		bool unprintLogs();								// unprint logs

		void addShader(GLuint, const char*, GLenum);
		void compileShaders(char*, char*);
		bool readFile(const char* , string&);

};

