
#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glm/glm.hpp>



class Shader {
public:
    unsigned int ID;
    Shader(const char* filePath);
    ~Shader();
    void use() const;
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

    void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
    static unsigned int compileShader(unsigned int type, const char *shaderSource);
    static void checkShaderComp(const unsigned int *shader);
    static void checkShaderProgram(const unsigned int *shaderProgram);
};


#endif