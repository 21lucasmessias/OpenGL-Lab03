#ifndef TEXTURES_H
#define TEXTURES_H

#include "main.hpp"

#define EMPTY_INDEX 0
#define INDEX_TEXTURE_SUN 1
#define INDEX_TEXTURE_MERCURY 2
#define INDEX_TEXTURE_VENUS 3
#define INDEX_TEXTURE_EARTH 4
#define INDEX_TEXTURE_MARS 5
#define INDEX_TEXTURE_JUPITER 6
#define INDEX_TEXTURE_SATURN 7
#define INDEX_TEXTURE_URANUS 8
#define INDEX_TEXTURE_NEPTUNE 9
#define INDEX_TEXTURE_SATURN_RING 10
#define INDEX_TEXTURE_STARS 11

using namespace std;
using namespace glm;

struct Texture {
	GLint TEXTURE_WIDTH;
	GLint TEXTURE_HEIGHT;
	unsigned char* TEXTURE;
};

void loadTextures();
void freeTextures();
void applyTexture(unsigned char* TEXTURE, GLint TEXTURE_WIDTH, GLint TEXTURE_HEIGHT);

extern vector<Texture> textures;

#endif