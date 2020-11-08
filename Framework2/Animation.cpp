#include "Animation.h"

Animations::Animations(string id, DWORD defaultTime) {
	this->id = id; 
	this->defaultFrameTime = defaultTime; 
}

Animations::Animations(const Animations& obj)
{
	this->id = obj.id;
	this->lastFrameTime = obj.lastFrameTime;
	this->currentFrame = -1;
	vector<LPANIMATIONFRAME> newFrames(obj.animationSet);
	this->animationSet = newFrames;

	// Clone Animation Transform to Object Transform  
	this->localPosition = obj.localPosition; 
	this->position = obj.position; 
	this->scale = obj.scale; 
	this->rotationAngle = obj.rotationAngle; 

	this->isLoop = obj.isLoop;
	this->isPlaying = obj.isPlaying;
}

Animations::~Animations() {
	//Empty on purpose
}

void Animations::AddAnimationFrame(LPSPRITE sprite, 
	D3DXVECTOR2 position, 
	DWORD frameTime){
	int t = frameTime;
	if (frameTime <= 0) t = this->defaultFrameTime;

	LPANIMATIONFRAME frame = new AnimationFrame(sprite, t, position);
	animationSet.push_back(frame);
}

// Not clear here 
void Animations::SetPlay(bool isPause) {
	if (isPause == false && isPlaying == false)
	{
		currentFrame = -1;
	}
	isPlaying = true;
}

LPANIMATIONFRAME Animations::GetAnimationFrame()
{
	if (currentFrame != -1)
		return animationSet[currentFrame];
	return NULL;
}

void Animations::Render(D3DXVECTOR2 position, int alpha) {

}

