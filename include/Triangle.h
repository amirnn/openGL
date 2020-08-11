#pragma once

#include <GL/glew.h>
#include "print.h"
#include "windowHandeling.h"
#include <GLFW/glfw3.h>
#include <array>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
// Define data ttpe here.
#define TypeOfData GLfloat

namespace Triangle {

struct Verticies {
  private:
  uint numberOfAttributesPerVertex;
  public:
  std::vector<TypeOfData> data = {
      -0.5, -0.5, 0.0, 0.5, -0.5,
      0.0,  0.0,  0.5, 0.0}; // within visible region of OpenGL
  unsigned sizeInBytes = data.size() * sizeof(TypeOfData);
  std::vector<GLuint> indices;
  std::function<GLuint()> getIndiciesSizeinBytes = [&]() -> GLuint {
    return indices.size() * sizeof(GLuint);
  };
  Verticies(uint numberOfAttributesPerVertex = 3)
      : numberOfAttributesPerVertex{numberOfAttributesPerVertex} {};
};

class Triangle {
private:
  uint numberOfAttributesPerVertex;
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
  Verticies *verticies = nullptr;
  // Constructors.
  Triangle(std::string shaderVertexPath, std::string fragmentVertexPath,
           uint numberOfAttributesPerVertex = 3);
  virtual ~Triangle();

  void run() {
    initGLFW();
    initWindow();
    initGLEW();
    setWindowAttributes();
    configureObject();
    setUpShaders();
    mainLoop();
  };
  // Using this I can inject functionality into the main loop.
  std::vector<std::function<void()>> runable;
};

} // namespace Triangle
