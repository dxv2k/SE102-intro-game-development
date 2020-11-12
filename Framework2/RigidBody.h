#pragma once

#include "Transform.h"
#include "MonoBehaviour.h"

class Rigidbody : protected MonoBehaviour
{
protected:
	D3DXVECTOR2 velocity;
	float gravity;
	bool isDynamic;
	float acceleration;

public:
	Rigidbody();
	
	void Update(); 

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
