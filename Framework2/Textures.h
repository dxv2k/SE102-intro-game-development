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
	//TODO: Complete textures manager
	static Textures* GetInstance();
	~Textures(); 

	// LoadGameTextures() is not a universal function  
	// Use specially to load Super Mario Bros 3 texture resources 
	void LoadGameTextures(); 

	void AddTextures(string id, LPCWSTR filePath, 
		D3DCOLOR transparentColor);
	void LoadTexture(string textureName, string texturePath); 

	LPDIRECT3DTEXTURE9 GetTexture(string textureID); 

	//void Clear(); 

};

