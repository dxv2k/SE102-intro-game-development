#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include "Utils.h"
#include "Textures.h"

//#include "Singleton.h"
//#include "SingletonManager.h"


#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_FRAME_RATE 120 

using namespace std; 

class Game {
private: 
	static Game* __instance;
	static float dt; // delta time 
	static float timeScale; 

	HWND hWnd; // Window Handle


	// DirectX and helper lib parameters 
	//D3DXCOLOR transparentColor; 

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;		
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	unordered_map<string, unordered_map<string, string>> gameSource;

public: 
	static Game* GetInstance();
	~Game();
	void InitDirectX(HWND hWnd);

	// Basic Game utility  
	void GameInit(); 
	void GameLoop(); 
	void GameEnd(); 

	void Update(); 
	void Render(); 

	// Time Scale, Delta Time 
	static float GetTimeScale() { return timeScale; }
	static void SetTimeScale(float time) { timeScale = time; }

	float GetFixedDeltaTime() { return 20; }
	float GetDeltaTime() { return dt; }

	// DirectX utility 
	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	// Draw utility
	void Draw(D3DXVECTOR2 position, D3DXVECTOR2 pointCenter, 
		LPDIRECT3DTEXTURE9 texture, RECT rect, 
		D3DXCOLOR transcolor = BACKGROUND_COLOR);

	void Draw(D3DXVECTOR2 position, LPDIRECT3DTEXTURE9 texture, 
		RECT rect, int alpha);
	
	void DrawFlipX(D3DXVECTOR2 position, D3DXVECTOR2 centerCoordinate, 
		LPDIRECT3DTEXTURE9 texture, RECT rect, 
		D3DXCOLOR transparentColor = BACKGROUND_COLOR);

	void DrawFlipY(D3DXVECTOR2 position, D3DXVECTOR2 centerCoordinate, 
		LPDIRECT3DTEXTURE9 texture, RECT rect, 
		D3DXCOLOR transparentColor = BACKGROUND_COLOR);

};

