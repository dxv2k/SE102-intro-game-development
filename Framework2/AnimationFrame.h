#pragma once 
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <string>

#include "Sprites.h"

class AnimationFrame;
typedef AnimationFrame* LPANIMATIONFRAME;

class AnimationFrame
{
private:
	LPSPRITE sprite;
	DWORD time;

	// Mostly use for speical animation in the game 
	// Example: 
	// -> collision with brick
	// -> mario shooting fire ball 
	D3DXVECTOR2 position; 

public:
	AnimationFrame(
		LPSPRITE sprite, 
		DWORD time, 
		D3DXVECTOR2 position); 
	~AnimationFrame(); 

	LPSPRITE GetSprite() { return sprite; }
	DWORD GetTime() { return time; }

}; 

