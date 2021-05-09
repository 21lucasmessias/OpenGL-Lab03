#ifndef PROJECT_H
#define PROJECT_H

#include "main.hpp"

typedef struct States {
	GLfloat pi;
	GLboolean wireframe;
	GLfloat speed;

	glm::vec3 eye;
	glm::vec3 center;
	glm::vec3 up;

	glm::vec3 cameraPosition;
	GLfloat cameraRotationX;
	GLfloat cameraRotationY;
} States;

extern States states;

#endif