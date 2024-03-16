//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

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
#include"Cube.h"

const unsigned int width = 800;
const unsigned int height = 800;

//// Vertices coordinates
//GLfloat vertices[] =
//{ //     COORDINATES     /        COLORS      /   TexCoord  //
//	-0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.66f, // 0
//	-0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.66f,	// 1
//	 0.5f, 0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.66f,	// 2
//	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.33f,	// 3
//	-0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.66f,	// 4
//	-0.5f, -0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,	// 5
//	 0.5f, -0.5f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,	// 6
//	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.33f,	// 7
//	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.33f,	// H, 8
//	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.66f,	// D, 9
//	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.66f,	// C, 10
//	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.75f, 0.33f,	// G, 11
//	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.66f,	// G, 12
//	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 1.0f,	// C, 13
//	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 1.0f,	// B, 14
//	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.66f,	// F, 15
//	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.33f,	// F, 16
//	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.66f,	// B, 17
//	 -0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.66f,	// A, 18
//	 -0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.33f,	// E, 19
//	 -0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.0f,	// A, 20
//	 -0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.33f,	// B, 21
//	 0.5f, 0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.33f,	// C, 22
//	 0.5f, 0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.50f, 0.0f,	// D, 23
//	 -0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.33f,	// E, 24
//	 0.5f, -0.5f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.66f,	// H, 25
//	 0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.66f,	// G, 26
//	 -0.5f, -0.5f,  -0.5f,     0.83f, 0.70f, 0.44f,	0.25f, 0.33f,	// F, 27
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	// Base
//	24, 25, 26,
//	26, 27, 24,
//	// Top
//	20, 21, 22,
//	22, 23, 20,
//	// lado 1
//	16, 17, 18,
//	18, 19, 16,
//	// lado 2
//	12, 13, 14,
//	14, 15, 12,
//	// Lado 3
//	8, 9, 10,
//	10, 11, 8,
//	// Lado 4
//	3, 0, 4,
//	4, 7, 3
//};

bool isKeyPressed = true;
float row1Rotation = 0;

Cube* row1[3][3];
Cube* row2[3][3];
Cube* row3[3][3];
Cube* column1[3][3];
Cube* column2[3][3];
Cube* column3[3][3];

void keyboard_func(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch (key) {
	case GLFW_KEY_Z:
		if (action == GLFW_PRESS && !isKeyPressed) {
			// Codigo aqui
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					row1[x][y]->RotateY(90.0f);
				}
			}
			isKeyPressed = true;
		} else if (action == GLFW_RELEASE) {
			isKeyPressed = false;
		}
		break;
	case GLFW_KEY_A:
		if (action == GLFW_PRESS && !isKeyPressed) {
			// Codigo aqui
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					row2[x][y]->RotateY(90.0f);
				}
			}
			isKeyPressed = true;
		} else if (action == GLFW_RELEASE) {
			isKeyPressed = false;
		}
		break;
	case GLFW_KEY_Q:
		if (action == GLFW_PRESS && !isKeyPressed) {
			// Codigo aqui
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					row3[x][y]->RotateY(90.0f);
				}
			}
			isKeyPressed = true;
		} else if (action == GLFW_RELEASE) {
			isKeyPressed = false;
		}
		break;
	case GLFW_KEY_E:
		if (action == GLFW_PRESS && !isKeyPressed) {
			// Codigo aqui
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					column1[x][y]->RotateY(90.0f);
				}
			}
			isKeyPressed = true;
		} else if (action == GLFW_RELEASE) {
			isKeyPressed = false;
		}
		break;
	case GLFW_KEY_R:
		if (action == GLFW_PRESS && !isKeyPressed) {
			// Codigo aqui
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					column2[x][y]->RotateY(90.0f);
				}
			}
			isKeyPressed = true;
		} else if (action == GLFW_RELEASE) {
			isKeyPressed = false;
		}
		break;
	case GLFW_KEY_T:
		if (action == GLFW_PRESS && !isKeyPressed) {
			// Codigo aqui
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					column3[x][y]->RotateY(90.0f);
				}
			}
			isKeyPressed = true;
		} else if (action == GLFW_RELEASE) {
			isKeyPressed = false;
		}
		break;
	}
}

int main() {
	Cube* one_one = new Cube(0, 0, -15);
	Cube* one_two = new Cube(3, 0, -15);
	Cube* one_three = new Cube(6, 0, -15);
	Cube* two_one = new Cube(0, 0, -18);
	Cube* two_two = new Cube(3, 0, -18);
	Cube* two_three = new Cube(6, 0, -18);
	Cube* three_one = new Cube(0, 0, -21);
	Cube* three_two = new Cube(3, 0, -21);
	Cube* three_three = new Cube(6, 0, -21);
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
	Cube* four_one = new Cube(0, 3, -15);
	Cube* four_two = new Cube(3, 3, -15);
	Cube* four_three = new Cube(6, 3, -15);
	Cube* five_one = new Cube(0, 3, -18);
	Cube* five_two = new Cube(3, 3, -18);
	Cube* five_three = new Cube(6, 3, -18);
	Cube* six_one = new Cube(0, 3, -21);
	Cube* six_two = new Cube(3, 3, -21);
	Cube* six_three = new Cube(6, 3, -21);
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
	Cube* seven_one = new Cube(0, 6, -15);
	Cube* seven_two = new Cube(3, 6, -15);
	Cube* seven_three = new Cube(6, 6, -15);
	Cube* eight_one = new Cube(0, 6, -18);
	Cube* eight_two = new Cube(3, 6, -18);
	Cube* eight_three = new Cube(6, 6, -18);
	Cube* nine_one = new Cube(0, 6, -21);
	Cube* nine_two = new Cube(3, 6, -21);
	Cube* nine_three = new Cube(6, 6, -21);
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
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	// Generates Vertex Array Object and binds it
	VAO VAO1;
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
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "dice_unwrap.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/

	// Variables that help the rotation of the pyramid
	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	glfwSetKeyCallback(window, keyboard_func);

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60) {
			rotation += 0.5f;
			prevTime = crntTime;
		}

		// Initializes matrices so they are not the null matrix
		//glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		// Assigns different transformations to each matrix
		//model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -10.0f));
		proj = glm::perspective(glm::radians(65.0f), (float)width / height, 0.1f, 100.0f);

		// Outputs the matrices into the Vertex Shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		/*int iterator = 0;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				for (int k = -1; k <= 1; k++) {
					models[iterator] = glm::rotate(models[iterator], glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
					models[iterator] = glm::translate(models[iterator], glm::vec3(i, j, k));
					glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(models[iterator]));
					glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
					iterator++;
				}
			}
		}*/

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				row1[x][y]->Draw(modelLoc);
			}
		}
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				row2[x][y]->Draw(modelLoc);
			}
		}
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				row3[x][y]->Draw(modelLoc);
			}
		}

		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// Binds texture so that is appears in rendering
		brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		//glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}