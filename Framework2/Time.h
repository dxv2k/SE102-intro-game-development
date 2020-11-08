#pragma once 

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

class Time {
private: 
	DWORD deltaTime; // time between current frame and previous frame 
	static float _time; // time in second since the game start 
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

