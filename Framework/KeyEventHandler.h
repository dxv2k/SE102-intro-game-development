#pragma once
#include <Windows.h>

class KeyEventHandler {
public: 
	virtual void KeyState(BYTE *state); 
	virtual void OnKeyUp(int KeyCode);
	virtual void OnKeyDown(int KeyCode);
};

typedef KeyEventHandler* LPKEYEVENTHANDLER; 

