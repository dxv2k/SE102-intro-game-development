#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include "Utils.h"
#include "Textures.h"
#include "MonoBehaviour.h"

//#include "Singleton.h"
//#include "SingletonManager.h"


#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_FRAME_RATE 120 

using namespace std; 

class Game : public MonoBehaviour {
private: 
	static Game* __instance;
	static DWORD deltaTime; // delta time 
	HWND hWnd; // Window Handle
	//TODO: Add timeScale for slow-motion in Game.h

	// DirectX and helper lib parameters 
	// NOTICE: not sure why need this 
	D3DXCOLOR transparentColor; 

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;		
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

public: 
	static Game* GetInstance();
	~Game();
	void InitDirectX(HWND hWnd);

	// Basic Game utility  
	void GameInit(); 
	void GameLoop(); 
	void GameEnd(); 

	// Core Game Update utility
	void Update(); 
	void FixedUpdate(); // Used for Physics update 

	// Core Game Render utility
	// NOTICE: Currently, all render (pre,post) prefer not to use
	void Render(); 

	// Time, delta time utility
	DWORD GetDeltaTime() { return deltaTime; }
	DWORD GetFixedDeltaTime() { return 20; }

	// DirectX utility 
	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	// Draw textures utility
	void Draw(D3DXVECTOR2 position, D3DXVECTOR2 anchorPoint, 
		LPDIRECT3DTEXTURE9 texture, RECT rect, 
		D3DXCOLOR transparentColor = BACKGROUND_COLOR);

	void Draw(D3DXVECTOR2 position, LPDIRECT3DTEXTURE9 texture, 
		RECT rect, int alpha);
	
	void DrawFlipX(D3DXVECTOR2 position, D3DXVECTOR2 anchorPoint, 
		LPDIRECT3DTEXTURE9 texture, RECT rect, 
		D3DXCOLOR transparentColor = BACKGROUND_COLOR);

	void DrawFlipY(D3DXVECTOR2 position, D3DXVECTOR2 anchorPoint, 
		LPDIRECT3DTEXTURE9 texture, RECT rect, 
		D3DXCOLOR transparentColor = BACKGROUND_COLOR);
};

