#pragma once

#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Utils.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBody.h"
#include "MonoBehaviour.h"


class CollisionBox : protected MonoBehaviour,
					public Transform {
protected: 
	D3DXVECTOR2 sizeBox; //height and width respectively 
	//D3DXVECTOR2 center; // center of the Collision Box  by default based on sizeBox 
	LPGAMEOBJECT gameObj; 
	LPRIGIDBODY rigidBody; 

public: 
	CollisionBox();
	~CollisionBox();

	void SetSizeBox(D3DXVECTOR2 size) { this->sizeBox = size; }
	D3DXVECTOR2 GetSizeBox() { return this->sizeBox; }

	void attachRigidBody(LPRIGIDBODY& rb) { this->rigidBody = rb;  }
	LPRIGIDBODY getRigidBody() { return this->rigidBody; }

	void attachGameObject(LPGAMEOBJECT& obj) { this->gameObj = obj; }
	LPGAMEOBJECT getGameObject() { return this->gameObj; }
};

typedef CollisionBox* LPCOLLISIONBOX; 
