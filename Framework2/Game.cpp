#include "Game.h"

Game* Game::__instance = NULL; 

float Game::dt = 0.0f; 
float Game::timeScale = 1.0f; 

Game* Game::GetInstance()
{
    if (__instance == NULL) __instance = new Game();
    return __instance;
}

Game::~Game()
{
	// Empty on purpose
}

void Game::GameInit() {
    DebugOut(L"[INFO] Load Resource Succesfully!\n");
	Textures::GetInstance()->LoadGameTextures(); 

}

void Game::GameLoop() {
	MSG msg;
	bool done = false;

	float prevTime, currentTime = GetTickCount();
	float delta = 0;
	float tickPerFrame = 1000.0f / MAX_FRAME_RATE;

	// Game Loop
	while (!done)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			if (msg.message == WM_QUIT)
				done = true;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			prevTime = currentTime; 
			currentTime = GetTickCount(); // now
			delta += (currentTime - prevTime);
			dt = delta;

			if (delta >= tickPerFrame) 
			{
				//// Process key
				//auto keyboardManger = CKeyboardManager::GetInstance();
				//keyboardManger->ProcessKeyboard();
				//if (keyboardManger->CheckESCKey() == true)
				//	continue;

				// Call update
				Update();
				Render();

				if (delta > tickPerFrame) delta = 0.0f;
			}
			else {
				Sleep(tickPerFrame - delta);
				delta = tickPerFrame;
			}
		}

	}
}

void Game::GameEnd() {

	//SceneManager::GetInstance()->GetActiveScene()->Unload();
	//TextureManager::GetInstance()->Clear();
	//SpriteManager::GetInstance()->Clear();
	//AnimationManager::GetInstance()->Clear();

	if (spriteHandler != NULL) spriteHandler->Release();
	if (backBuffer != NULL) backBuffer->Release();
	if (d3ddv != NULL) d3ddv->Release();
	if (d3d != NULL) d3d->Release();
	DebugOut(L"[INFO] Release all DirectX \n");
}

void Game::Update() {
	//LPSceneManager sceneManger = SceneManager::GetInstance();
	//LPScene activeScene = sceneManger->GetActiveScene();
	//if (activeScene != NULL)
	//	activeScene->Update(deltaTime);
}

void Game::Render() {
	D3DCOLOR bgColor = D3DCOLOR_XRGB(0, 0, 0);
	//auto activeScene = SceneManager::GetInstance()->GetActiveScene();
	//if (activeScene != nullptr)
	//	bgColor = activeScene->GetBackgroundColor();
	//d3ddv->Clear(0, NULL, D3DCLEAR_TARGET, bgColor, 1.0f, 0);

	if (d3ddv->BeginScene())
	{
		DebugOut(L"Testing empty scene!");
		d3ddv->ColorFill(backBuffer, NULL, D3DCOLOR_XRGB(0,0,0)); 

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		//if (activeScene != nullptr)
		//	activeScene->Render();

		spriteHandler->End();

		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);

}

void Game::InitDirectX(HWND hWnd) {

	LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);

	this->hWnd = hWnd; 

	DebugOut(L"[INFO] Begin Init DirectX \n");

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.hDeviceWindow = hWnd;

	RECT r; 
	GetClientRect(hWnd, &r); 

	d3dpp.BackBufferWidth =  r.right + 1;
	d3dpp.BackBufferHeight =  r.bottom + 1;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT, 
		D3DDEVTYPE_HAL, 
		hWnd, 
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, 
		&d3ddv);

	if (d3ddv == NULL)
	{
		OutputDebugString(L"[ERROR] CreateDevice failed\n");
		return;
	}

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	D3DXCreateSprite(d3ddv, &spriteHandler);

	if (!spriteHandler)
	{
		MessageBox(hWnd, L"Creating sprite handler failed!", L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	DebugOut(L"[INFO] Init DirectX Done \n");
}

void Game::Draw(D3DXVECTOR2 position, D3DXVECTOR2 pointCenter,
	LPDIRECT3DTEXTURE9 texture, RECT rect,
	D3DXCOLOR transcolor) {

	D3DXVECTOR3 pCenter((int)pointCenter.x, (int)pointCenter.y, 0);
	D3DXVECTOR3 pInt((int)(position.x), (int)(position.y), 0); 

	spriteHandler->Draw(
		texture, &rect, 
		&pCenter, &pInt, 
		BACKGROUND_COLOR);
}

void Game::Draw(D3DXVECTOR2 position, 
	LPDIRECT3DTEXTURE9 texture, 
	RECT rect, int alpha)
{

	D3DXVECTOR3 pInt((int)(position.x), (int)(position.y), 0);  
	spriteHandler->Draw(
		texture, &rect, 
		NULL, &pInt, 
		D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Game::DrawFlipX(D3DXVECTOR2 position, 
	D3DXVECTOR2 centerCoordinate,
	LPDIRECT3DTEXTURE9 texture, 
	RECT rect,
	D3DXCOLOR transcolor) {

	D3DXVECTOR3 pCenter((int)centerCoordinate.x, (int)centerCoordinate.y, 0);
	D3DXVECTOR2 pScale(-1, 1);
	D3DXVECTOR3 pInt((int)(position.x), (int)(position.y), 0);
	D3DXMATRIX beforeTransformation, afterTransformation;

	spriteHandler->GetTransform(&beforeTransformation);

	D3DXMatrixTransformation2D(
		&beforeTransformation, &position, //pOut, pScalingCenter 
		0.0f, &pScale, //ScalingRotation, pScaling 
		NULL, 0.0f, //pRotationCenter, Rotation 
		NULL // pTRanslation
	);
	spriteHandler->SetTransform(&afterTransformation);

	spriteHandler->Draw(texture, &rect, 
		&pCenter, &pInt, 
		transcolor);
	spriteHandler->SetTransform(&afterTransformation);
}


void Game::DrawFlipY(D3DXVECTOR2 position, 
	D3DXVECTOR2 centerCoordinate,
	LPDIRECT3DTEXTURE9 texture, 
	RECT rect,
	D3DXCOLOR transparentColor) {

	D3DXVECTOR3 pCenter((int)centerCoordinate.x, (int)centerCoordinate.y, 0);
	D3DXVECTOR2 pScale(1,-1); // Here to flip Y  
	D3DXVECTOR3 pInt((int)(position.x), (int)(position.y), 0);
	D3DXMATRIX beforeTransformation, afterTransformation;

	spriteHandler->GetTransform(&beforeTransformation);

	D3DXMatrixTransformation2D(
		&beforeTransformation, &position, //pOut, pScalingCenter 
		0.0f, &pScale, //ScalingRotation, pScaling 
		NULL, 0.0f, //pRotationCenter, Rotation 
		NULL // pTRanslation
	);
	spriteHandler->SetTransform(&afterTransformation);

	spriteHandler->Draw(texture, &rect, 
		&pCenter, &pInt, 
		transparentColor);

	spriteHandler->SetTransform(&afterTransformation);
}

