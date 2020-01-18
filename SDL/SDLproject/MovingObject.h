#pragma once
#include "GameObject.h"
class MovingObject :
	public GameObject
{
protected:
	void setXY(int x, int y);
	MovingObject(int x, int y, int w, int h);
};

