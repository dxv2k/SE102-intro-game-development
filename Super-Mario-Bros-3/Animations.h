#pragma once
#include "Sprites.h"
#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>

/*
	Sprite animation
*/
class AnimationFrame {
	LPSPRITE sprite;
	DWORD time;

public:
	AnimationFrame(LPSPRITE sprite, int time) { this->sprite = sprite; this->time = time; }
	DWORD GetTime() { return time; }
	LPSPRITE GetSprite() { return sprite; }
};

typedef AnimationFrame *LPANIMATION_FRAME;

class Animation {
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPANIMATION_FRAME> frames;
public:
	Animation(int defaultTime) { this->defaultTime = defaultTime; lastFrameTime = -1; currentFrame = -1; }

	void Add(int spriteId, 
		DWORD time = 0 // Set time for how long this frame will freeze 
	);

	void Render(float x, float y);
};

typedef Animation *LPANIMATION;

class Animations {
	static Animations * __instance;

	unordered_map<int, LPANIMATION> animations;

public:
	void Add(int id, LPANIMATION ani);
	LPANIMATION Get(int id);

	static Animations * GetInstance();
};
