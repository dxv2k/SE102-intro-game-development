#include "RigidBody.h"

Rigidbody::Rigidbody()
{
	this->velocity = D3DXVECTOR2(0.0f,0.0f);
	this->gravity = 0.0f;
	this->acceleration = 0.0f;
}

void Rigidbody::SetVelocity(D3DXVECTOR2* velocity)
{
	this->velocity.x = velocity->x;
	this->velocity.y = velocity->y;
}

D3DXVECTOR2 Rigidbody::GetVelocity()
{
	return this->velocity;
}

void Rigidbody::SetGravity(float gravity)
{
	this->gravity = gravity;
}

float Rigidbody::GetGravity()
{
	return this->gravity;
}

bool Rigidbody::IsDynamic()
{
	return this->isDynamic;
}

void Rigidbody::SetDynamic(bool dynamic)
{
	this->isDynamic = dynamic;
}

void Rigidbody::SetAcceleration(float acceleration)
{
	this->acceleration = acceleration;
}

float Rigidbody::GetAcceleration()
{
	return this->acceleration;
}
