#include "CollisionBox.h" 

// Default constructor

ColliderBox::ColliderBox() {
	this->sizeBox = D3DXVECTOR2(1.0f, 1.0f); 
	this->gameObj = NULL; 
	this->rigidBody = NULL; 
}

ColliderBox::ColliderBox(D3DXVECTOR2 sb,
	LPGAMEOBJECT &obj,
	LPRIGIDBODY &rb) {
	this->sizeBox = sb; 
	this->gameObj = obj; 
	this->rigidBody = rb; 
}

ColliderBox::~ColliderBox() {
	// Empty on purpose 
}

RectFloat ColliderBox::GetBoundingBox() {
	//if (gameObj->isEnabled() == false 
	//	|| enabled == false)
	//	return RectFloat{0,0,0,0};

	if (gameObj.MonoBehaviour::isEnabled() == false)
		return RectFloat{0,0,0,0};

	//auto pos = GetWorldPosition();
	//RectFloat rect;
	//rect.left = pos.x - boxSize.x * 0.5f;
	//rect.right = pos.x + boxSize.x * 0.5f;
	//rect.top = pos.y - boxSize.y * 0.5f;
	//rect.bottom = pos.y + boxSize.y * 0.5f;
	//return rect;
}

//LPCOLLISIONEVENT SweptAABBX(LPCOLLIDERBOX other) {
//	float sl, st, sr, sb;		// static object bbox
//	float ml, mt, mr, mb;		// moving object bbox
//	float t, nx, ny;
//
//	auto otherBox = other->GetBoundingBox();
//	sl = otherBox.left;
//	st = otherBox.top;
//	sr = otherBox.right;
//	sb = otherBox.bottom;
//
//	// deal with moving object: m speed = original m speed - collide object speed
//	float svx, svy;
//	auto velocity = other->GetGameObject()->GetRigidbody()->GetVelocity();
//	svx = velocity.x;
//	svy = velocity.y;
//
//	float sdx = svx * Game::DeltaTime();
//	float sdy = svy * Game::DeltaTime();
//
//	float dx = this->dvx - sdx;
//	float dy = this->dvy - sdy;
//
//	D3DXVECTOR2 direction;
//
//	SweptAABB(
//		GetBoundingBox(),
//		dx, dy,
//		otherBox,
//		t, direction
//	);
//
//	CollisionEvent* e = new CollisionEvent(t, direction, other);
//	return e;
//}

