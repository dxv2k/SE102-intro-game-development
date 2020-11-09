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

void Transform::Translate(D3DXVECTOR2 newCoordinate) {
	// Translate method here is replace the current position with the new position  
	position.x = newCoordinate.x; 
	position.y = newCoordinate.y; 
}



