#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(LPSPRITE sprite,
	DWORD time, 
	D3DXVECTOR2 position) {

	this->sprite = sprite;
	this->time = time;
	this->position = position;
}

AnimationFrame::~AnimationFrame() {
	// Empty on purpose 
}

