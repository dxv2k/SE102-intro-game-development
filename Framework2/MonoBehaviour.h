#pragma once
#include "Time.h"

class MonoBehaviour
{
protected: 
	bool enabled;
	bool isActiveandEnable; 
	
public: 

	// Called when GameObject begins to exists
	void Start(); 

	// Called every frame
	void Update(); 
	
	// Use for physics upate (Ex: RigidBody) 
	void FixedUpdate();


	void OnCollisionEnter(); 
	void OnTriggerEnter();
};

