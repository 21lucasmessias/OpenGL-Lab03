#ifndef PROJECT_H
#define PROJECT_H

#include "main.hpp"

typedef struct States {
	GLboolean wireframe;
	GLfloat speed;

	glm::vec3 eye;
	glm::vec3 center;
	glm::vec3 up;

	GLfloat cameraX;
	GLfloat	cameraY;
	GLfloat cameraZ;

	GLfloat cubeLocX;
	GLfloat cubeLocY;
	GLfloat cubeLocZ;
} States;

extern States states;

#endif