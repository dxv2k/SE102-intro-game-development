#pragma once

#include "MonoBehaviour.h"
#include "CollisionBox.h"

using namespace std; 

class Collision2D: protected MonoBehaviour {
public: 
	float t, nx, ny;
	float  dx, dy;

	Collision2D(); 
	~Collision2D(); 

	/*
		TODO: 
		-	Add SweptAABB
		-	Filter Collision 
		-	Calculate  Potential Collision 
	*/
	bool Comparator(const Collision2D &otherCollision) {
		return this->t < otherCollision.t; 
	}
};
typedef Collision2D* LPCOLLISIONEVENT