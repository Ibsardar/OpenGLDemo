#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {

public:
	// methods
	Shader();
	Shader(const std::string & filename);
	virtual ~Shader();

	// set the GPU to use the vertex and fragment shaders from this class
	void bind();

protected:

private:
	// methods
	Shader(const Shader&);
	Shader& operator=(const Shader&);

	// variables
	// 2 for the vertex shader and the fragment shader
	static const unsigned int NUM_SHADER = 2;

	// keeps track of program handle
	GLuint m_program;

	// list of types of shaders (only vertex and fragment for now..)
	GLuint m_shaders[NUM_SHADER];

}; //end Shader

#endif // SHADER_H

