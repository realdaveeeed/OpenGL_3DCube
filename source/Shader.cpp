//
// Created by Dávid Fabriczius on 2025. 09. 21..
//

#include "Shader.h"
#include "glUtils.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* filePath) {

    /* Checking if file is valid, and can be opened */
    std::ifstream stream(filePath);
    if (!stream.is_open()) { throw std::runtime_error("Failed to open shader file: " + std::string(filePath)); }

    enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

    std::string line;
    std::stringstream vertexStream, fragmentStream;
    ShaderType type = ShaderType::NONE;

    /* Seperating the frag, and vertex shader from each other*/
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            if (type == ShaderType::VERTEX) {
                vertexStream << line << "\n";
            } else if (type == ShaderType::FRAGMENT) {
                fragmentStream << line << "\n";
            }
        }
    }

    /* Assigning the shader codes to const chars */
    std::string vShaderStr = vertexStream.str();
    std::string fShaderStr = fragmentStream.str();

    const char* vShaderCode = vShaderStr.c_str();
    const char* fShaderCode = fShaderStr.c_str();

    /* Compiling the shaders */
    unsigned int vShader = compileShader(GL_VERTEX_SHADER, vShaderCode);
    checkShaderComp(&vShader);
    unsigned int fShader = compileShader(GL_FRAGMENT_SHADER, fShaderCode);
    checkShaderComp(&fShader);

    /* Creating the shader program, and binding the shaders to it */
    ID = glCreateProgram();
    glAttachShader(ID, vShader);
    glAttachShader(ID, fShader);
    glLinkProgram(ID);
    checkShaderProgram(&ID);

    /* Deleting the binded shaders */
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

Shader::~Shader() {
    glDeleteProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(value));
}

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setMat4(const std::string &name, glm::mat4 value) {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()),1 ,GL_FALSE, glm::value_ptr(value));
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::use() const { glUseProgram(ID); }

unsigned int Shader::compileShader(unsigned int type, const char *shaderSource) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);
    return shader;
}

void Shader::checkShaderComp(const unsigned int *shader) {
    int  success;
    GLint shaderType;
    char infoLog[512];
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
    glGetShaderiv(*shader, GL_SHADER_TYPE, &shaderType);

    if(!success)
    {
        if (shaderType == GL_VERTEX_SHADER) {
            glGetShaderInfoLog(*shader, 512, nullptr, infoLog);
            std::cout << "ERROR: VERTEX SHADER COMP FAILED\n" << infoLog << std::endl;
        } else if (shaderType == GL_FRAGMENT_SHADER) {
            glGetShaderInfoLog(*shader, 512, nullptr, infoLog);
            std::cout << "ERROR: FRAGMENT SHADER COMP FAILED\n" << infoLog << std::endl;
        }

    }
}

void Shader::checkShaderProgram(const unsigned int *shaderProgram) {
    int success;
    char infoLog[512];

    glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(*shaderProgram, 512, nullptr, infoLog);
        std::cout << "OPENGL ERROR: Shader Program Link Failed: "<<infoLog<<std::endl;
    }
}
