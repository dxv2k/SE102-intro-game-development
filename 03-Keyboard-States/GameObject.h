#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"


using namespace std;

class CGameObject
{
protected:

	float x; 
	float y;

	float vx;
	float vy;

	int nx;	 

	int state;									
	
	int status;  // For debugging multi status of character  

	static vector<LPANIMATION> animations;

public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }

	void SetState(int state) { this->state = state; }
	void SetStatus(int status) { this->status = status; }
	int GetState() { return this->state; }


	static void AddAnimation(int aniId);

	CGameObject();

	void Update(DWORD dt);
	void Render();
	~CGameObject();
};