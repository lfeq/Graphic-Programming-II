#pragma once
#include "Cube.h"
#include <iostream>

class Rubik {
public:
	Cube cubes[3];
	Rubik();
};

Rubik::Rubik() {
	int xPos = 3;
	int yPos = 3;
	int zPos = -17;
	for (int i = 0; i < sizeof(cubes) / sizeof(*cubes); i++) {
		cubes[i].SetPositions(xPos * i, 0, zPos);
		glPushMatrix();
		cubes[i].Draw();
		glPopMatrix();
	}
}

//TODO: Crear una funcion que rote los cubos