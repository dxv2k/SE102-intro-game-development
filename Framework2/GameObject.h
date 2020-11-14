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

#include "CollisionBox.h"

using namespace std; 

class Animation; 
typedef Animation* LPANIMATION; 

class GameObject : protected MonoBehaviour {
protected:
	Transform transform; 
	string tag;
	string name; 
	string currentState, lastState;

	/// <summary>
	/// Add current state, every GameObject can only have 
	/// 1 ColliderBox
	/// Every GameObject 2 compulsory component
	///	- RigidBody & ColliderBox   
	/// </summary>
	LPCOLLIDERBOX colliderBox; 
	LPRIGIDBODY rigidBody; 

	// Each GameObject can have more than one animationSet. 
	// Example how to store animationSets for GameObj: <state_name, animationSet>
	std::unordered_map<string, LPANIMATION> objAnimation;
	
public:
	GameObject();
	GameObject(D3DXVECTOR2 position, 
				D3DXVECTOR2 scale,
				float rotation);
	~GameObject();

	// Correct order of execution for the program
	// TODO: Add physics and collider box in the future for Init  
	void Init();

	// RigidBody utility 
	void SetRigidBody(LPRIGIDBODY &rb) { this->rigidBody = rb; }
	LPRIGIDBODY GetRigidBody() { return this->rigidBody; }

	// ColliderBox utility 
	void SetColliderBox(LPCOLLIDERBOX &cb) { this->colliderBox = cb; }
	LPCOLLIDERBOX GetColliderBox() { return this->colliderBox; }
		
	// TODO: Add a more specific parameter for RigidBody
	void SetRigidBody(LPRIGIDBODY &rb) { this->rigidBody = rb; }
	// TODO: Add a more specific parameter for ColliderBox
	void SetColliderBox(LPCOLLIDERBOX &cb) { this->colliderBox = cb; }

	// Name utility 
	void SetName(string newName) { this->name = newName; }
	string GetName() { return this->name; }

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


