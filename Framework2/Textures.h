#include "Debug.h"
#include "Game.h"

#include <d3dx9.h> 
#include <d3d9.h> 
#include <unordered_map>

class Textures {
private: 
	static Textures* __instance; 
	unordered_map<string, LPDIRECT3DTEXTURE9> list_textures; 

public: 

	static Textures* GetInstance();
	Textures();

	void Add(string id, LPCWSTR filePath, D3DCOLOR transparentColor);
	void Clear(); 
};

