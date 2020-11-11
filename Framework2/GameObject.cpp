#include "Game.h"
#include "GameObject.h"


GameObject::GameObject() {
	this->tag = ""; 
	this->currentState = ""; 
	transform.Transform(); 


}


GameObject::~GameObject() {

}

void GameObject::Init() {
	// TODO: Add physics and collider box in the future 
	Awake(); 
	Start(); 
	this->enabled = true; 
}


bool GameObject::CompareTag(string otherTag) {
	return (tag == otherTag); 
}

void GameObject::SetState(string newState) {
	this->lastState = currentState; 
	this->currentState = newState; 
}

