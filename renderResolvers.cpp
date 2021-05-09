#include "renderResolvers.hpp"
#include <iomanip>

using namespace std;

//1 = 100000km

const GLfloat borderSun = 13.927f * 5.0f;

const GLfloat SHORTER_DISTANCE = 100.0f;
const GLfloat MORE_SPEED_ROTATION = 10000.0f;
const GLfloat MORE_SPEED_TRANSLATION = 10000.0f;

const GLfloat distanceMercury = 579.1f / SHORTER_DISTANCE;
const GLfloat distanceVenus = 1082.0f / SHORTER_DISTANCE;
const GLfloat distanceEarth = 1496.0f / SHORTER_DISTANCE;
const GLfloat distanceMars = 2279.4f / SHORTER_DISTANCE;
const GLfloat distanceJupiter = 7783.3f / SHORTER_DISTANCE;
const GLfloat distanceSaturn = 14294.0f / SHORTER_DISTANCE;
const GLfloat distanceUranus = 28709.9f / SHORTER_DISTANCE;
const GLfloat distanceNeptune = 45043.0f / SHORTER_DISTANCE;

const GLfloat rotationSun = 27 * 24 * 3600;
const GLfloat rotationMercury = 59 * 24 * 3600;
const GLfloat rotationVenus = 243 * 24 * 3600;
const GLfloat rotationEarth = 24 * 3600;
const GLfloat rotationMars = (24 * 60 + 37) * 60;
const GLfloat rotationJupiter = (9 * 60 + 55) * 60;
const GLfloat rotationSaturn = (10 * 60 + 14) * 60;
const GLfloat rotationUranus = 17 * 3600;
const GLfloat rotationNeptune = 16 * 3600;

const GLfloat translationMercury = (long long int)87 * 24 * 3600 / MORE_SPEED_TRANSLATION;
const GLfloat translationVenus = (long long int)225 * 24 * 3600 / MORE_SPEED_TRANSLATION;
const GLfloat translationEarth = (long long int)365 * 24 * 3600 / MORE_SPEED_TRANSLATION;
const GLfloat translationMars = (long long int)687 * 24 * 3600 / MORE_SPEED_TRANSLATION;
const GLfloat translationJupiter = (long long int)12 * 365 * 24 * 3600 / MORE_SPEED_TRANSLATION;
const GLfloat translationSaturn = (long long int)30 * 365 * 24 * 3600 / MORE_SPEED_TRANSLATION;
const GLfloat translationUranus = (long long int)165 * 365 * 24 * 3600 / MORE_SPEED_TRANSLATION;
const GLfloat translationNeptune = (long long int)164 * 365 * 24 * 3600 / MORE_SPEED_TRANSLATION;

