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
            double data[9] = {
                -0.5, -0.5, 0.0,
                0.5, -0.5, 0.0,
                0.0, 0.5, 0.0};
            unsigned sizeInBytes = sizeof(data);
        } verticies;

        std::string vertexShaderSourceCode;
        std::string fragmentShaderSourceCode;
        uint linkedShaderProgram;
        GLFWwindow *window;
        uint vao;
        uint vbo;
        void initWindow();
        void initGLFW();
        void initGLEW();
        void setWindowAttributes();
        void configureObject();
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
            configureObject();
            setUpShaders();
            mainLoop();
        };
        virtual ~Triangle();
    };
} // namespace Triangle
