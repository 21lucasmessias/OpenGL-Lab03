#include "objectsDefinition.hpp"

vector<GLfloat> sphere;
vector<GLushort> sphere_index;

vector<GLfloat> ring;
vector<GLushort> ring_index;

vector<ObjectProperties> objects{
	{sphere, sphere_index},
	{ring, ring_index}
};

vector<ObjectsToRender> objectsToRender;