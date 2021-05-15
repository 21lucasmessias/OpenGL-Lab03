#ifndef MAIN_H
#define MAIN_H

#include <Windows.h>
#include <iostream>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/GL.h>
#include "SOIL2/SOIL2.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include <vector>
#include <algorithm>
#include <string>

#include "hotkeys.hpp"
#include "renderResolvers.hpp"
#include "objectsDefinition.hpp"
#include "states.hpp"
#include "textures.hpp"

#endif