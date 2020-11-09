#pragma once 

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

class Time {
private: 
	static float _time; // time in second 
	DWORD __accumalativeTime; 

	bool isJustChanged; 

public: 
	Time();
	~Time();

	//float GetDeltaTime() { return deltaTime; }
	void Update(DWORD dt); 

	void SetTime(int newTime); 
	int GetTime(); 
	bool CheckIsJustChanged(); 

};

