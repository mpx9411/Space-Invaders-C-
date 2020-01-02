#ifndef COLLIDER_H
#define COLLIDER_H
#include "GameObject.h"
#include <vector>
#include <utility>
using namespace std;

class Collider
{
public:
	void addObject(GameObject* o, vector<pair<int, int>> c);
	GameObject* setObject(GameObject* o, vector<pair<int, int>> c);
	bool isCollision(GameObject* o, vector<pair<int, int>> c);
	GameObject* getFCollider();
	GameObject* getSCollider();

    virtual ~Collider();

private:
	vector<pair<GameObject*, vector<pair<int, int>>>> activeObjs;
};

extern Collider* collider;

#endif

