#pragma once
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Utils.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBody.h"
#include "MonoBehaviour.h"
#include "RectFloat.h"

using namespace std; 

class RigidBody;
typedef RigidBody* LPRIGIDBODY; 

class GameObject; 
typedef GameObject* LPGAMEOBJECT;

class ColliderBox : protected MonoBehaviour,
					public Transform {
protected: 
	D3DXVECTOR2 sizeBox; //height and width respectively 
	//D3DXVECTOR2 center; // center of the Collider Box  by default based on sizeBox 

	// Collider just simply store which GameObject and RigidBody are using it 
	LPGAMEOBJECT gameObj;	// the GameObject attached to the ColliderBox  
	LPRIGIDBODY rigidBody; // the RigidBody attached to the ColliderBox 
	// REMINDER: a GameObject can have multiple ColliderBox

public: 
	ColliderBox();
	ColliderBox(D3DXVECTOR2 sb, 
		LPGAMEOBJECT &obj, 
		LPRIGIDBODY &rb);
	~ColliderBox();

	void SetSizeBox(D3DXVECTOR2 size) { this->sizeBox = size; }
	D3DXVECTOR2 GetSizeBox() { return this->sizeBox; }

	void attachToRigidBody(LPRIGIDBODY rb) { this->rigidBody = rb;  }
	LPRIGIDBODY GetRigidBody() { return this->rigidBody; }

	void attachToGameObject(LPGAMEOBJECT obj) { this->gameObj = obj; }
	LPGAMEOBJECT GetGameObject() { return this->gameObj; }

};
typedef ColliderBox* LPCOLLIDERBOX; 

//class ColliderBox {
//protected: 
//	D3DXVECTOR2 sizeBox; //height and width respectively 
//	//D3DXVECTOR2 center; // center of the Collider Box  by default based on sizeBox 
//
//	// Collider just simply store which GameObject and RigidBody are using it 
//	LPGAMEOBJECT gameObj;	// the GameObject attached to the ColliderBox  
//	LPRIGIDBODY rigidBody; // the RigidBody attached to the ColliderBox 
//	// REMINDER: a GameObject can have multiple ColliderBox
//
//public: 
//	ColliderBox();
//	ColliderBox(D3DXVECTOR2 sb, 
//		LPGAMEOBJECT &obj, 
//		LPRIGIDBODY &rb);
//	~ColliderBox();
//
//	void SetSizeBox(D3DXVECTOR2 size) { this->sizeBox = size; }
//	D3DXVECTOR2 GetSizeBox() { return this->sizeBox; }
//
//	void attachToRigidBody(LPRIGIDBODY rb) { this->rigidBody = rb;  }
//	LPRIGIDBODY GetRigidBody() { return this->rigidBody; }
//
//	void attachToGameObject(LPGAMEOBJECT obj) { this->gameObj = obj; }
//	LPGAMEOBJECT GetGameObject() { return this->gameObj; }
//
//};
//typedef ColliderBox* LPCOLLIDERBOX; 


/// <summary>
/// Use to handle Collision Event by passing Collider into it
/// This is just intial thoughts
/// </summary>
//TODO: Remember to split this to another files for easier management

////Testing purpose 
//struct CollisionEvent
//{
//	LPCOLLIDERBOX objCollider;
//	float t, nx, ny;
//	float dx, dy;		// *RELATIVE* movement distance between this object and obj
//
//	CollisionEvent(float t, 
//		float nx, 
//		float ny, 
//		float dx = 0, 
//		float dy = 0, 
//		LPCOLLIDERBOX obj = NULL)
//	{
//		this->t = t;
//		this->nx = nx;
//		this->ny = ny;
//		this->dx = dx;
//		this->dy = dy;
//		this->objCollider = obj;
//	}
//	
//	//static bool compare(const LPCOLLISIONEVENT& thisEvent, 
//	//					LPCOLLISIONEVENT& otherEvent) {
//	//	return (thisEvent->t < otherEvent->t) ? 1 : 0;
//	//}
//
//};
//typedef CollisionEvent* LPCOLLISIONEVENT

//class Collision : protected MonoBehaviour {
//private: 
//	float time;
//	ColliderBox* collider;
//	D3DXVECTOR2 collisionDirection;
//
//public: 
//	Collision(); 
//	~Collision(); 
//
//	/*
//		TODO: 
//		-	Add SweptAABB
//		-	Filter Collision 
//		-	Calculate  Potential Collision 
//	*/
//	Collision(float time,
//		D3DXVECTOR2 direction,
//		ColliderBox* collider); 
//	
//	bool Comparator(const Collision &otherCollisionEvent)
//	{
//		return this->time < otherCollisionEvent.time; 
//	}
//};
//
