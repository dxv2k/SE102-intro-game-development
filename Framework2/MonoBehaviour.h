#pragma once
#include "Time.h"

class MonoBehaviour: protected Time 
{
protected: 
	bool enabled;
	bool isActiveandEnable; 
	
public: 
	//Reference: https://docs.unity3d.com/Manual/ExecutionOrder.html
	//---------------------ORDER-OF-EXECUTION------------------------
	// THE FOLLOWING EXECUTION MUST BE CALLED CORRECTLY 

	// Awake: Intialize data, call only once in a lifetime    
	virtual void Awake(); 

	// Start: Intialize the target variables
	virtual void Start(); 

	// Update: called every frame, main update for the whole program
	void Update(); 
	
	// FixedUpddate: indepentdent from FPS, time interval is constant  
	// FixedUpddate: Use for physics upate (Ex: RigidBody and Collision) 
	void FixedUpdate();

	// LateUpdate: Post processing update, called after update
	// Should be use 
	// Recommend to use for camera update
	void LateUpdate();

	////////////////////////////////////////////////////////////////

	virtual void OnCollisionEnter(); 
	
	virtual void OnTriggerEnter();

	// OnOverlapped: when an intersection of this and other 
	virtual void OnOverlapped(); 

	virtual void OnDestroy(); 

	virtual void PreRender();

	virtual void Render();

	virtual void PostRender();

};

