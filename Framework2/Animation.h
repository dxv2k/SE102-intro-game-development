//#pragma once
//#include <string>
//#include <vector>
//#include <d3d9.h>
//#include <d3dx9.h>
//
//#include "AnimationFrame.h"
//#include "Sprites.h"
//#include "GameObject.h"
//#include "Transform.h"
//
//using namespace std; 
//
//class GameObject;
//typedef GameObject* LPGAMEOBJECT;
//
//class Animations;
//typedef Animations* LPANIMATION;
//
//class Animations {
//protected: 
//	Transform transform; 
//	string id;
//	int currentFrame;
//	DWORD defaultFrameTime, lastFrameTime;
//	bool isLoop, isPlaying;
//
//	//Transform transform;
//	//D3DXVECTOR2 localPosition;
//	
//	/*
//	Each animation contain 	
//	*/
//	vector<LPANIMATIONFRAME> animationSet;
//
//	GameObject* gameObject; 
//
//public: 
//	Animations(string id, DWORD defaultTime = 100);
//
//	// This function was created with the intention 
//	// to made a copy of the AnimationSet to GameObject
//	// instead of using a pointer to AnimationSet. 
//	// Also, which mean it will run directly on RAM  
//	Animations(const Animations& obj);
//
//	~Animations();
//	
//	void Render(D3DXVECTOR2 position, int alpha = 255);
//
//	void SetPlay(bool isPause); // Need to work on 
//	bool GetPlayStatus() { return isPlaying; }
//	
//	void AddAnimationFrame(LPSPRITE sprite, 
//		D3DXVECTOR2 position, // use for animation with fixed position  
//		DWORD frameTime = 0);
//	LPANIMATIONFRAME GetAnimationFrame(); 
//
//	void SetPosition(D3DXVECTOR2 newPos) { this->transform.position = newPos; } // local position
//	D3DXVECTOR2 GetPosition() { return this->transform.position; }
//
//	void SetScale(D3DXVECTOR2 newScale) { this->transform.scale = newScale; }
//	D3DXVECTOR2 GetScale() { return transform.scale; }
//
//	void SetRotation(float angle) { this->transform.rotationAngle = angle; }
//	float GetRotation() { return transform.rotationAngle; }
//
//	void SetLocalPosition(D3DXVECTOR2 pos) { this->transform.localPosition = pos; }
//	D3DXVECTOR2 GetLocalPositionn() { return this->transform.localPosition; }
//
//	void SetAnimationLoop(bool isLoop) { this->isLoop = isLoop; }
//	bool GetAnimationLoop() { return isLoop; }
//
//	void SetGameObject(LPGAMEOBJECT obj) { gameObject = obj; }
//	LPGAMEOBJECT GetGameObject() { return gameObject; }
//};

#pragma once

#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Utils.h"
#include "Sprites.h"
#include "GameObject.h"
#include "AnimationFrame.h"
#include "Transform.h"

using namespace std;

class AnimationFrame;
typedef AnimationFrame* LPANIMATION_FRAME;

class GameObject;
typedef GameObject* LPGAMEOBJECT;

class Animation
{
	string id;

	int currentFrame;
	int defaultTime;
	DWORD lastFrameTime;

	bool isLooping;
	//for looping animation, brick at the end of the scene game, Goomba, Mario_walk...

	bool isEnabled;
	//some animation just plays when we get into an overlappedBox or triggerBox, or animation will be disbale when mario interacts with it (brick with the quesion mark);
	//or for object have many animaton in the animation_set
	//ex: Mario have a lot of states with a lot of animations for each states
	//when an state end -> disable the state -> disable the animation of that state

	Transform transform;
	//set the position, scale or rotation of the anmation (ex: the leaf item, sync the animation's position with the position of gameobject)

	D3DXVECTOR2 localPosition;
	//position of the animation with the relative object (for example when we draw attack animation of the racoon, movement animation of the marion -> update animation with the gameobj...)
	//what is the difference between localPostion and Postion(worldPostion)
	//localPostion is the position which is the centerpoint of the coordinate is gameObj
	//for example racoon mario have a tail and it's localPosition is 0,1
	//world postion is the position of component with the world

	// an animation = 1 or alot of frames
	vector<LPANIMATION_FRAME> frames;

	GameObject* gameobj;
	//relative obj with the animation

public:
	Animation(string id, DWORD defaultTime = 100);

	void Add(LPSPRITE sprite, D3DXVECTOR2 position, DWORD frameTime = 0);
	void Render(D3DXVECTOR2 position, int alpha = 255);

	void SetPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 GetPosition();

	void SetScale(D3DXVECTOR2 scale);
	D3DXVECTOR2 GetScale();

	void SetRotation(float rotation);
	float GetRotation();

	void SetLoop(bool isLoop);
	bool GetIsLooping();

	void SetLocalPosition(D3DXVECTOR2 relativeposition);
	D3DXVECTOR2 GetLocalPosition();

	void SetEnabled(bool enable);
	bool CheckIsEnabled();

	LPANIMATION_FRAME GetAnimFrame();

	void SetGameObject(LPGAMEOBJECT obj);
	LPGAMEOBJECT GetGameObject();

	int GetNumberOfFrames();
	int GetCurrentFrame();
};
typedef Animation* LPANIMATION;
