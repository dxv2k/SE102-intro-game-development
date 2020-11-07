#include "Transform.h"

Transform::Transform(
	D3DXVECTOR2 position,
	D3DXVECTOR2 scale, 
	float rotationAngle) {

	this->position = position; 
	this->scale = scale; 
	this->rotationAngle = rotationAngle; 
}

Transform::~Transform(){ 
	//Empty on purpose 
}
