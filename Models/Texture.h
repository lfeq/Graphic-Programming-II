#pragma once
#include <GL/eglew.h>
#include "stb_image.h"

class Texture
{
public:
	Texture();
	Texture(char* fileLoc);
	void LoadTexture();
	void UseTexture();
	void ClearTexture();
	~Texture();
private:
	GLuint texture2D, textureID;
	int width, height, bitDepth;
	const char* fileLocation;
};

