#pragma once

class Cube
{
	public:
		float posX, posY, posZ;
		Cube();
		Cube(float t_posX, float t_posY, float t_posZ);
};

Cube::Cube() {
	posX = 0;
	posY = 0;
	posZ = 0;
}

Cube::Cube(float t_posX, float t_posY, float t_posZ) {
	posX = t_posX;
	posY = t_posY;
	posZ = t_posZ;
}