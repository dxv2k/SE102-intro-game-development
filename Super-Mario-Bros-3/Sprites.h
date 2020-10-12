#pragma once

#include <Windows.h> 
#include <d3dx9.h> 
#include <unordered_map>

using namespace std; 

class Sprite {
	int ID; 

	int upper_left_x; 
	int upper_left_y; 
	int bottom_right_x; 
	int bottom_right_y; 
	
	LPDIRECT3DTEXTURE9 texture; 
public: 
	Sprite(	
		int ID, 
		int upper_left_x, 
		int upper_left_y, 
		int bottom_right_x, 
		int bottom_right_y); 
	void Add(int ID, LPCWSTR filePath, D3DCOLOR transparentColor); 
	void Draw(float x, float y); 
};

typedef Sprite* LPSPRITE; 

class Sprites {
	static Sprites* __instance; 
	unordered_map<int, LPSPRITE> sprites; 

public: 


};





