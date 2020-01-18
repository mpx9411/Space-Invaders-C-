#include "MovingObject.h"


MovingObject::MovingObject(int x, int y, int w, int h) : GameObject{x, y, w, h}
{

}

void MovingObject::setXY(int x, int y)
{
	rect.x = x;
	rect.y = y;
}