#ifndef PROJECT_H
#define PROJECT_H

#include "main.hpp"

typedef struct States {
	GLfloat pi;
	GLboolean wireframe;
	GLfloat speed;

	vec3 eye;
	vec3 center;
	vec3 up;
} States;

extern States states;

#endif