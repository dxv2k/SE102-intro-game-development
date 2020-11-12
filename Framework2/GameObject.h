#pragma once 
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> 

#include "Game.h" 
#include "Animation.h"
#include "Textures.h"
#include "Utils.h"
#include "Constant.h"
#include "Transform.h"

using namespace std; 

class GameObject : protected MonoBehaviour {
protected:
	Transform transform; 
	string tag;
	string currentState, lastState;

	// Each GameObject can have more than one animationSet. 
	// Example how to store animationSets for GameObj: <state_name, animationSet>
	unordered_map<string, LPANIMATION> animations;
	
public:
	GameObject();
	GameObject(D3DXVECTOR2 position, 
				D3DXVECTOR2 scale,
				float rotation);
	~GameObject();

	// Correct order of execution for the program
	// TODO: Add physics and collider box in the future for Init  
	void Init();

	// Tag utility 
	void SetTag(string inputTag) { this->tag = inputTag; }
	string GetTag() { return this->tag; }
	bool CompareTag(string otherTag);
	bool IsEmptyTag(); 

	// Object state utility
	string GetCurrentState() { return currentState; }
	string GetLastState() { return lastState; }
	void SetState(string newState); 

	// Animation utility 
	// Each GameObject will hold its own AnimationSet 
	// instead of pointing to animation database to get animation
	void AddAnimation(string name, LPANIMATION animationSet);
	void LoadAnimation(); 
};


