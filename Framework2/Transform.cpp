#include "Transform.h"

Transform::Transform() {

	DebugOut(L"Base Transform Constructor"); 
	this->position = D3DXVECTOR2(0.0f,0.0f); 
	this->localPosition = D3DXVECTOR2(0.0f,0.0f); 
	this->scale = D3DXVECTOR2(1.0f,1.0f); 
	this->rotationAngle = 0.0f; 
}

Transform::Transform(
	D3DXVECTOR2 position,
	D3DXVECTOR2 localPosition,
	D3DXVECTOR2 scale, 
	float rotationAngle) {

	this->position = position; 
	this->localPosition = localPosition; 
	this->scale = scale; 
	this->rotationAngle = rotationAngle; 
}

Transform::~Transform(){ 
	//Empty on purpose 
}

void Transform::Translate(D3DXVECTOR2 newCoordinate) {
	// Translate method here is replace the current position with the new position  
	this->position.x = newCoordinate.x; 
	this->position.y = newCoordinate.y; 
}

