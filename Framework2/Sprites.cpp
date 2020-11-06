#include "Game.h"
#include "Sprites.h"
#include "tinyxml.h"
#include "tinystr.h"

Sprites* Sprites::__instance = NULL;

Sprite::Sprite(string id,
	int xPivot, //Use to flip  
	RECT r,
	LPDIRECT3DTEXTURE9 tex,
	D3DXCOLOR transparentColor) {

	this->id = id; 
	this->rect = r; 

	this->width = rect.right - rect.left;
	this->height = rect.bottom - rect.top;
		
	// Multiply by 3 (-1 to -3) because spritesize (height and width) 
	// is reduced by half 
	if (xPivot == -3)
		this->centerCoordinate = D3DXVECTOR2(width * 0.5, height * 0.5);
	else
		this->centerCoordinate = D3DXVECTOR2(xPivot, height * 0.5);

	this->texture = tex; 
	this->transparentColor = transparentColor; 
}

Sprite::~Sprite() {
	//Empty on purpose
}

void Sprite::Draw(
	D3DXVECTOR2 position,
	D3DXVECTOR2 scale,
	float rotation,
	D3DXCOLOR transparentColor) {

	Game* game = Game::GetInstance();
	if (scale.x < 0)
		game->DrawFlipX(position, centerCoordinate, 
			texture, rect, 
			transparentColor);
	else if (scale.y < 0)
		game->DrawFlipY(position, centerCoordinate, 
			texture, rect, 
			transparentColor);
	else
		game->Draw(position, centerCoordinate, 
			texture, rect, 
			transparentColor);
}
Sprites::Sprites() {
	//Empty on purpose
}

Sprites::~Sprites() {
	for (auto x : sprites)
	{
		auto sprite = x.second;
		delete sprite;
	}
	sprites.clear();
}

LPSPRITES Sprites::GetInstance() {
	if (__instance == NULL) {
		__instance = new Sprites();
	}	
	return __instance;
}

LPSPRITE Sprites::GetSprite(string id) {
	//return sprites[id]; 
	return sprites.at(id); 
}

void Sprites::AddSprite(
	string id, RECT rect, 
	LPDIRECT3DTEXTURE9 tex, int xPivot, 
	D3DXCOLOR transcolor)
{
	LPSPRITE s = new Sprite(id, xPivot, rect, tex, transcolor);
	sprites.insert(make_pair(id, s));
}

void Sprites::LoadPreDefinedGameSprites() {
	auto game = Game::GetInstance();
	LoadSprite(MARIO_TEXTURE, "resources/Sprites/MarioDB.xml");
	LoadSprite(ENEMY_TEXTURE, "resources/Sprites/EnemyDB.xml");
	LoadSprite(MISC_TEXTURE, "resources/Sprites/MiscDB.xml");
}

int Sprites::LoadSprite(string textureName, string filePath) {
	DebugOut(L"[INFO] Load Sprite From XML \n");
	OutputDebugStringW(ToLPCWSTR(filePath.c_str()));
	DebugOut(L"\n");
	TiXmlDocument document(filePath.c_str());
	if (!document.LoadFile())
	{
		OutputDebugStringW(ToLPCWSTR(document.ErrorDesc()));
		return false;
	}

	TiXmlElement* root = document.RootElement();
	for (TiXmlElement* texture = root->FirstChildElement(); texture != nullptr; texture = texture->NextSiblingElement())
	{
		string textureID = texture->Attribute("id");
		if (textureID != textureName)
			continue; // keep going because we'using different dataset than intial thought
		LPDIRECT3DTEXTURE9 tex = Textures::GetInstance()->GetTexture(textureID);

		if (tex != nullptr)
			OutputDebugStringW(ToLPCWSTR("Texture id: " + textureID + '\n'));
		else
			return false;
		for (TiXmlElement* node = texture->FirstChildElement(); node != nullptr; node = node->NextSiblingElement())
		{

			string spriteID = node->Attribute("id");
			int left, top, width, height, pivotX, transcolor;
			D3DXCOLOR color;
			node->QueryIntAttribute("left", &left);
			node->QueryIntAttribute("top", &top);
			node->QueryIntAttribute("width", &width);
			node->QueryIntAttribute("height", &height);
			if (node->QueryIntAttribute("xPivot", &pivotX) != TIXML_SUCCESS)
				pivotX = -1;
			pivotX *= 3;
			OutputDebugStringW(ToLPCWSTR(spriteID + ':' + to_string(left) + ':' + to_string(top) + ':' + to_string(width) + ':' + to_string(height) + ':' + to_string(pivotX) + '\n'));

			RECT rect;
			rect.left = left * 3;
			rect.top = top * 3;
			rect.right = (left + width) * 3;
			rect.bottom = (top + height) * 3;

			AddSprite(spriteID, rect, tex, pivotX);
		}
		return true;
	}
}



