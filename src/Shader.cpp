#include "Shader.h"



Shader::Shader(const std::string& vert_file, const std::string& frag_file) {
	// Read source from file
    std::string vert_source;
    std::string frag_source;
	read_file("../" + vert_file, vert_source);
	read_file("../" + frag_file, frag_source);

	// Compile each shader
    unsigned int vert_id = compile_shader(vert_source, "vertex");
    unsigned int frag_id = compile_shader(frag_source, "fragment");
    
    // Link shader program
    int  success;
    char infoLog[512];
    program = glCreateProgram();
    glAttachShader(program, vert_id);
    glAttachShader(program, frag_id);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vert_id);
    glDeleteShader(frag_id);	
}

unsigned int Shader::compile_shader(const std::string& source, const std::string& shader_type) {
    int  success;
    char infoLog[512];
    const char* src = source.c_str();

    unsigned int shader_id;
    if (shader_type == "vertex") {
        shader_id = glCreateShader(GL_VERTEX_SHADER);
    }
    else if (shader_type == "fragment") {
        shader_id = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else {
        std::cout << "ERROR::SHADER::SHADER_TYPE" << std::endl;
        return 0;
    }
    
    glShaderSource(shader_id, 1, &src, NULL);
    glCompileShader(shader_id);

    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader_id;
}

void Shader::read_file(const std::string& filename, std::string& dest) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file\n";
        return;
    }

    // Use a stringstream to capture the whole file
    std::stringstream buffer;
    buffer << file.rdbuf();

    dest = buffer.str();
    std::cout << dest << "\n";

    file.close();
}

void Shader::use_program() {
    glUseProgram(program);
}

void Shader::set_bool(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(program, name.c_str()), (int)value);
}

void Shader::set_float(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::set_int(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}