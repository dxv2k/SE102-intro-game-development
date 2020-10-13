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
	void Draw(float x, float y); 
};

typedef Sprite* LPSPRITE; 

class Sprites {
	static Sprites* __instance; 
	unordered_map<int, LPSPRITE> sprites; 

public: 

	/*
		In this version, I'm trying to get the code up and running as fast as possible. 
		So like this Add() function below here and how its manage Sprites is not very good
		TODO: REMEMBER Add() and manage sprites is not very effective!  
	*/
	void Add(
		int id, 
		int upper_left_x, 
		int upper_left_y, 
		int bottom_right_x, 
		int bottom_right_y, 
		LPDIRECT3DTEXTURE9 tex);
	LPSPRITE Get(int id);

	static Sprites * GetInstance();
};
