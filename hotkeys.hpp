#ifndef HOTKEYS_H
#define HOTKEYS_H

#include "main.hpp"

using namespace std;
using namespace glm;

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

#endif