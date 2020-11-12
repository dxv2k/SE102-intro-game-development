#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(LPSPRITE sprite,
	DWORD time, 
	D3DXVECTOR2 pos) {
	this->sprite = sprite;
	this->time = time;
	this->localPosition = pos;
}

AnimationFrame::~AnimationFrame() {
	// Empty on purpose 
}