void handleRealTimeTransformations() {
	const GLfloat time = (GLfloat)glfwGetTime() * 10;

	//Rotation
	objectsToRender[INDEX_SUN].rotation.radians = time * MORE_SPEED_ROTATION / rotationSun;
	objectsToRender[INDEX_MERCURY].rotation.radians = -time * MORE_SPEED_ROTATION / rotationMercury;
	objectsToRender[INDEX_VENUS].rotation.radians = -time * MORE_SPEED_ROTATION / rotationVenus;
	objectsToRender[INDEX_EARTH].rotation.radians = -time * MORE_SPEED_ROTATION / rotationEarth;
	objectsToRender[INDEX_MARS].rotation.radians = -time * MORE_SPEED_ROTATION / rotationMars;
	objectsToRender[INDEX_JUPITER].rotation.radians = -time * MORE_SPEED_ROTATION / rotationJupiter;
	objectsToRender[INDEX_SATURN].rotation.radians = -time * MORE_SPEED_ROTATION / rotationSaturn;
	objectsToRender[INDEX_SATURN_RING].rotation.radians = -time * MORE_SPEED_ROTATION / rotationSaturn;
	objectsToRender[INDEX_URANUS].rotation.radians = -time * MORE_SPEED_ROTATION / rotationUranus;
	objectsToRender[INDEX_NEPTUNE].rotation.radians = -time * MORE_SPEED_ROTATION / rotationNeptune;

	//Translation
	objectsToRender[INDEX_MERCURY].translation[0] = -((GLfloat)cos(time / translationMercury)) * (borderSun + distanceMercury);
	objectsToRender[INDEX_MERCURY].translation[2] =  ((GLfloat)sin(time / translationMercury)) * (borderSun + distanceMercury);

	objectsToRender[INDEX_VENUS].translation[0] = -((GLfloat)cos(time / translationVenus)) * (borderSun + distanceVenus);
	objectsToRender[INDEX_VENUS].translation[2] = ((GLfloat)sin(time / translationVenus)) * (borderSun + distanceVenus);

	objectsToRender[INDEX_EARTH].translation[0] = -((GLfloat)cos(time / translationEarth)) * (borderSun + distanceEarth);
	objectsToRender[INDEX_EARTH].translation[2] = ((GLfloat)sin(time / translationEarth)) * (borderSun + distanceEarth);

	objectsToRender[INDEX_MARS].translation[0] = -((GLfloat)cos(time / translationMars)) * (borderSun + distanceMars);
	objectsToRender[INDEX_MARS].translation[2] = ((GLfloat)sin(time / translationMars)) * (borderSun + distanceMars);

	objectsToRender[INDEX_JUPITER].translation[0] = -((GLfloat)cos(time / translationJupiter)) * (borderSun + distanceJupiter);
	objectsToRender[INDEX_JUPITER].translation[2] = ((GLfloat)sin(time / translationJupiter)) * (borderSun + distanceJupiter);

	objectsToRender[INDEX_SATURN].translation[0] = -((GLfloat)cos(time / translationSaturn)) * (borderSun + distanceSaturn);
	objectsToRender[INDEX_SATURN].translation[2] = ((GLfloat)sin(time / translationSaturn)) * (borderSun + distanceSaturn);
	objectsToRender[INDEX_SATURN_RING].translation[0] = -((GLfloat)cos(time / translationSaturn)) * (borderSun + distanceSaturn);
	objectsToRender[INDEX_SATURN_RING].translation[2] = ((GLfloat)sin(time / translationSaturn)) * (borderSun + distanceSaturn);

	objectsToRender[INDEX_URANUS].translation[0] = -((GLfloat)cos(time / translationUranus)) * (borderSun + distanceUranus);
	objectsToRender[INDEX_URANUS].translation[2] = ((GLfloat)sin(time / translationUranus)) * (borderSun + distanceUranus);

	objectsToRender[INDEX_NEPTUNE].translation[0] = -((GLfloat)cos(time / translationNeptune)) * (borderSun + distanceNeptune);
	objectsToRender[INDEX_NEPTUNE].translation[2] = ((GLfloat)sin(time / translationNeptune)) * (borderSun + distanceNeptune);

	//Lightning
}

void bufferSphere() {
	GLint PRECISION_CIRCLE = 60, i, j;
	GLfloat raio = 5.0f;
	GLfloat x, y, z;
	GLfloat pi = 3.14159265359f;
	GLfloat r = 1.0f, g = 1.0f, b = 1.0f;

	//vertices
	for (j = PRECISION_CIRCLE/-2; j <= PRECISION_CIRCLE/2; j++) {
		GLfloat radian = j * 180/PRECISION_CIRCLE * pi / 180;

		if (j == (PRECISION_CIRCLE / -2) || j == (PRECISION_CIRCLE / 2)) {

			x = 0.0f;
			y = (GLfloat)sin(radian) * raio;
			z = 0.0f;

			objects[INDEX_SPHERE].object.push_back(x);
			objects[INDEX_SPHERE].object.push_back(y);
			objects[INDEX_SPHERE].object.push_back(z);

			objects[INDEX_SPHERE].object.push_back(r);
			objects[INDEX_SPHERE].object.push_back(g);
			objects[INDEX_SPHERE].object.push_back(b);

			objects[INDEX_SPHERE].object.push_back(0.0f);
			objects[INDEX_SPHERE].object.push_back(sin(radian));
		}
		else {
			for (i = 0; i <= 360; i += 180 / PRECISION_CIRCLE) {
				x = (GLfloat)cos(i * pi / 180) * raio * cos(radian);
				y = (GLfloat)sin(radian) * raio;
				z = (GLfloat)sin(i * pi / 180) * raio * cos(radian);
																
				objects[INDEX_SPHERE].object.push_back(x);
				objects[INDEX_SPHERE].object.push_back(y);
				objects[INDEX_SPHERE].object.push_back(z);

				objects[INDEX_SPHERE].object.push_back(r);
				objects[INDEX_SPHERE].object.push_back(g);
				objects[INDEX_SPHERE].object.push_back(b);

				objects[INDEX_SPHERE].object.push_back(-i / 360.0f);
				objects[INDEX_SPHERE].object.push_back((sin(radian) + 1) / 2);
			}
		}
	}


	//index
	//top
	for (i = 1; i <= PRECISION_CIRCLE * 2; i++) {
		objects[INDEX_SPHERE].indexs.push_back(0);
		objects[INDEX_SPHERE].indexs.push_back(i);
		objects[INDEX_SPHERE].indexs.push_back(i + 1);
	}


	//middle
	for (i = 1; i < (GLushort)objects[INDEX_SPHERE].object.size()/8 - 2 - PRECISION_CIRCLE*2; i++) {
		objects[INDEX_SPHERE].indexs.push_back(i);
		objects[INDEX_SPHERE].indexs.push_back(i + PRECISION_CIRCLE*2 + 1);
		objects[INDEX_SPHERE].indexs.push_back(i + PRECISION_CIRCLE*2 + 2);

		objects[INDEX_SPHERE].indexs.push_back(i + PRECISION_CIRCLE*2 + 2);
		objects[INDEX_SPHERE].indexs.push_back(i);
		objects[INDEX_SPHERE].indexs.push_back(i + 1);
	}

	//bottom
	for (i = (GLushort)objects[INDEX_SPHERE].object.size()/8 - 2; i >= (GLushort)objects[INDEX_SPHERE].object.size()/8 - 1 - PRECISION_CIRCLE * 2; i--) {
		objects[INDEX_SPHERE].indexs.push_back((GLushort)objects[INDEX_SPHERE].object.size()/8 - 1);
		objects[INDEX_SPHERE].indexs.push_back(i);
		objects[INDEX_SPHERE].indexs.push_back(i - 1);
	}
}

