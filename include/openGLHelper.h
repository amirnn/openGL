//
// Created by amir on 12.08.20.
//
#pragma once
#include <GL/glew.h>
#include <iostream>
#include <cassert>

#define GLCallHelper(x)                                                        \
  OGLHelper::clearErrors();                                                    \
  x;                                                                           \
  assert(OGLHelper::getError())

namespace OGLHelper {
void clearErrors();
bool getError();
} // namespace OGLHelper