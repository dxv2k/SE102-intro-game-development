#pragma once
#include <string>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>

class Transform {
	/*
	Position, local position, scale and rotation of an GameObject
	It's used to store and manipulate the position, scale and rotation of every GameObject
	and inhertied object of Transform class
	*/

public:
	D3DXVECTOR2 position; //World position 
	
	// localPosition: or relative position to the parent transform 
	D3DXVECTOR2 localPosition; 

	D3DXVECTOR2 scale;
	float rotationAngle; // Receive with Degree but when Draw must convert into Radian 

	// NOTICE: No idea what the hell I have written below
	Transform(
		D3DXVECTOR2 position = D3DXVECTOR2(0.0f,0.0f),
		D3DXVECTOR2 localPosition = D3DXVECTOR2(0.0f,0.0f),
		D3DXVECTOR2 scale = D3DXVECTOR2(1.0f,1.0f),
		float rotationAngle = 0.0f
	);
	~Transform();

	// Translate: translate the object by multiply current position (world position) 
	// to distance. Useful for Camera, update moving object with FixedUpdate() 
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