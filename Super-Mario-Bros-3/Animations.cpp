#include "Animations.h"
#include "Sprites.h"
#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>

void Animation::Add(int spriteID, DWORD time) {
	int t = time; 
	if (time == 0) {
		t = this->defaultTime; 
	}
	LPSPRITE sprite = Sprites::GetInstance()->Get(spriteID); 
	LPANIMATION_FRAME frame = new AnimationFrame(sprite, t); 
	frames.push_back(frame); 
}

void Animation::Render(float x, float y) {
	DWORD now = GetTickCount();
	if (currentFrame == -1) 
	{
		currentFrame = 0; 
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size()) currentFrame = 0;
		}
		
	}
	frames[currentFrame]->GetSprite()->Draw(x, y);
}

Animations* Animations::__instance = NULL; 

Animations* Animations::GetInstance() {
	if (__instance == NULL) {
		__instance = new Animations(); 
	}
	return __instance; 
}

void Animations::Add(int id, LPANIMATION ani)
{
	animations[id] = ani;
}

LPANIMATION Animations::Get(int id)
{
	return animations[id];
}





