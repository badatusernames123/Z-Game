#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <glad/glad.h>

class Shader {
private:
	void read_file(const std::string& filename, std::string& dest);

	// Return compled shader id
	unsigned int compile_shader(const std::string& source, const std::string& shader_type);

public:
	unsigned int program;

	Shader(const std::string& frag_file, const std::string& vert_file);

	void use_program();

	void set_bool(const std::string& name, bool value) const;
	void set_int(const std::string& name, int value) const;
	void set_float(const std::string& name, float value) const;
};


#endif