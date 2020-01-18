#pragma once
#include "GameObject.h"
class StillObject :
	public GameObject
{
protected:
	StillObject(int x, int y, int w, int h);

private:
	SDL_Rect rect;
};

