#shader vertex
#version 410 core
    layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

out vec3 ourColor;
out vec3 ourPosition;
uniform float Offset;

void main() {
gl_Position = vec4(aPos.x + Offset, aPos.y + Offset, aPos.z, 1.0);
ourColor = aCol;
}

#shader fragment
#version 410 core
    out vec4 FragColor;
in vec3 ourPosition;
in vec3 ourColor;

void main() {
FragColor = vec4(ourColor,1.0f);
}
