#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> 

#include "Game.h" 
#include "Textures.h"

class GameObject {
protected: 
	int id; 
	DWORD dt; 
	bool enable; 

public: 
	GameObject(); 
	~GameObject(); 

	virtual void Update(DWORD dt); 
	virtual void Render(); 


};






