#pragma once

#include "MonoBehaviour.h"
#include "CollisionBox.h"

class ColliderBox; 
typedef ColliderBox* LPCOLLIDERBOX;

//Testing purpose 
struct CollisionEvent
{
	LPCOLLIDERBOX objCollider;
	float t, nx, ny;
	float dx, dy;		// *RELATIVE* movement distance between this object and obj

	CollisionEvent(float t, 
		float nx, 
		float ny, 
		float dx = 0, 
		float dy = 0, 
		LPCOLLIDERBOX obj = NULL)
	{
		this->t = t;
		this->nx = nx;
		this->ny = ny;
		this->dx = dx;
		this->dy = dy;
		this->objCollider = obj;
	}
	
	bool compare(const LPCOLLISIONEVENT& thisEvent, 
						LPCOLLISIONEVENT& otherEvent) {
		return (thisEvent->t < otherEvent->t) ? 1 : 0;
	}
	/*static bool compare(const LPCOLLISIONEVENT& thisEvent, 
						LPCOLLISIONEVENT& otherEvent) {
		return (thisEvent->t < otherEvent->t) ? 1 : 0;
	}*/

};
typedef CollisionEvent* LPCOLLISIONEVENT

//using namespace std; 
//
//class Collision2D: protected MonoBehaviour {
//public: 
//	float t, nx, ny;
//	float  dx, dy;
//
//	Collision2D(); 
//	~Collision2D(); 
//
//	/*
//	*/
//	bool Comparator(const Collision2D &otherCollision) {
//		return this->t < otherCollision.t; 
//	}
//};
//typedef Collision2D* LPCOLLISIONEVENT