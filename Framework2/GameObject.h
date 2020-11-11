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

	// Animation 
	unordered_map<string, LPANIMATION> animations;
	
public:

	GameObject();
	~GameObject();

	// Correct order of execution for the program
	// TODO: Add physics and collider box in the future 
	void Init();

	// Tag utility 
	void SetTag(string inputTag) { this->tag = inputTag; }
	string GetTag() { return this->tag; }
	bool CompareTag(string otherTag);





	// Create a copy of animation and manage it with GameObject instead of pointer 
	// and with Singleton 
	// With this way, it is much easier 
	void AddAnimation();
	void LoadAnimation(); 
	
	string GetCurrentState() { return currentState; }
	string GetLastState() { return lastState; }
	void SetState(string newState); 

};



