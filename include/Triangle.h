#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "print.h"
#include "windowHandeling.h"
#include <exception>
#include <array>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>

namespace Triangle
{
    class Triangle
    {
    private:
        std::string vertexShaderSourceCode;
        std::string fragmentShaderSourceCode;
        uint linkedShaderProgram;
        GLFWwindow *window;
        uint vao; //vertex array object
        uint vbo; //vertex buffer object
        uint ebo;  //element buffer object
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
        struct Verticies
        {
            // within visible region of OpenGL
            std::vector<double> data = {
                -0.5, -0.5, 0.0,
                0.5, -0.5, 0.0,
                0.0, 0.5, 0.0};
            unsigned sizeInBytes = data.size() * sizeof(double);
            std::vector<uint> indices;
            std::function<uint()> getIndiciesSizeinBytes = [&]()->uint{ return indices.size() * sizeof(uint);};
        } verticies;
        virtual ~Triangle();
    };
} // namespace Triangle
