#include "RigidBody.h"

RigidBody::RigidBody() {
	this->velocity = D3DXVECTOR2(0.0f,0.0f);
	this->gravity = 0.0f;
	this->acceleration = 0.0f;
}

RigidBody::~RigidBody() {
	// Empty on purpose
}

void RigidBody::SetVelocity(D3DXVECTOR2* velocity) {
	this->velocity.x = velocity->x;
	this->velocity.y = velocity->y;
}

D3DXVECTOR2 RigidBody::GetVelocity() {
	return this->velocity;
}

void RigidBody::SetGravity(float gravity) {
	this->gravity = gravity;
}

float RigidBody::GetGravity() {
	return this->gravity;
}

bool RigidBody::IsDynamic() {
	return this->isDynamic;
}

void RigidBody::SetDynamic(bool dynamic) {
	this->isDynamic = dynamic;
}

void RigidBody::SetAcceleration(float acceleration) {
	this->acceleration = acceleration;
}

float RigidBody::GetAcceleration() {
	return this->acceleration;
}
