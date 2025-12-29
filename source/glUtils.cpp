#include "glUtils.h"

#include <iostream>


namespace glUtils {
    void OpenGLInformation() {
        std::cout << "OpenGL Vendor:\t" << glGetString(GL_VENDOR)   << "\n";
        std::cout << "OpenGL Renderer:\t" << glGetString(GL_RENDERER) << "\n";
        std::cout << "OpenGL Version:\t" << glGetString(GL_VERSION)  << "\n";
        std::cout << "GLSL Version:\t" << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";

        int nrAttributes;
        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
        std::cout << "OpenGL Maximum Vertex Attributes:\t" << nrAttributes << std::endl;
    }
    void checkShaderProgram(const unsigned int *shaderProgram) {
        int success;
        char infoLog[512];

        glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(*shaderProgram, 512, nullptr, infoLog);
            std::cout << "OPENGL ERROR: Shader Program Link Failed: "<<infoLog<<std::endl;
        }
    }

}
