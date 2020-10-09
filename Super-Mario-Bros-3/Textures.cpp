#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>

#include "Debug.h"
#include "Game.h"
#include "Textures.h"

Textures* Textures::__instance = NULL; 

Textures::Textures() 
{ 
	// Leave empty on purpose 
}

Textures* Textures::GetInstance() {
	if (__instance == NULL)
		__instance = new Textures(); 
	return __instance; 
}








