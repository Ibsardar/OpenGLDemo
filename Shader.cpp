#include "Shader.h"

Shader::Shader() {

}

Shader::Shader(const Shader& shader) {

}

Shader::~Shader() {

}

Shader& Shader::operator=(const Shader& shader) {

	// self assignment
	if (this == &rhs)
		return *this;

	return *this;
}