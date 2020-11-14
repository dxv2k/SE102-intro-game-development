#include "CollisionBox.h"

ColliderBox::ColliderBox() {
	this->sizeBox = D3DXVECTOR2(1.0f, 1.0f); 
	this->gameObj = NULL; 
	this->rigidBody = NULL; 
	//this->center = D3DXVECTOR2(sizeBox.x * 0.5f, sizeBox.y * 0.5f);  
}

ColliderBox::~ColliderBox() {
	// Empty on purpose 
}


