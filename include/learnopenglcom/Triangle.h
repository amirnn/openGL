#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "print.h"
#include "windowHandeling.h"
#include <exception>

class Triangle
{
private:
    GLFWwindow *window;
    void initWindow();
    void initGLFW();
    void initGLEW();
    void setWindowAttributes();
    void mainLoop();
    void cleanup();
    void createInstance();
public:
    Triangle();
    void run(){
        initGLFW();
        initWindow();
        initGLEW();
        setWindowAttributes();
        mainLoop();
    };
    virtual ~Triangle();
};