void bufferArc() {
	GLint PRECISION_RING = 60, i, j;
	GLfloat raio = 5.5f;
	GLfloat x, y, z;
	GLfloat pi = 3.14159265359f;
	GLfloat r = 1.0f, g = 1.0f, b = 1.0f;

	//vertices
	for (j = 0; j < 4; j++) {
		if (j == 0) {
			z = 0.05f;
		}
		else if (j == 1) {
			raio += 2.0f;
		}
		else if (j == 2) {
			z = -z;
		}
		else {
			raio -= 2.0f;
		}

		for (i = 0; i < 360; i += 360 / PRECISION_RING) {
			x = (GLfloat)cos(i * pi / 180) * raio;
			y = (GLfloat)sin(i * pi / 180) * raio;

			objects[INDEX_RING].object.push_back(x);
			objects[INDEX_RING].object.push_back(y);
			objects[INDEX_RING].object.push_back(z);

			objects[INDEX_RING].object.push_back(r);
			objects[INDEX_RING].object.push_back(g);
			objects[INDEX_RING].object.push_back(b);

			objects[INDEX_RING].object.push_back(-i / 360.0f);
			objects[INDEX_RING].object.push_back((sin(i * pi / 180) + 1) / 2);
		}
	}

	//index
	for (i = 0; i < (GLushort)objects[INDEX_RING].object.size()/8 - PRECISION_RING; i++) {
		if ((i+1) % PRECISION_RING == 0) {
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(i + PRECISION_RING);
			objects[INDEX_RING].indexs.push_back(i + 1);

			objects[INDEX_RING].indexs.push_back(i + 1);
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(i + 1 - PRECISION_RING);
		}
		else {
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(i + PRECISION_RING);
			objects[INDEX_RING].indexs.push_back(i + PRECISION_RING + 1);

			objects[INDEX_RING].indexs.push_back(i + PRECISION_RING + 1);
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(i + 1);
		}
	}

	for (i = 0; i < PRECISION_RING; i++) {
		if ((i + 1) % PRECISION_RING == 0) {
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(PRECISION_RING * 3 + i);
			objects[INDEX_RING].indexs.push_back(PRECISION_RING * 3);

			objects[INDEX_RING].indexs.push_back(PRECISION_RING * 3);
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(i + 1 - PRECISION_RING);
		}
		else {
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(i + PRECISION_RING * 3);
			objects[INDEX_RING].indexs.push_back(i + PRECISION_RING * 3 + 1);

			objects[INDEX_RING].indexs.push_back(i + PRECISION_RING * 3 + 1);
			objects[INDEX_RING].indexs.push_back(i);
			objects[INDEX_RING].indexs.push_back(i + 1);
		}
	}
}

