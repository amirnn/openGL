#version 450 core
out vec4 FragColor;  
in vec3 vOColor; // will link to vertex shader.
void main()
{
    FragColor = vec4(vOColor, 1.0);
}