#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>


class KeyEventHandler {
public: 
	virtual void KeyState(BYTE* state) = 0; 
	virtual void OnKeyDown(int KeyCode) = 0; 
	virtual void OnKeyUp(int KeyCode) = 0; 
};

/*
	TODO: Remember to create custom key so that we are able 
	to switch to different status of the GameObject 
	Ex: Mario -> 4 status -> Num1,2,3,4 -> status 1,2,3,4
*/

