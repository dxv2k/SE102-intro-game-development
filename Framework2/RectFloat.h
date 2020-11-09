// Why does this exists? 
// -> Because Rect in Windows.h is long dtype 
// which is not suitable for updating world and GameObj
struct RectFloat {
	float left, top, right, bottom; 
};

