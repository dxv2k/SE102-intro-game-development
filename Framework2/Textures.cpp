#include "Textures.h"
#include "Game.h"
#include "Constant.h"

Textures* Textures::__instance = NULL;

Textures* Textures::GetInstance() {
	if (__instance == NULL) __instance = new Textures();
	return __instance;
}

void Textures::LoadGameTextures(){ 
	// Add texture manually 
	AddTextures(MARIO_TEXTURE, L"resources\\Textures\\\mario.png", D3DCOLOR_XRGB(255, 255, 255));
	AddTextures(BBOX_TEXTURE, L"resources\\Textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	AddTextures(ENEMY_TEXTURE, L"resources\\Textures\\enemy.png", D3DCOLOR_XRGB(255, 255, 255));
	AddTextures(MISC_TEXTURE, L"resources\\Textures\\misc.png", D3DCOLOR_XRGB(255, 255, 255));
	AddTextures(MISC_TEXTURE, L"resources\\Textures\\misc.png", D3DCOLOR_XRGB(255, 255, 255));
	AddTextures(FIREBALL_TEXTURE, L"resources\Textures\fireball.png", D3DCOLOR_XRGB(255, 255, 255));
	AddTextures(UI_TEXTURE, L"resources\\Textures\\UI.png", D3DCOLOR_XRGB(255, 255, 255));
	AddTextures(INTRO_TEXTURE, L"resources\\Textures\\intro.png", D3DCOLOR_XRGB(255, 255, 255));

}

void Textures::AddTextures(string id, LPCWSTR filePath, 
	D3DCOLOR transparentColor) {

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);
	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] GetImageInfoFromFile failed: %s\n", filePath);
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();
	LPDIRECT3DTEXTURE9 texture;

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
		return;
	}

	//list_textures[id] = texture;
	list_textures.insert(make_pair(id, texture)); 

	DebugOut(L"[INFO] Texture loaded Ok: id=%s, %s \n", id, filePath);
}

void Textures::LoadTexture(string textureName, string texturePath) {
	AddTextures(textureName, ToLPCWSTR(texturePath),D3DCOLOR_XRGB(255, 255, 255));
}

LPDIRECT3DTEXTURE9 Textures::GetTexture(string id) {
	if (list_textures.find(id) == list_textures.end())
		return nullptr;
	else
		return list_textures.at(id);
}

Textures::~Textures() {
	for (auto t : list_textures) {
		LPDIRECT3DTEXTURE9 tex = t.second;
		if (tex != NULL) tex->Release();
	}
	list_textures.clear(); 
	DebugOut(L"[INFO] Textures CLEARED!!!"); 
}


