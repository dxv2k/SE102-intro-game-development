#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>


class KeyboardEventHandler {
public: 
	virtual void KeyState(BYTE* state) = 0; 
	virtual void OnKeyDown(int KeyCode) = 0; 
	virtual void OnKeyUp(int KeyCode) = 0; 
};


