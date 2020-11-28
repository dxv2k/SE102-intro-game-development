#pragma once

#include "Transform.h"
#include "MonoBehaviour.h"

// TODO: Complete Rigidbody, missing Update() method

// TODO: RigidBody2D Type IS NOT COMPLETE 
// Ref: https://docs.unity3d.com/ScriptReference/RigidbodyType2D.html

class RigidBody : protected MonoBehaviour
{
protected:
	D3DXVECTOR2 velocity;
	float gravity;
	bool isDynamic;
	float acceleration;

public:
	RigidBody();
	~RigidBody();
	
	void SetVelocity(D3DXVECTOR2* velocity);
	D3DXVECTOR2 GetVelocity();

	void SetGravity(float gravity);
	float GetGravity();

	// Object moving -> Dynamic 
	// Otherwise -> Static
	bool IsDynamic();
	void SetDynamic(bool dynamic);

	void SetAcceleration(float acceleration);
	float GetAcceleration();
};
 
typedef RigidBody* LPRIGIDBODY; 
