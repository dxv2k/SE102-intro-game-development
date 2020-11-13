#pragma once

#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Utils.h"
#include "Sprites.h"
#include "GameObject.h"
#include "AnimationFrame.h"
#include "Transform.h"

#include "MonoBehaviour.h"

//class CollisionBox : protected MonoBehaviour
//{
//protected: 
//	Transform transform; 
//
//public: 
//	CollisionBox();
//	~CollisionBox();
//
//};

class CollisionBox : protected MonoBehaviour,
					public Transform
{
protected: 
	D3DXVECTOR2 sizeBox; //height and width respectively 
	LPGAMEOBJECT gameObj; 


public: 
	CollisionBox();
	~CollisionBox();
	LPGAMEOBJECT getGameObject() { return this->gameObj; }

};


