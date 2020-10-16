#include "GameObject.h"
#include "Game.h" 


vector <LPANIMATION> GameObject::animations;

GameObject::GameObject() {
	x = y = 0; 
	vx = vy = 0; 
	nx = 1; // default object facing to the right  
}

GameObject::~GameObject() {
	// leave empty on purpose 
}


void GameObject::Update(DWORD dt) {
	x += vx * dt; 
	y += vy * dt; 
}

void GameObject::Render() {
	// leave empty on purpose 
}

void GameObject::AddAnimation(int aniID) {
	LPANIMATION ani = Animations::GetInstance()->Get(aniID); 
	animations.push_back(ani); 
}




