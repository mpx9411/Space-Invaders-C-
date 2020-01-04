#include "Collider.h"
#include <vector>
#include <utility>
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

/*
vector<pair<int, int>> GameObject::collisionSurface()
{
	for (int i = rect.x; i <= rect.x + rect.w; i++) {
		coor.push_back(pair<int, int>(i, rect.y));
		coor.push_back(pair<int, int>(i, rect.y - rect.h));
	}
	for (int i = rect.y; i >= rect.y - rect.h; i--) {
		coor.push_back(pair<int, int>(rect.x, i));
		coor.push_back(pair<int, int>(rect.x + rect.w, i));
	}

	return coor;
}
 */
