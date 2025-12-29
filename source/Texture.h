//
// Created by Dávid Fabriczius on 2025. 09. 28..
//

#ifndef INC_3DCUBE_TEXTURE_H
#define INC_3DCUBE_TEXTURE_H
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Texture {
public:
    int width, height, nrChannels;
    unsigned int ID;
    unsigned char* data;
    unsigned int texture;
    Texture(const std::string filePath, unsigned int imageFormat ,GLenum texType = GL_TEXTURE_2D);
    ~Texture();

    void Bind(unsigned int target = GL_TEXTURE0);

    void Use();

    void Unbind();
};


#endif //INC_3DCUBE_TEXTURE_H