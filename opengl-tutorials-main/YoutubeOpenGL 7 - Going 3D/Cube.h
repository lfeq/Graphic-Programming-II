#pragma once
#include<filesystem>
namespace fs = std::filesystem;
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
	-0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f, // 0
	-0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// 1
	 0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// 2
	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,	// 3
	-0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// 4
	-0.5f, -0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,	// 5
	 0.5f, -0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// 6
	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,	// 7
	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// H, 8
	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,	// D, 9
	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,	// C, 10
	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,	// G, 11
	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// G, 12
	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,	// C, 13
	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,	// B, 14
	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,	// F, 15
	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// F, 16
	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,	// B, 17
	 -0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,	// A, 18
	 -0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,	// E, 19
	 -0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// A, 20
	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,	// B, 21
	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,	// C, 22
	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,	// D, 23
	 -0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// E, 24
	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// H, 25
	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// G, 26
	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// F, 27
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
	VAO VAO1;
	GLuint uniID;

	Cube(Shader& shaderProgram) {
		// Generates Vertex Array Object and binds it
		VAO1.Bind();

		// Generates Vertex Buffer Object and links it to vertices
		VBO VBO1(vertices, sizeof(vertices));
		// Generates Element Buffer Object and links it to indices
		EBO EBO1(indices, sizeof(indices));

		// Links VBO attributes such as coordinates and colors to VAO
		VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		// Unbind all to prevent accidentally modifying them
		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();

		// Gets ID of uniform called "scale"
		uniID = glGetUniformLocation(shaderProgram.ID, "scale");

		/*
		* I'm doing this relative path thing in order to centralize all the resources into one folder and not
		* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
		* folder and then give a relative path from this folder to whatever resource you want to get to.
		* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
		*/
		std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
		std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

		// Texture
		Texture brickTex((parentDir + texPath + "pop_cat.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		brickTex.texUnit(shaderProgram, "tex0", 0);
	};

	void draw(Shader& shaderProgram) {
		// Generates Vertex Array Object and binds it
		VAO1.Bind();

		// Generates Vertex Buffer Object and links it to vertices
		VBO VBO1(vertices, sizeof(vertices));
		// Generates Element Buffer Object and links it to indices
		EBO EBO1(indices, sizeof(indices));

		// Links VBO attributes such as coordinates and colors to VAO
		VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		// Unbind all to prevent accidentally modifying them
		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();

		// Gets ID of uniform called "scale"
		uniID = glGetUniformLocation(shaderProgram.ID, "scale");

		/*
		* I'm doing this relative path thing in order to centralize all the resources into one folder and not
		* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
		* folder and then give a relative path from this folder to whatever resource you want to get to.
		* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
		*/
		std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
		std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

		// Texture
		Texture brickTex((parentDir + texPath + "pop_cat.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		brickTex.texUnit(shaderProgram, "tex0", 0);
	}
};
