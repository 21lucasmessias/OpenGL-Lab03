#ifndef MYPROJECT_H
#define MYPROJECT_H

#include "main.hpp"

#define INDEX_SUN 0
#define INDEX_MERCURY 1
#define INDEX_VENUS 2
#define INDEX_EARTH 3
#define INDEX_MARS 4
#define INDEX_JUPITER 5
#define INDEX_SATURN 6
#define INDEX_URANUS 7
#define INDEX_NEPTUNE 8
#define INDEX_SATURN_RING 9
#define INDEX_STARS 10

void handleRealTimeTransformations();
void processObjects();
void handleSpecificRealTimeTransformations(GLuint index);

#endif