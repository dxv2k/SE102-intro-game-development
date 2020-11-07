#pragma once
#include <string>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>

#include "AnimationFrame.h"
#include "Sprites.h"
#include "GameObject.h"

using namespace std; 

struct Transform {

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float rotationAngle; 	

	Transform CreateTransformation(D3DXVECTOR2 position, 
		D3DXVECTOR2 scale, 
		float rotationAngle) {

		Transform result;
		result.position = position;
		result.scale = scale;
		result.rotationAngle = rotationAngle;
		return result;
	}
};

class GameObject;
typedef GameObject* LPGAMEOBJECT;

class Animation;
typedef Animation* LPANIMATION;

class Animation {
	string id;
	int currentFrame;
	DWORD defaultFrameTime, lastFrameTime;
	bool isLoop, isPlaying;

	Transform transform;
	D3DXVECTOR2 relativePosition;

	vector<LPANIMATIONFRAME> animationFrames;
	GameObject* gameObject; 

public: 
	Animation(string id, DWORD defaultTime = 100);
	Animation(const Animation& obj);
	~Animation();
	
	// AddAnimation only support add single frame to create Animations
	void AddAnimation(LPSPRITE sprite, 
		D3DXVECTOR2 position, 
		DWORD frameTime = 0);

	void Render(D3DXVECTOR2 position, int alpha = 255);

	void SetPosition(D3DXVECTOR2 p) { this->transform.position = p; } // relative position
	D3DXVECTOR2 GetPosition() { return transform.position; }

	void SetScale(D3DXVECTOR2 newScale) { this->transform.scale = newScale; }
	D3DXVECTOR2 GetScale() { return transform.scale; }

	void SetRotation(float angle) { this->transform.rotationAngle = angle; }
	float GetRotation() { return transform.rotationAngle; }

	void SetAnimationLoop(bool isLoop) { this->isLoop = isLoop; }
	bool GetAnimationLoop() { return isLoop; }

	void SetRelativePosition(D3DXVECTOR2 pos) { this->relativePosition = pos; }
	D3DXVECTOR2 GetRelativePosition() { return relativePosition; }

	void SetGameObject(LPGAMEOBJECT obj) { gameObject = obj; }
	LPGAMEOBJECT GetGameObject() { return gameObject; }

	void SetPlay(bool isPause);

	LPANIMATIONFRAME GetAnimationFrame(); 
};



