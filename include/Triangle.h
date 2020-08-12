#pragma once

#include "openGLHelper.h"
#include "print.h"
#include "windowHandeling.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <array>
#include <cmath>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
// Define data type here.
#define TypeOfData float

namespace Triangle {

struct Vertices {
private:
  // I am assuming same component number for each generic vertex (color, position).
  uint numberOfGenericAttributes;
  uint totalCountOfVertexComponents;

public:
  uint componentTypeLengthInBytes{sizeof(TypeOfData)};
  std::vector<TypeOfData> data = {
      -0.5, -0.5, 0.0,  // 1
      0.5,  -0.5, 0.0,  // 2
      0.0,  0.5,  0.0}; // 3. within visible region of OpenGL
  std::function<uint()> getDataSizeInBytes = [&]() -> uint {
    return data.size() * sizeof(TypeOfData);
  };
  std::vector<uint> indices;
  std::function<uint()> getIndicesSizeInBytes = [&]() -> uint {
    return indices.size() * sizeof(uint);
  };
// Constructor:
  Vertices(uint numberOfGenericAttributes = 1, uint totalCountOfVertexComponents = 3)
      : numberOfGenericAttributes{numberOfGenericAttributes},
        totalCountOfVertexComponents{totalCountOfVertexComponents} {};
};

class Triangle {
private:
  uint totalCountOfVertexComponents;
  uint numberOfGenericAttributes;
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

  void upLoadVertices();

  void upLoadIndices();

  void setUpShaders();

  void setUpMemoryLayout();

  void mainLoop();

  void cleanup();

  void createInstance();

  void shaderCodeReader(std::string &shaderCode, const std::string &filePath);

public:
  int linkedShaderProgram;
  Vertices *vertices = nullptr;

  // Constructors.
  Triangle(std::string shaderVertexPath, std::string fragmentVertexPath,
           uint numberOfAttributeType = 1,
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
  std::vector<std::function<void()>> runnable;
};

} // namespace Triangle
