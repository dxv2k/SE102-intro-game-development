#pragma once

#include "GameObject.h"

#define MARIO_WIDTH 14

class CMario : public CGameObject
{
protected:
	float vx;
public:
	CMario(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
};

class CBrick : public CGameObject {
public: 
	CBrick(float x, float y); 
	void Update(DWORD dt); 
	void Render(); 
};






















































































































