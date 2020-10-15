#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>
#include "Sprites.h"
#include "Animations.h"

using namespace std;

class GameObject
{
protected:
	// Current coordinate for GameObject in Window 
	float x; 
	float y;
	
	// Velocity for when moving 
	// Currently not support acceleration
	float vx; 
	float vy; 

	// Facing left or right 
	int nx; 

	// Current state of an object
	int state; 

	// Full animations for GameObject
	static vector <LPANIMATION> animations;

public: 
	GameObject();

	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }

	static void AddAnimation(int aniID); 

	void SetState(int state) { this->state = state;  }


	float GetX() { return x; }
	float GetY() { return y; }

	void Update(DWORD dt);
	void Render();
	

	~GameObject();
};










