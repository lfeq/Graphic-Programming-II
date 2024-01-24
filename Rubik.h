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
	for (int i = 0; i < 3; i++) {
		cubes[i].SetPositions(xPos * i, 0, zPos);
		glPushMatrix();
		//cubes[i].Draw();
		cubes[i].Rotate(45, 1, 0, 0);
		glPopMatrix();
	}
}

//TODO: Crear una funcion que rote los cubos
// El cubo se tiene que manejar por niveles