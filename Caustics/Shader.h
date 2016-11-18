#pragma once

#include <string>

#include "OpenGL.h"
#include "Shader.h"

using namespace std;

class Shader
{

	private:
		
		bool areCompiled;						// are shaders compiled?
		bool areLinked;							// is shader linked?

		char* fragName;							// fragment shader name
		char* geomName;							// geometry shader name
		char* vertName;							// vertex shader name

		GLchar* fragData;						// fragment shader
		GLchar* geomData;						// geometry shader
		GLchar* vertData;						// vertex shader

		GLint fragSize;							// fragment size
		GLint geomSize;							// geometry size
		GLint vertSize;							// vertex size

		GLint fragProgram;						// fragment program
		GLint geomProgram;						// geometry program
		GLint vertProgram;						// vertex program

		GLuint fragObject;						// fragment object
		GLuint geomObject;						// geometry object
		GLuint vertObject;						// vertex object

		GLchar infoLog[1024];					// info log
		GLchar errorLog[1024];					// error log

	public:
	
		Shader();								// shader constructor
		~Shader();								// shader detructor

		bool loadFS(char* path);				// load fragment shader
		bool loadGS(char* path);				// load geometry shader
		bool loadVS(char* path);				// load vertex shader

		bool saveFS(char* path);				// save fragment shader
		bool saveGS(char* path);				// save geometry shader
		bool saveVS(char* path);				// save vertex shader

		bool compileFS(void);					// compile fragment shader
		bool compileGS(void);					// compile geometry shader
		bool compileVS(void);					// compile vertex shader

		bool uncompileFS(void);					// uncompile 
		bool uncompileGS(void);					// uncompile
		bool uncompileVS(void);					// uncompile

		bool linkFS(void);						// link fragment shader
		bool linkGS(void);						// link geometry shader
		bool linkVS(void);						// link vertex shader

		bool unlinkFS(void);					// unlink
		bool unlinkGS(void);					// unlink
		bool unlinkVS(void);					// unlink
			
};

