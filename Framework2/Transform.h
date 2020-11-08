#pragma once
#include <string>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>

class Transform {
	/*
	Position, scale and rotation of an GameObject
	It's used to store and manipulate the positino, scale and rotation of every GameObject
	*/

	//D3DXVECTOR2 position; //World position 
	//D3DXVECTOR2 localPosition; 

	//D3DXVECTOR2 scale;
	//float rotationAngle; // Receive with Degree but when Draw must convert into Radian 

public:
	
	D3DXVECTOR2 position; //World position 
	D3DXVECTOR2 localPosition; 

	D3DXVECTOR2 scale;
	float rotationAngle; // Receive with Degree but when Draw must convert into Radian 

	Transform(
		D3DXVECTOR2 position = D3DXVECTOR2(0.0f,0.0f),
		D3DXVECTOR2 scale = D3DXVECTOR2(1.0f,1.0f),
		float rotationAngle = 0.0f
	);
	~Transform();
	
	void SetPosition(D3DXVECTOR2 newPos) { this->position = newPos; }
	D3DXVECTOR2 GetPosition() { return position; }

	void SetLocalPosition(D3DXVECTOR2 newPos) { this->localPosition = newPos; }
	D3DXVECTOR2 GetLocalPosition() { return localPosition; }

	void SetScale(D3DXVECTOR2 newScale) { this->scale = newScale; }
	D3DXVECTOR2 GetScale() { return scale; }
		
	void SetRotationAngle(float newAngle) { this->rotationAngle = newAngle; }
	float GetRotationAngle() { return rotationAngle; }

};