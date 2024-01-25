#pragma once
#include "Cube.h"
#include <iostream>

class Rubik {
public:
	Cube row1[3][3];
	Cube row2[3][3];
	Cube row3[3][3];
	Cube column1[3][3];
	Cube column2[3][3];
	Cube column3[3][3];
	Rubik();
	void RotateRow1();
	void RotateRow2();
	void RotateRow3();
	void RotateColumn1();
	void RotateColumn2();
	void RotateColumn3();
};

Rubik::Rubik() {
	// Row 1
	Cube one_one(0, 0, -15);
	Cube one_two(3, 0, -15);
	Cube one_three(6, 0, -15);
	Cube two_one(0, 0, -18);
	Cube two_two(3, 0, -18);
	Cube two_three(6, 0, -18);
	Cube three_one(0, 0, -21);
	Cube three_two(3, 0, -21);
	Cube three_three(6, 0, -21);
	row1[0][0] = one_one;
	row1[0][1] = one_two;
	row1[0][2] = one_three;
	row1[1][0] = two_one;
	row1[1][1] = two_two;
	row1[1][2] = two_three;
	row1[2][0] = three_one;
	row1[2][1] = three_two;
	row1[2][2] = three_three;

	// Row 2
	Cube four_one(0, 3, -15);
	Cube four_two(3, 3, -15);
	Cube four_three(6, 3, -15);
	Cube five_one(0, 3, -18);
	Cube five_two(3, 3, -18);
	Cube five_three(6, 3, -18);
	Cube six_one(0, 3, -21);
	Cube six_two(3, 3, -21);
	Cube six_three(6, 3, -21);
	row2[0][0] = four_one;
	row2[0][1] = four_two;
	row2[0][2] = four_three;
	row2[1][0] = five_one;
	row2[1][1] = five_two;
	row2[1][2] = five_three;
	row2[2][0] = six_one;
	row2[2][1] = six_two;
	row2[2][2] = six_three;

	// Row 3
	Cube seven_one(0, 6, -15);
	Cube seven_two(3, 6, -15);
	Cube seven_three(6, 6, -15);
	Cube eight_one(0, 6, -18);
	Cube eight_two(3, 6, -18);
	Cube eight_three(6, 6, -18);
	Cube nine_one(0, 6, -21);
	Cube nine_two(3, 6, -21);
	Cube nine_three(6, 6, -21);
	row3[0][0] = seven_one;
	row3[0][1] = seven_two;
	row3[0][2] = seven_three;
	row3[1][0] = eight_one;
	row3[1][1] = eight_two;
	row3[1][2] = eight_three;
	row3[2][0] = nine_one;
	row3[2][1] = nine_two;
	row3[2][2] = nine_three;

	// Column 1
	column1[0][0] = one_one;
	column1[0][1] = two_one;
	column1[0][2] = three_one;
	column1[1][0] = four_one;
	column1[1][1] = five_one;
	column1[1][2] = six_one;
	column1[2][0] = seven_one;
	column1[2][1] = eight_one;
	column1[2][2] = nine_one;

	// Column 2
	column2[0][0] = one_two;
	column2[0][1] = two_two;
	column2[0][2] = three_two;
	column2[1][0] = four_two;
	column2[1][1] = five_two;
	column2[1][2] = six_two;
	column2[2][0] = seven_two;
	column2[2][1] = eight_two;
	column2[2][2] = nine_two;

	// Column 3
	column3[0][0] = one_three;
	column3[0][1] = two_three;
	column3[0][2] = three_three;
	column3[1][0] = four_three;
	column3[1][1] = five_three;
	column3[1][2] = six_three;
	column3[2][0] = seven_three;
	column3[2][1] = eight_three;
	column3[2][2] = nine_three;
}

void Rubik::RotateRow1() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			glPushMatrix();
			//row1[x][y].Draw();
			row1[x][y].Rotate(45, 1, 0, 0);
			glPopMatrix();
		}
	}
}

void Rubik::RotateRow2() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			glPushMatrix();
			//row1[x][y].Draw();
			row2[x][y].Rotate(45, 1, 0, 0);
			glPopMatrix();
		}
	}
}

void Rubik::RotateRow3() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			glPushMatrix();
			//row1[x][y].Draw();
			row3[x][y].Rotate(45, 1, 0, 0);
			glPopMatrix();
		}
	}
}

void Rubik::RotateColumn1() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			glPushMatrix();
			//row1[x][y].Draw();
			column1[x][y].Rotate(45, 1, 0, 0);
			glPopMatrix();
		}
	}
}

void Rubik::RotateColumn2() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			glPushMatrix();
			//row1[x][y].Draw();
			column2[x][y].Rotate(45, 1, 0, 0);
			glPopMatrix();
		}
	}
}

void Rubik::RotateColumn3() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			glPushMatrix();
			//row1[x][y].Draw();
			column3[x][y].Rotate(45, 1, 0, 0);
			glPopMatrix();
		}
	}
}

//TODO: Crear una funcion que rote los cubos
// El cubo se tiene que manejar por niveles