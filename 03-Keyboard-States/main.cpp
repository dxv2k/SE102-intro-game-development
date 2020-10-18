/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102
	
	SAMPLE 03 - KEYBOARD AND OBJECT STATE

	This sample illustrates how to:

		1/ Process keyboard input
		2/ Control object state with keyboard events
================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Mario.h"

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"03 - Keyboard States"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(200, 200, 255)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define MAX_FRAME_RATE 90

#define ID_TEX_MARIO 0
#define ID_TEX_NEW_MARIO 1 // testing purpose
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20

CGame *game;
CMario *mario;

class CSampleKeyHander: public CKeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

CSampleKeyHander * keyHandler; 

void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		mario->SetState(MARIO_STATE_JUMP);
		break;
	case DIK_1:
		mario->SetStatus(MARIO_BIG);
		break;
	case DIK_2:
		mario->SetStatus(MARIO_SMALL);
		break;
	case DIK_3:
		mario->SetStatus(MARIO_RACOON);
		break;
	case DIK_4:
		mario->SetStatus(MARIO_FIRE);
		break;
	} 
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	//DebugOutTitle(L"", MAIN_WINDOW_TITLE, KeyCode); 
	//DebugOutTitle(L"", KeyCode); 

}

void CSampleKeyHander::KeyState(BYTE *states)
{
	if (game->IsKeyDown(DIK_D))
		mario->SetState(MARIO_STATE_WALKING_RIGHT);
	else if (game->IsKeyDown(DIK_A))
		mario->SetState(MARIO_STATE_WALKING_LEFT);
	else mario->SetState(MARIO_STATE_IDLE);
}

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

