//#include "Animation.h"
//
//Animations::Animations(string id, DWORD defaultTime) {
//	this->id = id; 
//	this->defaultFrameTime = defaultTime; 
//}
//
//Animations::Animations(const Animations& obj)
//{
//	this->id = obj.id;
//	this->lastFrameTime = obj.lastFrameTime;
//	this->currentFrame = -1;
//	vector<LPANIMATIONFRAME> newFrames(obj.animationSet);
//	this->animationSet = newFrames;
//
//	//// Clone Animation Transform to Object Transform  
//	//this->localPosition = obj.localPosition; 
//	//this->position = obj.position; 
//	//this->scale = obj.scale; 
//	//this->rotationAngle = obj.rotationAngle; 
//
//	this->isLoop = obj.isLoop;
//	this->isPlaying = obj.isPlaying;
//}
//
//Animations::~Animations() {
//	//Empty on purpose
//}
//
//void Animations::AddAnimationFrame(LPSPRITE sprite, 
//	D3DXVECTOR2 position, 
//	DWORD frameTime){
//	int t = frameTime;
//	if (frameTime <= 0) t = this->defaultFrameTime;
//
//	LPANIMATIONFRAME frame = new AnimationFrame(sprite, t, position);
//	animationSet.push_back(frame);
//}
//
//// Not clear here 
//void Animations::SetPlay(bool isPause) {
//	if (isPause == false && isPlaying == false)
//	{
//		currentFrame = -1;
//	}
//	isPlaying = true;
//}
//
//LPANIMATIONFRAME Animations::GetAnimationFrame()
//{
//	if (currentFrame != -1)
//		return animationSet[currentFrame];
//	return NULL;
//}
//
//void Animations::Render(D3DXVECTOR2 position, int alpha) {
//}


#include "Animation.h"

Animation::Animation(string id, DWORD defaultTime)
{
	this->id = id;
	this->currentFrame = -1;
	this->defaultTime = defaultTime;

	this->isLooping = true;

	this->isEnabled = true;

	this->transform.SetPosition(D3DXVECTOR2(0.0f, 0.0f));
}

void Animation::Add(LPSPRITE sprite, D3DXVECTOR2 position, DWORD frameTime)
{
	int t = frameTime;

	if (frameTime <= 0)
	{
		t = this->defaultTime;
	}

	LPANIMATION_FRAME frame = new AnimationFrame(sprite, t, position);

	frames.push_back(frame);
}

void Animation::Render(D3DXVECTOR2 position, int alpha)
{
	if (frames.size() == 0)
	{
		return;
	}

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
			if (currentFrame == frames.size() - 1 && isLooping == false)
			{
				//gameobj->EndAnimation();
				isEnabled = false;
			}
			else if (isEnabled == true)
			{
				currentFrame++;
				lastFrameTime = now;
				if (currentFrame >= frames.size())
				{
					currentFrame = 0;
				}
			}
		}
	}

	frames[currentFrame]->GetSprite()->Draw(
		D3DXVECTOR2(position.x, position.y), 
		transform.GetScale(), 
		transform.GetRotationAngle());
}

void Animation::SetPosition(D3DXVECTOR2 position)
{
	this->transform.SetPosition(position);
}

void Animation::SetScale(D3DXVECTOR2 scale)
{
	this->transform.SetScale(scale);
}

void Animation::SetRotation(float rotation)
{
	this->transform.SetRotationAngle(rotation);
}

void Animation::SetLoop(bool isLoop)
{
	this->isLooping = isLoop;
}

void Animation::SetLocalPosition(D3DXVECTOR2 relativeposition)
{
	this->localPosition = relativeposition;
}

void Animation::SetEnabled(bool enable)
{
	if (enable == false && isLooping == false)
	{
		currentFrame = -1;
	}
	isEnabled = true;
}

bool Animation::CheckIsEnabled()
{
	return this->isEnabled;
}

D3DXVECTOR2 Animation::GetPosition()
{
	return this->transform.GetPosition();
}

D3DXVECTOR2 Animation::GetScale()
{
	return this->transform.GetPosition();
}

float Animation::GetRotation()
{
	return this->transform.GetRotationAngle();
}

bool Animation::GetIsLooping()
{
	return this->isLooping;
}

LPANIMATION_FRAME Animation::GetAnimFrame()
{
	if (currentFrame != -1)
	{
		return frames[currentFrame];
	}
	return NULL;
}

D3DXVECTOR2 Animation::GetLocalPosition()
{
	return this->localPosition;
}

void Animation::SetGameObject(LPGAMEOBJECT obj)
{
	this->gameobj = obj;
}

LPGAMEOBJECT Animation::GetGameObject()
{
	return this->gameobj;
}

int Animation::GetNumberOfFrames()
{
	return frames.size();
}

int Animation::GetCurrentFrame()
{
	return this->currentFrame;
}




