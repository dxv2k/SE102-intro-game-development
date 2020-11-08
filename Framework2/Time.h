#pragma once 

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

class Time {
private: 
	DWORD __cumalativeTime; 
public: 

	static float dt; 

	Time();
	~Time();

	void SetDeltaTime(float newDT) { this->dt = newDT; }
	float GetDeltaTime() { return dt; }



};

