#include "objectsDefinition.hpp"

vector<GLfloat> sphere;
vector<GLushort> sphere_index;

vector<GLfloat> ring;
vector<GLushort> ring_index;

vector<GLfloat> piramid =
{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side

	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side

	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
};

// Indices for vertices order
vector<GLushort> piramid_index =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};

vector<GLfloat> cube{
	-1.0f,	1.0f,	1.0f,	    0.5f, 0.5f, 0.5f,      0.0f, 1.0f,		0.0f,	0.0f,	1.0f,
	1.0f,	1.0f,	1.0f,	    0.5f, 0.5f, 0.5f,	   1.0f, 1.0f,		0.0f,	0.0f,	1.0f,
	1.0f,	-1.0f,	1.0f,	    0.5f, 0.5f, 0.5f,	   1.0f, 0.0f,		0.0f,	0.0f,	1.0f,
	-1.0f,	-1.0f,	1.0f,	    0.5f, 0.5f, 0.5f,	   0.0f, 0.0f,		0.0f,	0.0f,	1.0f,

	-1.0f,	1.0f,	-1.0f,	    0.5f, 0.5f, 0.5f,	   0.0f, 1.0f,		0.0f,	1.0f,	0.0f,
	1.0f,	1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 1.0f,		0.0f,	1.0f,	0.0f,
	1.0f,	1.0f,	1.0f,	    0.5f, 0.5f, 0.5f,      1.0f, 0.0f,		0.0f,	1.0f,	0.0f,
	-1.0f,	1.0f,	1.0f,	    0.5f, 0.5f, 0.5f,	   0.0f, 0.0f,		0.0f,	1.0f,	0.0f,

	1.0f,	1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   0.0f, 1.0f,		0.0f,	0.0f,	-1.0f,
	-1.0f,	1.0f,	-1.0f,	    0.5f, 0.5f, 0.5f,	   1.0f, 1.0f,		0.0f,	0.0f,	-1.0f,
	-1.0f,	-1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 0.0f,		0.0f,	0.0f,	-1.0f,
	1.0f,	-1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   0.0f, 0.0f,		0.0f,	0.0f,	-1.0f,

	-1.0f,	-1.0f,	-1.0f,	    0.5f, 0.5f, 0.5f,	   0.0f, 1.0f,		0.0f,	-1.0f,	0.0f,
	1.0f,	-1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 1.0f,		0.0f,	-1.0f,	0.0f,
	1.0f,	-1.0f,	1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 0.0f,		0.0f,	-1.0f,	0.0f,
	-1.0f,	-1.0f,	1.0f,		0.5f, 0.5f, 0.5f,	   0.0f, 0.0f,		0.0f,	-1.0f,	0.0f,

	-1.0f,	1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   0.0f, 1.0f,		-1.0f,	0.0f,	0.0f,
	-1.0f,	1.0f,	1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 1.0f,		-1.0f,	0.0f,	0.0f,
	-1.0f,	-1.0f,	1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 0.0f,		-1.0f,	0.0f,	0.0f,
	-1.0f,	-1.0f,	-1.0f,	    0.5f, 0.5f, 0.5f,	   0.0f, 0.0f,		-1.0f,	0.0f,	0.0f,

	1.0f,	1.0f,	1.0f,		0.5f, 0.5f, 0.5f,	   0.0f, 1.0f,		1.0f,	0.0f,	0.0f,
	1.0f,	1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 1.0f,		1.0f,	0.0f,	0.0f,
	1.0f,	-1.0f,	-1.0f,		0.5f, 0.5f, 0.5f,	   1.0f, 0.0f,		1.0f,	0.0f,	0.0f,
	1.0f,	-1.0f,	1.0f,	    0.5f, 0.5f, 0.5f,	   0.0f, 0.0f,		1.0f,	0.0f,	0.0f,
};

vector<GLushort> cube_index{
	0, 3, 1,
	1, 3, 2,

	4, 7, 5,
	5, 7, 6,

	8, 11, 9,
	9, 11, 10,

	12, 15, 13,
	13, 15, 14,

	16, 19, 17,
	17, 19, 18,

	20, 23, 21,
	21, 23, 22
};

vector<ObjectProperties> objects{
	{sphere, sphere_index},
	{ring, ring_index},
	{piramid, piramid_index},
	{cube, cube_index}
};

vector<ObjectsToRender> objectsToRender;