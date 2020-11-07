#include "Animation.h"

Animation::Animation(string id, DWORD defaultTime) {
	this->id = id; 
	this->defaultFrameTime = defaultTime; 
}

Animation::Animation(const Animation& obj)
{
	this->id = obj.id;
	this->lastFrameTime = obj.lastFrameTime;
	this->currentFrame = -1;
	vector<LPANIMATIONFRAME> newFrames(obj.animationFrames);
	this->animationFrames = newFrames;
	this->transform = transform.CreateTransformation(obj.transform.position, obj.transform.scale, obj.transform.rotationAngle);
	this->isLoop = obj.isLoop;
	this->isPlaying = obj.isPlaying;
}

Animation::~Animation() {
	//Empty on purpose
}

void Animation::AddAnimation(LPSPRITE sprite, 
	D3DXVECTOR2 position, 
	DWORD frameTime){
	int t = frameTime;
	if (frameTime <= 0) t = this->defaultFrameTime;

	LPANIMATIONFRAME frame = new AnimationFrame(sprite, t, position);
	LPANIMATIONFRAME.push_back(frame);
}

void Animation::SetPlay(bool isPause) {
	if (isPause == false && isPlaying == false)
	{
		currentFrame = -1;
	}
	isPlaying = true;
}


LPANIMATIONFRAME Animation::GetAnimationFrame()
{
	if (currentFrame != -1)
		return animationFrames[currentFrame];
	return NULL;
}


