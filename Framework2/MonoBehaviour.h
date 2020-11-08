#pragma once
#include "Time.h"

class MonoBehaviour: protected Time 
{
protected: 
	bool enabled;
	bool isActiveandEnable; 
	
public: 
	// Called when GameObject begins to exists
	virtual void Start(); 

	// Called every frame
	void Update(); 
	
	// Use for physics upate (Ex: RigidBody and Collision) 
	// FixedUpdate based on 20 clic
	void FixedUpdate();

	// Use for camera update
	void LateUpdate();

	//void OnCollisionEnter(); 
	//void OnTriggerEnter();
};

