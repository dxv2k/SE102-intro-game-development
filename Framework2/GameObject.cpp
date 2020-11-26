//#include "Game.h"
#include "GameObject.h"

// Not sure about this 
// Because I already set Transform with default value in its constructor 
GameObject::GameObject() {
	DebugOut(L"GameObj base constructor"); 
	this->tag = ""; 
	this->name = ""; 
	this->currentState = ""; 
	this->transform.position = D3DXVECTOR2(0.0f, 0.0f); 
	this->transform.rotationAngle = 0.0f; 

	// Reference to MonoBehavior Execution Order
	this->Awake(); 

	this->Start(); 

	this->enabled = true; 
}

GameObject::GameObject(D3DXVECTOR2 position, 
						D3DXVECTOR2 scale,
						float rotation) {
	this->transform.position = position; 
	this->transform.scale = scale; 
	this->transform.rotationAngle = rotation; 

	this->enabled = false; 

	// Reference to MonoBehavior Execution Order
	this->Awake(); 

	this->Start(); 

	this->enabled = true; 
}

GameObject::~GameObject() {
	// TODO: Complete desconstructor of GameObject 
}

void GameObject::Init() {
	this->rigidBody = new RigidBody(); 
	this->colliders = new vector<ColliderBox*>(); 
	this->enabled = true; 
	this->Awake(); 
	this->Start(); 
}

bool GameObject::IsEmptyTag() {
	return (this->tag.length() == 0 ? 1 : 0); 
}

bool GameObject::CompareTag(string otherTag) {
	return (this->tag == otherTag); 
}

void GameObject::SetState(string newState) {
	this->lastState = currentState; 
	this->currentState = newState; 
}


void GameObject::AddAnimation(string name, LPANIMATION animationSet) {

}


void GameObject::LoadAnimation() {

}

