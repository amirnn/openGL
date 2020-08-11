#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "print.h"
#include "windowHandeling.h"
#include <array>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
// Define data ttpe here.
#define TypeOfData double

namespace Triangle
{
    class Triangle
    {
    private:
        std::string vertexShaderSourceCode;
        std::string fragmentShaderSourceCode;
        GLFWwindow *window;
        uint vao; // vertex array object
        uint vbo; // vertex buffer object
        uint ebo; // element buffer object
        void initWindow();
        void initGLFW();
        void initGLEW();
        void setWindowAttributes();
        void configureObject();
        void upLoadVerticies();
        void upLoadIndicies();
        void setUpShaders();
        void setUpMemoryLayout();
        void mainLoop();
        void cleanup();
        void createInstance();
        void shaderCodeReader(std::string &shaderCode, const std::string &filePath);

    public:
        uint linkedShaderProgram;

        // Constructors.
        Triangle(std::string shaderVertexPath, std::string fragmentVertexPath);
        virtual ~Triangle();

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
        struct Verticies
        {
            std::vector<TypeOfData> data = {
                -0.5, -0.5, 0.0, 0.5, -0.5,
                0.0, 0.0, 0.5, 0.0}; // within visible region of OpenGL
            unsigned sizeInBytes = data.size() * sizeof(TypeOfData);
            std::vector<uint> indices;
            std::function<uint()> getIndiciesSizeinBytes = [&]() -> uint {
                return indices.size() * sizeof(uint);
            };
        } verticies;

        // Using this I can inject functionality into the main loop.
        std::vector<std::function<void()>> runable;
    };
} // namespace Triangle
