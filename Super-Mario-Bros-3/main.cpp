#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

#include "Game.h" 
#include "GameObject.h" 
#include "Debug.h "
#include "Mario.h"
#include "Textures.h"
#include "Sprites.h"
#include "KeyEventHandler.h"

#define WINDOW_CLASS_NAME L"Super Mario Bros 3" 
#define WINDOW_TITLE L"Super Mario Bros 3" 
#define WINDOW_ICON_PATH L"mario.ico"
#define MAIN_WINDOW_TITLE L"Super Mario Bros 3"

#define D3DCOLOR_WHITE D3DCOLOR_XRGB(255, 255, 255)
#define BACKGROUND_COLOR D3DCOLOR_XRGB(0,0,0) 

#define WINDOW_WIDTH 640 
#define WINDOW_HEIGHT 480 
#define MAX_FRAME_RATE 120 

HWND hWnd = 0; 

Game* game; 
Mario* mario; 

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void KeyEventHandler::OnKeyDown(int KeyCode) {
	switch (KeyCode)
	{
	case DIK_SPACE: 
		mario->SetState(MARIO_STATE_JUMP); 
	}
}
void KeyEventHandler::OnKeyUp(int KeyCode) {
	// Currently nothing here
}

void KeyEventHandler::KeyState(BYTE* states) {
	if (game->IsKeyDown(DIK_RIGHT))
		mario->SetState(MARIO_STATE_WALKING_RIGHT); 
	else if (game->IsKeyDown(DIK_LEFT))
		mario->SetState(MARIO_STATE_WALKING_LEFT); 
	else 
		mario->SetState(MARIO_STATE_IDLE); 
}


void Update(DWORD dt) {
	mario->Update(dt);
}

// Render a frame
void Render() {

	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		//Game::GetInstance()->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight) {
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);


	if (!hWnd)
	{
		DWORD ErrCode = GetLastError();
		OutputDebugString(L"[ERROR] CreateWindow failed!");
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	SetDebugWindow(hWnd);
	return hWnd;
}

int Run() {
	MSG msg; 
	int done = 0; 
	DWORD frameStart = GetTickCount(); 
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE; 
	while (!done) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				done = 1; 
			}
		}
		DWORD now = GetTickCount(); 

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart; 
		if (dt >= tickPerFrame) {
			frameStart = now;
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt); 
	}
	return 1;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, WINDOW_WIDTH, WINDOW_HEIGHT); 
	return 0; 

}

void LoadResources() {

}

