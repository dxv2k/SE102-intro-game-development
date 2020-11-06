#pragma once

#include <string>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>

#include "AnimationFrame.h"
#include "Sprites.h"

#include "GameObject.h"

class GameObject;
typedef GameObject* LPGAMEOBJECT;

class Animation;
typedef Animation* LPANIMATION;
class Animation; 

using namespace std; 

class Animation {
	string id;
	DWORD defaultFrameTime, lastFrameTime;

	int currentFrame;
	bool isLoop, isPlaying;

	//Transform transform;
	D3DXVECTOR2 relativePosition;
	vector<LPANIMATIONFRAME> animationFrames;

	GameObject* gameObject; 
public: 
	Animation(std::string id, DWORD defaultTime = 100);
	Animation(const Animation& obj);
	void Add(LPSPRITE sprite, D3DXVECTOR2 pos, DWORD frameTime = 0);
	void Render(D3DXVECTOR2 position, int alpha = 255);

	//void setposition(d3dxvector2 p) { this->transform.position = p; } // relative position
	//void setscale(d3dxvector2 s) { this->transform.scale = s; }
	//void setrotation(float r) { this->transform.rotationangle = r; }
	//void setloopanimation(bool isloop) { this->isloop = isloop; }
	//void setrelativeposition(d3dxvector2 rp) { this->relativeposition = rp; }
	//void setplay(bool ispause);
	//d3dxvector2 getposition() { return transform.position; }
	//d3dxvector2 getscale() { return transform.scale; }
	//float GetRotation() { return transform.rotationAngle; }

	bool GetLoopAnimation() { return isLoop; }

	LPANIMATIONFRAME GetAnimationFrame(){ return animationFrames}
	D3DXVECTOR2 GetRelativePosition() { return relativePosition; }

	void SetGameObject(LPGAMEOBJECT obj) { gameObject = obj; }
	LPGAMEOBJECT GetGameObject() { return gameObject; }

	~Animation();





};



