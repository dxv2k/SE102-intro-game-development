#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "KeyEventHandler.h"



class Game {
	//static Game * __instance;
	//HWND hWnd;									// Window handle

	//LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	//LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	//LPDIRECT3DSURFACE9 backBuffer = NULL;		
	//LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 
	//
	//BYTE keyStates[256]; 
	//	
	//LPKEYEVENTHANDLER keyHandler; 

	int backBufferWidth = 0;
	int backBufferHeight = 0;

	static Game * __instance;
	HWND hWnd;									// Window handle

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;		
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data

	LPKEYEVENTHANDLER keyHandler;

public:
	void Init(HWND hWnd); // init directX parameter, device 

	void InitKeyboard(LPKEYEVENTHANDLER handler); 
	int IsKeyDown(int KeyCode); 
	void ProcessKeyboard(); 

	void Draw(
		float x, 
		float y, 
		LPDIRECT3DTEXTURE9 texture, 
		int upper_left_x, 
		int upper_left_y, 
		int bottom_right_x, 
		int bottom_right_y);

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	int GetBackBufferWidth() { return backBufferWidth; }
	int GetBackBufferHeight() { return backBufferHeight; }

	static Game * GetInstance();

	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath);

	~Game();
};








