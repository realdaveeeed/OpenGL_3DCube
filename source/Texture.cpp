//
// Created by Dávid Fabriczius on 2025. 09. 28..
//

#include "Texture.h"
#include <iostream>
#include "stb_image.h"

Texture::Texture(const std::string filePath, unsigned int imageFormat, GLenum texType) {

    stbi_set_flip_vertically_on_load(true);
    data = stbi_load(filePath.c_str(),&width,&height,&nrChannels,0);
    glGenTextures(1,&ID);
    glBindTexture(GL_TEXTURE_2D,ID);
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else { std::cout << "Failed to load texture" << std::endl; }

    stbi_image_free(data);
}

Texture::~Texture() {
    glDeleteTextures(1, &ID);
}

void Texture::Bind(unsigned int target) {
    glActiveTexture(target);
    glBindTexture(GL_TEXTURE_2D,ID);

}

void Texture::Unbind() {
    glBindTexture(GL_TEXTURE_2D,0);
}