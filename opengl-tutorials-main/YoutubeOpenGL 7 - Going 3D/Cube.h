#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.66f, // 0
	-0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.66f,	// 1
	 0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.66f,	// 2
	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.33f,	// 3
	-0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.66f,	// 4
	-0.5f, -0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,	// 5
	 0.5f, -0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// 6
	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.33f,	// 7
	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.33f,	// H, 8
	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.66f,	// D, 9
	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.66f,	// C, 10
	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.33f,	// G, 11
	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.66f,	// G, 12
	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 1.0f,	// C, 13
	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 1.0f,	// B, 14
	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.66f,	// F, 15
	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.33f,	// F, 16
	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.66f,	// B, 17
	 -0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.66f,	// A, 18
	 -0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.33f,	// E, 19
	 -0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.0f,	// A, 20
	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.33f,	// B, 21
	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.33f,	// C, 22
	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.0f,	// D, 23
	 -0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.33f,	// E, 24
	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.66f,	// H, 25
	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.66f,	// G, 26
	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.33f,	// F, 27
};

// Indices for vertices order
GLuint indices[] =
{
	// Base
	24, 25, 26,
	26, 27, 24,
	// Top
	20, 21, 22,
	22, 23, 20,
	// lado 1
	16, 17, 18,
	18, 19, 16,
	// lado 2
	12, 13, 14,
	14, 15, 12,
	// Lado 3
	8, 9, 10,
	10, 11, 8,
	// Lado 4
	3, 0, 4,
	4, 7, 3
};

class Cube {
public:
	float posX, posY, posZ, rotX, rotY, rotZ;
	Cube();
	Cube(float t_posX, float t_posY, float t_posZ);
	void Draw(int modelLoc);
	void SetPositions(float t_posX, float t_posY, float t_posZ);
	void Rotate(float t_angle, float t_rotX, float t_rotY, float t_rotZ);
	void RotateX(float t_angle);
	void RotateY(float t_angle);
	void RotateZ(float t_angle);
};

Cube::Cube() {
	posX = 0;
	posY = 0;
	posZ = 0;
	rotX = 0;
	rotY = 0;
	rotZ = 0;
}

Cube::Cube(float t_posX, float t_posY, float t_posZ) {
	posX = t_posX;
	posY = t_posY;
	posZ = t_posZ;
	rotX = 0;
	rotY = 0;
	rotZ = 0;
}

void Cube::Draw(int modelLoc) {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(posX, posY, posZ));
	model = glm::rotate(model, glm::radians(rotX), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotY), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotZ), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
}

void Cube::SetPositions(float t_posX, float t_posY, float t_posZ) {
	posX = t_posX;
	posY = t_posY;
	posZ = t_posZ;
}

void Cube::Rotate(float t_angle, float t_rotX, float t_rotY, float t_rotZ) {
}

void Cube::RotateX(float t_angle) {
	rotX += t_angle;
}

void Cube::RotateY(float t_angle) {
	rotY += t_angle;
}

void Cube::RotateZ(float t_angle) {
	rotZ += t_angle;
};
