#ifndef SHADER_H
#define SHADER_H

class Shader {

public:
	// methods
	Shader();
	virtual ~Shader();

protected:

private:
	// methods
	Shader(const Shader& shader);
	Shader& operator=(const Shader& shader);

}; // Shader

#endif // SHADER_H

