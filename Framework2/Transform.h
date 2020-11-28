#pragma once
#include <string>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>

#include "Utils.h" 
using namespace std; 

class Transform {
	/*
	Position, local position, scale and rotation of an GameObject
	It's used to store and manipulate the position, scale and rotation of every GameObject
	and inhertied object of Transform class
	*/

public:
	D3DXVECTOR2 position; //World position 
	
	// localPosition: or relative position to the parent transform 
	// NOTICE: localPosition IS NOT COMPLETE, not recommend to use 
	D3DXVECTOR2 localPosition; 

	D3DXVECTOR2 scale;
	float rotationAngle; // Receive with Degree but when Draw must convert into Radian 

	Transform(); 
	Transform(
		D3DXVECTOR2 position,
		D3DXVECTOR2 localPosition,
		D3DXVECTOR2 scale,
		float rotationAngle); 
	~Transform();

	// NOTICE: No idea what the hell I have written below
	//Transform(
	//	D3DXVECTOR2 position = D3DXVECTOR2(0.0f,0.0f),
	//	D3DXVECTOR2 localPosition = D3DXVECTOR2(0.0f,0.0f),
	//	D3DXVECTOR2 scale = D3DXVECTOR2(1.0f,1.0f),
	//	float rotationAngle = 0.0f
	//);

	// Create translation by replace old position with new position   
	// NOTICE: still have no idea how to get translation out 
	// Ref: https://docs.unity3d.com/ScriptReference/Transform.Translate.html
	void Translate(D3DXVECTOR2 newCoordinate);

	void SetPosition(D3DXVECTOR2 newPos) { this->position = newPos; }
	D3DXVECTOR2 GetPosition() { return position; }

	void SetLocalPosition(D3DXVECTOR2 newPos) { this->localPosition = newPos; }
	D3DXVECTOR2 GetLocalPosition() { return localPosition; }

	void SetScale(D3DXVECTOR2 newScale) { this->scale = newScale; }
	D3DXVECTOR2 GetScale() { return scale; }
		
	void SetRotationAngle(float newAngle) { this->rotationAngle = newAngle; }
	float GetRotationAngle() { return rotationAngle; }

};