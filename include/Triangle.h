#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "print.h"
#include "windowHandeling.h"
#include <exception>
#include <array>
#include <fstream>
#include <sstream>

namespace Triangle
{
    class Triangle
    {
    private:
        struct Verticies
        {
            // within visible region of OpenGL
            std::array<double, 9> data{
                -0.5, -0.5, 0.0,
                0.5, -0.5, 0.0,
                0.0, 0.5, 0.0};
            unsigned sizeInBytes = data.size() * sizeof(double);
        } verticies;

        std::string vertexShaderSourceCode;
        std::string fragmentShaderSourceCode;
        uint linkedShaderProgram;
        GLFWwindow *window;
        uint vbo;
        void initWindow();
        void initGLFW();
        void initGLEW();
        void setWindowAttributes();
        void upLoadVerticies();
        void setUpShaders();
        void setUpMemoryLayout();
        void mainLoop();
        void cleanup();
        void createInstance();
        void shaderCodeReader(std::string& shaderCode, const std::string& filePath);

    public:
        Triangle();
        void run()
        {
            initGLFW();
            initWindow();
            initGLEW();
            setWindowAttributes();
            upLoadVerticies();
            setUpShaders();
            setUpMemoryLayout();
            mainLoop();
        };
        virtual ~Triangle();
    };
} // namespace Triangle
