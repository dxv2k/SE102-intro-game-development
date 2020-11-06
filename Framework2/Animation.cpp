#include "Animation.h"

LPANIMATIONFRAME Animation::GetAnimationFrame()
{
	if (currentFrame != -1)
		return animationFrames[currentFrame];
	return NULL;
}







Animation::~Animation() {

}



