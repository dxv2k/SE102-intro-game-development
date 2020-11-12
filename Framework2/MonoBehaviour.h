#pragma once
#include "Time.h"

class MonoBehaviour: protected Time 
{
protected: 
	int id; 
	bool enabled;
	
public: 
	bool isEnabled() { return this->enabled; }
	void setActive(bool active) { this->enabled = active; }
	int GetInstanceID() { return this->id; }

	//Reference: https://docs.unity3d.com/Manual/ExecutionOrder.html
	//----------------------EXECUTION-ORDER--------------------------
	// THE FOLLOWING EXECUTION MUST BE CALLED CORRECTLY 

	// Awake: Intialize data, call only once in a lifetime    
	virtual void Awake(); 

	// Start: Intialize the target variables
	virtual void Start(); 

	// Update: Main update, called every frame 
	void Update(); 
	
	// FixedUpddate: indepentdent from FPS, time interval is constant  
	// FixedUpddate: Use for physics upate (Ex: RigidBody and Collision) 
	virtual void FixedUpdate();

	// LateUpdate: Post processing update, called after update()
	// Recommend to use for camera update
	void LateUpdate();

	////////////////////////////////////////////////////////////////

	// This part below here is not fully complete
	// OnCollisionEnter: Called when collision occured 
	virtual void OnCollisionEnter(); 

	// OnTriggerEnter: same with CollisionEnter but use with RigidBody2D	
	virtual void OnTriggerEnter();

	// OnOverlapped: when an intersection of this and other 
	virtual void OnOverlapped(); 

	// OnDestroy: Called when destroying an object or scene end  
	virtual void OnDestroy(); 

	// Destroy: Called when destroy an object or scene end  
	virtual void Destroy(); 

	// PreRender: Intialized render information 
	// Use for camera, called before camera starts render a scene 
	virtual void PreRender();

	// Render: render information based on PreRender  
	virtual void Render();

	//// PostRender: called after camera has finish render a scene 
	//virtual void PostRender();

	// OnKeyUp: 
	virtual void OnKeyUp();

	// OnKeyDown: 
	virtual void OnKeyDown();

};

