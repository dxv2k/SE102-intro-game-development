#include <unordered_map>
#include  <d3dx9.h> 

using namespace std; 

// Manage texture database 
class Textures {
	static Textures* __instance; 
	unordered_map<int, LPDIRECT3DTEXTURE9> textures;
public: 
	Textures(); 
	/*
		Future implementation of Add() will replace manually add id   	
		to load *.json file for the ease of work load
	*/
	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor); 
	LPDIRECT3DTEXTURE9 Get(unsigned int i);
	static Textures * GetInstance();

};









