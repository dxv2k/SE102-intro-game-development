#include "CollisionBox.h" 

// Default constructor
ColliderBox::ColliderBox() {
	this->sizeBox = D3DXVECTOR2(1.0f, 1.0f); 
	this->gameObj = NULL; 
	this->rigidBody = NULL; 
}

ColliderBox::ColliderBox(D3DXVECTOR2 sb,
	LPGAMEOBJECT &obj,
	LPRIGIDBODY &rb) {
	this->sizeBox = sb; 
	this->gameObj = obj; 
	this->rigidBody = rb; 
}

ColliderBox::~ColliderBox() {
	// Empty on purpose 
}