/*
	Load all game resources 
	In this example: load textures, sprites, animations and mario object
*/
void LoadResources()
{
	CTextures * textures = CTextures::GetInstance();

	
	// new textures with left and right states
	textures->Add(ID_TEX_NEW_MARIO, L"textures\\new_mario.png",D3DCOLOR_XRGB(255, 255, 255));

	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	
	LPDIRECT3DTEXTURE9 texMario = textures->Get(ID_TEX_NEW_MARIO);

	/*-----------------------SMALL-MARIO-----------------------------*/
	sprites->Add(MARIO_SMALL_IDLE_LEFT, 174, 87, 193, 107, texMario);
	sprites->Add(MARIO_SMALL_IDLE_RIGHT, 214, 88, 234, 109, texMario);

	sprites->Add(MARIO_SMALL_WALK_LEFT, 133, 88, 153, 108, texMario);
	sprites->Add(MARIO_SMALL_WALK_RIGHT, 253, 88, 275, 110, texMario);

	sprites->Add(MARIO_SMALL_JUMP_LEFT, 53, 86, 78, 107, texMario);
	sprites->Add(MARIO_SMALL_JUMP_RIGHT, 333, 87, 354, 107, texMario);


	/*-----------------------SUPER-MARIO-OR-BIG-MARIO-----------------------*/
	sprites->Add(MARIO_BIG_IDLE_LEFT, 173, 240, 194, 273, texMario);
	sprites->Add(MARIO_BIG_IDLE_RIGHT, 210, 241, 236, 274, texMario);

	sprites->Add(MARIO_BIG_WALK_LEFT, 132, 241, 154, 273, texMario);
	sprites->Add(MARIO_BIG_WALK_LEFT_1, 92, 242, 115, 273, texMario);

	sprites->Add(MARIO_BIG_WALK_RIGHT, 252, 241, 275, 273, texMario);
	sprites->Add(MARIO_BIG_WALK_RIGHT_1, 292, 242, 314, 272, texMario);

	sprites->Add(MARIO_BIG_JUMP_LEFT, 51, 241, 75, 274, texMario);
	sprites->Add(MARIO_BIG_JUMP_RIGHT, 331, 241, 354, 274, texMario);

	sprites->Add(MARIO_BIG_SIT_LEFT, 12, 245, 34, 269, texMario);
	sprites->Add(MARIO_BIG_SIT_RIGHT, 372, 243, 394, 272, texMario);

	/*----------------------------RACOON-MARIO-----------------------------*/
	sprites->Add(MARIO_RACOON_IDLE_LEFT, 171, 441, 197, 476, texMario);
	sprites->Add(MARIO_RACOON_IDLE_RIGHT, 207, 441, 235, 474, texMario);

	sprites->Add(MARIO_RACOON_WALK_LEFT, 145, 441, 172, 474, texMario);
	sprites->Add(MARIO_RACOON_WALK_LEFT_1, 119, 441, 146, 475, texMario);
	sprites->Add(MARIO_RACOON_WALK_LEFT_2, 86, 440, 119, 474, texMario);

	sprites->Add(MARIO_RACOON_WALK_RIGHT, 234, 440, 261, 474, texMario);
	sprites->Add(MARIO_RACOON_WALK_RIGHT_1, 260, 440, 288, 474, texMario);
	sprites->Add(MARIO_RACOON_WALK_RIGHT_2, 289, 440, 320, 474, texMario);

	sprites->Add(MARIO_RACOON_JUMP_LEFT, 46, 440, 78, 474, texMario);
	sprites->Add(MARIO_RACOON_JUMP_RIGHT, 320, 440, 365, 474, texMario);

	sprites->Add(MARIO_RACOON_SIT_LEFT, 10, 440, 37, 474, texMario);
	sprites->Add(MARIO_RACOON_SIT_RIGHT, 367, 443, 398, 474, texMario);

	sprites->Add(MARIO_RACOON_HIT_RIGHT, 353, 480, 373, 513, texMario);
	sprites->Add(MARIO_RACOON_HIT_LEFT, 33, 481, 21, 32, texMario);

	/*----------------------------FIRE-MARIO-----------------------------*/
	sprites->Add(MARIO_FIRE_IDLE_LEFT, 172, 680, 193, 714, texMario);
	sprites->Add(MARIO_FIRE_IDLE_RIGHT, 211, 681, 236, 713, texMario);

	sprites->Add(MARIO_FIRE_WALK_RIGHT, 249, 680, 280, 714, texMario);
	sprites->Add(MARIO_FIRE_WALK_RIGHT_1, 290, 680, 316, 714, texMario);

	sprites->Add(MARIO_FIRE_WALK_LEFT, 131, 680, 155, 714, texMario);
	sprites->Add(MARIO_FIRE_WALK_LEFT_1, 92, 680, 115, 714, texMario);

	sprites->Add(MARIO_FIRE_JUMP_LEFT, 51, 680, 77, 714, texMario);
	sprites->Add(MARIO_FIRE_JUMP_RIGHT, 328, 680, 357, 714, texMario);

	sprites->Add(MARIO_FIRE_SIT_LEFT, 10, 680, 35, 714, texMario);
	sprites->Add(MARIO_FIRE_SIT_RIGHT, 370, 680, 398, 714, texMario);

	sprites->Add(MARIO_FIRE_SHOOT_LEFT, 23, 801, 45, 834, texMario);
	sprites->Add(MARIO_FIRE_SHOOT_LEFT_1, 2, 801, 23, 834, texMario);

	sprites->Add(MARIO_FIRE_SHOOT_RIGHT, 362, 801, 383, 834, texMario);
	sprites->Add(MARIO_FIRE_SHOOT_RIGHT_1, 384, 801, 403, 834, texMario);

	LPANIMATION ani;

	/*-----------------------SMALL-MARIO-----------------------------*/
	ani = new CAnimation(100);
	ani->Add(MARIO_SMALL_IDLE_LEFT);
	animations->Add(MARIO_ANI_IDLE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_SMALL_IDLE_RIGHT);
	animations->Add(MARIO_ANI_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_SMALL_IDLE_LEFT);
	ani->Add(MARIO_SMALL_WALK_LEFT);
	animations->Add(MARIO_ANI_WALKING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_SMALL_IDLE_RIGHT);
	ani->Add(MARIO_SMALL_WALK_RIGHT);
	animations->Add(MARIO_ANI_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_SMALL_JUMP_LEFT);
	animations->Add(MARIO_ANI_JUMP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_SMALL_JUMP_RIGHT);
	animations->Add(MARIO_ANI_JUMP_RIGHT, ani);

	/*-----------------------SUPER-MARIO-OR-BIG-MARIO-----------------------*/
	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_IDLE_LEFT);
	animations->Add(MARIO_BIG_ANI_IDLE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_IDLE_RIGHT);
	animations->Add(MARIO_BIG_ANI_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_IDLE_RIGHT);
	ani->Add(MARIO_BIG_WALK_RIGHT);
	ani->Add(MARIO_BIG_WALK_RIGHT_1);
	ani->Add(MARIO_BIG_WALK_RIGHT);
	animations->Add(MARIO_BIG_ANI_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_IDLE_LEFT);
	ani->Add(MARIO_BIG_WALK_LEFT);
	ani->Add(MARIO_BIG_WALK_LEFT_1);
	ani->Add(MARIO_BIG_WALK_LEFT);
	animations->Add(MARIO_BIG_ANI_WALKING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_JUMP_RIGHT);
	animations->Add(MARIO_BIG_ANI_JUMP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_JUMP_LEFT);
	animations->Add(MARIO_BIG_ANI_JUMP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_SIT_LEFT);
	animations->Add(MARIO_BIG_ANI_SIT_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_BIG_SIT_RIGHT);
	animations->Add(MARIO_BIG_ANI_SIT_RIGHT, ani);

	/*----------------------------RACOON-MARIO-----------------------------*/
	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_IDLE_LEFT);
	animations->Add(MARIO_RACOON_ANI_IDLE_LEFT, ani);

	//mario racoon 
	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_IDLE_RIGHT);
	animations->Add(MARIO_RACOON_ANI_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_WALK_RIGHT);
	ani->Add(MARIO_RACOON_WALK_RIGHT_1);
	ani->Add(MARIO_RACOON_WALK_RIGHT_2);
	ani->Add(MARIO_RACOON_WALK_RIGHT_1);
	animations->Add(MARIO_RACOON_ANI_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_WALK_LEFT);
	ani->Add(MARIO_RACOON_WALK_LEFT_1);
	ani->Add(MARIO_RACOON_WALK_LEFT_2);
	ani->Add(MARIO_RACOON_WALK_LEFT_1);
	animations->Add(MARIO_RACOON_ANI_WALKING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_JUMP_RIGHT);
	animations->Add(MARIO_RACOON_ANI_JUMP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_JUMP_LEFT);
	animations->Add(MARIO_RACOON_ANI_JUMP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_SIT_RIGHT);
	animations->Add(MARIO_RACOON_ANI_SIT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_SIT_LEFT);
	animations->Add(MARIO_RACOON_ANI_SIT_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_WALK_LEFT);
	ani->Add(MARIO_RACOON_HIT_RIGHT);
	ani->Add(MARIO_RACOON_WALK_RIGHT);
	ani->Add(MARIO_RACOON_WALK_LEFT);
	animations->Add(MARIO_RACOON_ANI_HIT_TAIL_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_RACOON_WALK_RIGHT);
	ani->Add(MARIO_RACOON_HIT_RIGHT);
	ani->Add(MARIO_RACOON_WALK_LEFT);
	ani->Add(MARIO_RACOON_WALK_RIGHT);
	animations->Add(MARIO_RACOON_ANI_HIT_TAIL_RIGHT, ani);


	/*----------------------------FIRE-MARIO-----------------------------*/
	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_IDLE_LEFT);
	animations->Add(MARIO_FIRE_ANI_IDLE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_IDLE_RIGHT);
	animations->Add(MARIO_FIRE_ANI_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_IDLE_RIGHT);
	ani->Add(MARIO_FIRE_WALK_RIGHT);
	ani->Add(MARIO_FIRE_WALK_RIGHT_1);
	ani->Add(MARIO_FIRE_WALK_RIGHT);
	animations->Add(MARIO_FIRE_ANI_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_IDLE_LEFT);
	ani->Add(MARIO_FIRE_WALK_LEFT);
	ani->Add(MARIO_FIRE_WALK_LEFT_1);
	ani->Add(MARIO_FIRE_WALK_LEFT);
	animations->Add(MARIO_FIRE_ANI_WALKING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_JUMP_RIGHT);
	animations->Add(MARIO_FIRE_ANI_JUMP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_JUMP_LEFT);
	animations->Add(MARIO_FIRE_ANI_JUMP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_SIT_LEFT);
	animations->Add(MARIO_FIRE_ANI_SIT_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_SIT_RIGHT);
	animations->Add(MARIO_FIRE_ANI_SIT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_SHOOT_RIGHT);
	ani->Add(MARIO_FIRE_SHOOT_RIGHT_1);
	animations->Add(MARIO_FIRE_ANI_SHOOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(MARIO_FIRE_SHOOT_LEFT);
	ani->Add(MARIO_FIRE_SHOOT_LEFT_1);
	animations->Add(MARIO_FIRE_ANI_SHOOT_LEFT, ani);
	/// ////////////////////////////////////////////////////////////////


	mario = new CMario();

	CMario::AddAnimation(MARIO_ANI_IDLE_RIGHT);
	CMario::AddAnimation(MARIO_ANI_IDLE_LEFT);
	CMario::AddAnimation(MARIO_ANI_WALKING_RIGHT);
	CMario::AddAnimation(MARIO_ANI_WALKING_LEFT);
	CMario::AddAnimation(MARIO_ANI_JUMP_RIGHT);
	CMario::AddAnimation(MARIO_ANI_JUMP_LEFT);

	CMario::AddAnimation(MARIO_BIG_ANI_IDLE_RIGHT);
	CMario::AddAnimation(MARIO_BIG_ANI_IDLE_LEFT);
	CMario::AddAnimation(MARIO_BIG_ANI_WALKING_RIGHT);
	CMario::AddAnimation(MARIO_BIG_ANI_WALKING_LEFT);
	CMario::AddAnimation(MARIO_BIG_ANI_JUMP_RIGHT);
	CMario::AddAnimation(MARIO_BIG_ANI_JUMP_LEFT);
	CMario::AddAnimation(MARIO_BIG_ANI_SIT_RIGHT);
	CMario::AddAnimation(MARIO_BIG_ANI_SIT_LEFT);

	CMario::AddAnimation(MARIO_RACOON_ANI_IDLE_RIGHT);
	CMario::AddAnimation(MARIO_RACOON_ANI_IDLE_LEFT);
	CMario::AddAnimation(MARIO_RACOON_ANI_WALKING_RIGHT);
	CMario::AddAnimation(MARIO_RACOON_ANI_WALKING_LEFT);
	CMario::AddAnimation(MARIO_RACOON_ANI_JUMP_RIGHT);
	CMario::AddAnimation(MARIO_RACOON_ANI_JUMP_LEFT);
	CMario::AddAnimation(MARIO_RACOON_ANI_SIT_RIGHT);
	CMario::AddAnimation(MARIO_RACOON_ANI_SIT_LEFT);
	CMario::AddAnimation(MARIO_RACOON_ANI_HIT_TAIL_RIGHT);
	CMario::AddAnimation(MARIO_RACOON_ANI_HIT_TAIL_LEFT);

	CMario::AddAnimation(MARIO_FIRE_ANI_IDLE_RIGHT);
	CMario::AddAnimation(MARIO_FIRE_ANI_IDLE_LEFT);
	CMario::AddAnimation(MARIO_FIRE_ANI_WALKING_RIGHT);
	CMario::AddAnimation(MARIO_FIRE_ANI_WALKING_LEFT);
	CMario::AddAnimation(MARIO_FIRE_ANI_JUMP_RIGHT);
	CMario::AddAnimation(MARIO_FIRE_ANI_JUMP_LEFT);
	CMario::AddAnimation(MARIO_FIRE_ANI_SIT_RIGHT);
	CMario::AddAnimation(MARIO_FIRE_ANI_SIT_LEFT);
	CMario::AddAnimation(MARIO_FIRE_ANI_SHOOT_RIGHT);
	CMario::AddAnimation(MARIO_FIRE_ANI_SHOOT_LEFT);



	mario->SetPosition(0.0f, 100.0f);
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	mario->Update(dt);
}

/*
	Render a frame 
*/
void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		mario->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
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
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			game->ProcessKeyboard();
			
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);	
	}

	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game = CGame::GetInstance();
	game->Init(hWnd);

	keyHandler = new CSampleKeyHander();
	game->InitKeyboard(keyHandler);


	LoadResources();
	Run();

	return 0;
}