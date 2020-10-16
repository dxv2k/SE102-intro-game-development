#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>


#define KEYBOARD_BUFFER_SIZE 1024
#define DIRECTINPUT_VERSION 0x0800

class KeyEventHandler {
public: 
	virtual void KeyState(BYTE* state); 
	virtual void OnKeyDown(int KeyCode); 
	virtual void OnKeyUp(int KeyCode); 
};

typedef KeyEventHandler * LPKEYEVENTHANDLER;

/*
	TODO: Remember to create custom key so that we are able 
	to switch to different status of the GameObject 
	Ex: Mario -> 4 status -> Num1,2,3,4 -> status 1,2,3,4
*/


/* 
	 In furture version, default keyboard control for GameObject 
	 will be set right here. 
	 For example: 
		W,S,A,D, SPACE will be use to control game Object 

*/



