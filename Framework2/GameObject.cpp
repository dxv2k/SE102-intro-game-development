//#include "Game.h"
#include "GameObject.h"

// Not sure about this 
// Because I already set Transform with default value in its constructor 
GameObject::GameObject() {
	this->tag = ""; 
	this->name = ""; 
	this->currentState = ""; 
	//transform.position = D3DXVECTOR2(0.0f,0.0f); 
	//this->transform.localPosition = D3DXVECTOR2(0.0f,0.0f); 
	//this->transform.rotationAngle = 0.0f; 
	//colliderBox = NULL; // NOTICE: not sure should set collider to NULL 
	rigidBody = NULL; // NOTICE: not sure should set rigidbody to NULL 
}

GameObject::GameObject(D3DXVECTOR2 position, 
						D3DXVECTOR2 scale,
						float rotation) {
	this->transform.position = position; 
	this->transform.scale = scale; 
	this->transform.rotationAngle = rotation; 
	this->enabled = true;  
	this->tag = ""; 
}

GameObject::~GameObject() {
	// Empty on purpose
}

void GameObject::Init() {
	// TODO: Add init RigidBody and ColliderBox in the future 
	this->rigidBody = new RigidBody(); 

	//this->colliderBox = new vector<LPCOLLIDERBOX>(); 

	//colliders = new vector<ColliderBox*>(); 
	// ERROR: can't overload '='
	colliders = new vector<ColliderBox*>(); 

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

