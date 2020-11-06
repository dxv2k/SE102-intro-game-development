#include <d3d9.h> 
#include <d3dx9.h> 
#include <string>  

#define TRANSPARENT_COLOR D3DCOLOR_XRGB(255, 255, 255)

using namespace std; 

class Sprite {
	string id;
	RECT r;

	// width and heigth used to calculated bottom right
	int width;
	int height;

	D3DXVECTOR2 pointCenter;
	LPDIRECT3DTEXTURE9 texture;
	D3DXCOLOR transparentColor;

public:
	Sprite(
		string id,
		//int xPitvot, 
		RECT r,
		LPDIRECT3DTEXTURE9 tex,
		D3DXCOLOR transparentColor
	);

	void Draw();

	RECT GetRect();
	void SetRect(RECT r);

	int GetWidth() { return width; }
	int GetHeight() { return height; }

	void SetWidth(int newWidth) { this->width = newWidth; }
	void SetHeight(int newHeight) { this->height = newHeight; }

}; 

typedef Sprite* LPSPrite; 






