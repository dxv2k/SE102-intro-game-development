//#include "Game.h"
#include "GameObject.h"

// Not sure about this 
// Because I already set Transform with default value in its constructor 
GameObject::GameObject() {
	DebugOut(L"Game Object base constructor"); 
	this->tag = ""; 
	this->name = ""; 
	this->currentState = ""; 
	
	// NOTICE: No need below because Transform class already done that
	//this->transform.position = D3DXVECTOR2(0.0f, 0.0f); 
	//this->transform.rotationAngle = 0.0f; 
	//this->transform.scale = D3DXVECTOR2(0.0f, 0.0f); 

	// Reference to MonoBehavior Execution Order
	this->Awake(); 

	this->Start(); 

	this->enabled = true; 
}

GameObject::GameObject(D3DXVECTOR2 position, 
						D3DXVECTOR2 scale,
						float rotation) {
	DebugOut(L"Game Object with transform parameters constructor"); 
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
	// Delete rigidbody and colliders 
	// Override OnDestroy if necessary
	if (rigidBody != NULL)
		delete rigidBody; 
	for (LPCOLLIDERBOX c : *colliders) {
		delete c; 
	}
	delete colliders; 
	OnDestroy(); 
}

void GameObject::Init() {
	this->rigidBody = new RigidBody(); 
	this->colliders = new vector<ColliderBox*>(); 

	// Reference to MonoBehavior Execution Order
	this->Awake(); 

	this->Start(); 

	this->enabled = true; 
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