void processObjects() {
	bufferSphere();
	bufferArc();

	ObjectsToRender sun;
	sun.index = INDEX_SPHERE;
	sun.translation = vec3(0.0f, 0.0f, 0.0f);
	sun.scaling = vec3(13.927f, 13.927f, 13.927f);
	sun.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	sun.index_texture = INDEX_TEXTURE_SUN;

	ObjectsToRender mercury;
	mercury.index = INDEX_SPHERE;
	mercury.translation = vec3(0.0f, 0.0f, 0.0f);
	mercury.scaling = vec3(0.048794f, 0.048794f, 0.048794f);
	mercury.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	mercury.index_texture = INDEX_TEXTURE_MERCURY;

	ObjectsToRender venus;
	venus.index = INDEX_SPHERE;
	venus.translation = vec3(0.0f, 0.0f, 0.0f);
	venus.scaling = vec3(0.12104f, 0.12104f, 0.12104f);
	venus.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	venus.index_texture = INDEX_TEXTURE_VENUS;

	ObjectsToRender earth;
	earth.index = INDEX_SPHERE;
	earth.translation = vec3(0.0f, 0.0f, 0.0f);
	earth.scaling = vec3(0.12742f, 0.12742f, 0.12742f);
	earth.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	earth.index_texture = INDEX_TEXTURE_EARTH;

	ObjectsToRender mars;
	mars.index = INDEX_SPHERE;
	mars.translation = vec3(0.0f, 0.0f, 0.0f);
	mars.scaling = vec3(0.06779f, 0.06779f, 0.06779f);
	mars.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	mars.index_texture = INDEX_TEXTURE_MARS;

	ObjectsToRender jupiter;
	jupiter.index = INDEX_SPHERE;
	jupiter.translation = vec3(0.0f, 0.0f, 0.0f);
	jupiter.scaling = vec3(1.3982f, 1.3982f, 1.3982f);
	jupiter.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	jupiter.index_texture = INDEX_TEXTURE_JUPITER;

	ObjectsToRender saturn;
	saturn.index = INDEX_SPHERE;
	saturn.translation = vec3(0.0f, 0.0f, 0.0f);
	saturn.scaling = vec3(1.1646f, 1.1646f, 1.1646f);
	saturn.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	saturn.index_texture = INDEX_TEXTURE_SATURN;

	ObjectsToRender saturn_ring;
	saturn_ring.index = INDEX_RING;
	saturn_ring.translation = vec3(0.0f, 0.0f, 0.0f);
	saturn_ring.scaling = vec3(1.2f, 1.2f, 1.2f);
	saturn_ring.rotation = { vec3(0.0f, 0.0f, 1.0f), 0.0f };
	saturn_ring.index_texture = INDEX_TEXTURE_SATURN_RING;

	ObjectsToRender uranus;
	uranus.index = INDEX_SPHERE;
	uranus.translation = vec3(0.0f, 0.0f, 0.0f);
	uranus.scaling = vec3(0.50724f, 0.50724f, 0.50724f);
	uranus.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	uranus.index_texture = INDEX_TEXTURE_URANUS;

	ObjectsToRender neptune;
	neptune.index = INDEX_SPHERE;
	neptune.translation = vec3(0.0f, 0.0f, 0.0f);
	neptune.scaling = vec3(0.49244f, 0.49244f, 0.49244f);
	neptune.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	neptune.index_texture = INDEX_TEXTURE_NEPTUNE;

	ObjectsToRender stars;
	stars.index = INDEX_SPHERE;
	stars.translation = vec3(0.0f, 0.0f, 0.0f);
	stars.scaling = vec3(300.0f, 300.0f, 300.0f);
	stars.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	stars.index_texture = INDEX_TEXTURE_STARS;

	objectsToRender.push_back(sun);
	objectsToRender.push_back(mercury);
	objectsToRender.push_back(venus);
	objectsToRender.push_back(earth);
	objectsToRender.push_back(mars);
	objectsToRender.push_back(jupiter);
	objectsToRender.push_back(saturn);
	objectsToRender.push_back(uranus);
	objectsToRender.push_back(neptune);
	objectsToRender.push_back(saturn_ring);
	objectsToRender.push_back(stars);
}

