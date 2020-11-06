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

using namespace std; 

class GameObject {
protected: 
	int id; 
	DWORD dt; 
	bool enable; 
		
	string currentState, lastState; 


	unordered_map<string, LPANIMATION> animations;

public: 
	GameObject(); 
	~GameObject(); 

	//virtual void Update(DWORD dt, Camera* cam);
	//virtual void Render(Camera* cam);
	virtual void Update(DWORD dt);
	virtual void Render();

	// Create a copy of animation and manage it with GameObject instead of pointer 
	// and with Singleton 
	// With this way, it is much easier 
	virtual void AddAnimation();
	virtual void LoadAnimation(); 
	
	string GetState(); 
	void SetState(string newState){}

};






