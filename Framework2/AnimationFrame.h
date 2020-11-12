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
	D3DXVECTOR2 localPosition; 

public:
	AnimationFrame(
		LPSPRITE sprite, 
		DWORD time, 
		D3DXVECTOR2 pos); 
	~AnimationFrame(); 

	LPSPRITE GetSprite() { return sprite; }
	DWORD GetTime() { return time; }
}; 

