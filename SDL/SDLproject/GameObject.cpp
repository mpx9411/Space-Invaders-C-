#include "GameObject.h"

GameObject::GameObject(int x, int y, int w, int h) :rect{ x, y, w, h } {
	//HäR ANGES LOCATION
}

void GameObject::setWH(int w, int h) {
    rect.w = w;
    rect.h = h;
}

void GameObject::setXY(int x, int y) {
    rect.x = x;
    rect.y = y;
}
