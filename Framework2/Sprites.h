#pragma once
#include <d3d9.h> 
#include <d3dx9.h> 
#include <string>  
#include <unordered_map>

#include "Utils.h" 
#include "Constant.h"

using namespace std; 

class Sprite; 
typedef Sprite* LPSPRITE; 
class Sprite {
	string id; //ID is the same in database 				
	RECT rect;
	
	// Sprite Width and Heigth receive from database 
	int width;
	int height;

	// DirectX 
	D3DXVECTOR2 centerCoordinate;
	LPDIRECT3DTEXTURE9 texture;
	D3DXCOLOR transparentColor;
public:
	Sprite(string id, 
		int xPivot, //Use to flip  
		RECT r, 
		LPDIRECT3DTEXTURE9 tex, 
		D3DXCOLOR transparentColor = D3DCOLOR_XRGB(255, 0, 255)); 
	~Sprite(); 

	void Draw(
		D3DXVECTOR2 position, 
		D3DXVECTOR2 scale, 
		float rotation, 
		D3DXCOLOR transparentColor = D3DXCOLOR(255, 255, 255, 255));

	RECT GetRect() { return rect;  }
	void SetRect(RECT r) { this->rect = r;  }

	int GetWidth() { return width; }
	int GetHeight() { return height; }

	void SetWidth(int newWidth) { this->width = newWidth; }
	void SetHeight(int newHeight) { this->height = newHeight; }

}; 


// Sprite Management  
class Sprites; 
typedef Sprites* LPSPRITES; 

class Sprites {
	static LPSPRITES __instance; 
	unordered_map<string, LPSPRITE> sprites; 
public: 
	Sprites(); 
	~Sprites(); 
	static LPSPRITES GetInstance(); 
	LPSPRITE GetSprite(string id); 

	void LoadPreDefinedGameSprites(); 

	void AddSprite(
		string id, RECT rect,
		LPDIRECT3DTEXTURE9 tex, int xPivot,
		D3DXCOLOR transparentColor = D3DCOLOR_XRGB(255, 0, 255));
	int LoadSprite(string textureName, string filePath); 

}; 





