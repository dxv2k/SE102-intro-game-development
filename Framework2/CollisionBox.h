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
#include "Collision.h" // This one caused error

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

	//LPGAMEOBJECT gameObj;	// the GameObject attached to the ColliderBox  

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

	// TODO: Complete GetBoundingBox() 
	// Mostly use for SweptAABBX
	//RectFloat GetBoundingBox(); 

	//TODO:Add SweptAABB & Filter Collision & Calculate Potential Collision 
	LPCOLLISIONEVENT SweptAABBE(LPCOLLIDERBOX other);
	
	void CalcPotentialCollisions(
		vector<LPCOLLIDERBOX>* coObjects, 
		vector<LPCOLLISIONEVENT>& coEvents);

	void FilterCollision(
		vector<LPCOLLISIONEVENT>& coEvents,
		vector<LPCOLLISIONEVENT>& coEventsResult,
		float& min_tx,
		float& min_ty,
		float& nx,
		float& ny);
};
typedef ColliderBox* LPCOLLIDERBOX; 
