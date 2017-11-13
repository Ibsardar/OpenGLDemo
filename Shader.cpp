#include "Shader.h"
#include <iostream>
#include <fstream>

/// Define helper functions here: ------
static std::string LoadShader(const std::string & filename);
static void CheckShaderError(GLuint shader, GLuint flag, bool is_program,
	const std::string & error_msg);
/// ------------------------------------

Shader::Shader() {

	// ...
}

Shader::Shader(const std::string & filename) {

	// store program handle after creating the program
	this->m_program = glCreateProgram();
	
	// HERE!!!
}

Shader::Shader(const Shader& shader) {

	// free memory of created program
	glDeleteProgram(this->m_program);
}

Shader::~Shader() {

}

Shader& Shader::operator=(const Shader& rhs) {

	// self assignment
	if (this == &rhs)
		return *this;

	return *this;
}

//
//	Helper functions below:
//

// loads a shader file
static std::string LoadShader(const std::string & filename) {

	std::ifstream file;
	file.open(filename.c_str());

	std::string output;
	std::string line;

	if (file.is_open()) {
		
		while (file.good()) {
			
			getline(file, line);
			output.append(line + "\n");
		}

	} else {

		std::cerr << "Unable to load shader: " << filename << std::endl;
	}

	return output;
}

// checks for shader errors
void CheckShaderError(GLuint shader, GLuint flag, bool is_program,
	const std::string & error_msg) {

	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (is_program)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE) {

		if (is_program)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << error_msg << ": '" << error << "'" << std::endl;
	}
}
