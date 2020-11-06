#pragma once
#include <d3dx9.h> 
#include <d3d9.h> 
#include <unordered_map>
#include <string>

#include "Utils.h"

class Textures {
private: 
	static Textures* __instance; 
	unordered_map<string, LPDIRECT3DTEXTURE9> list_textures; 

public: 

	static Textures* GetInstance();
	~Textures(); 
	void LoadGameTextures(); 

	void AddTextures(string id, LPCWSTR filePath, 
		D3DCOLOR transparentColor);
	void LoadTexture(string textureName, string texturePath); 

	LPDIRECT3DTEXTURE9 GetTexture(string textureID); 

	//void Clear(); 

};

