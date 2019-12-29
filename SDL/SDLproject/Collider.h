#ifndef COLLIDER_H
#define COLLIDER_H
#include "GameObject.h"

class Collider
{
public:
	void addObject(GameObject* o, vector<pair<int, int>> c);
	GameObject* setObject(GameObject* o, vector<pair<int, int>> c);
	pair<GameObject*, vector<pair<int, int>>> isCollision(GameObject* o, vector<pair<int, int>> c);
private:
	vector<pair<GameObject*, vector<pair<int, int>>>> activeObjs;
};

extern Collider* collider;

#endif

