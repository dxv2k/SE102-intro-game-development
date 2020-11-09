#include "Game.h"
#include "GameObject.h"


GameObject::GameObject() {
}


GameObject::~GameObject() {

}

void GameObject::Init() {
	// TODO: Add physics and collider box in the future 
	Awake(); 
	Start(); 
	this->enabled = true; 
}


