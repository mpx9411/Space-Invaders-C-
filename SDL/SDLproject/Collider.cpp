#include "Collider.h"
#include <utility>

void Collider::addObject(GameObject* o, vector<pair<int, int>> c) {
	activeObjs.push_back(pair<GameObject*, vector<pair<int, int>>>(o, c));
}

GameObject* Collider::setObject(GameObject* o, vector<pair<int, int>> c)
{
	pair<GameObject*, vector<pair<int, int>>> collidingObject;
	try {collidingObject = isCollision(o, c); }
	catch (int e) { 
		addObject(o, c);
	}

	throw collidingObject.first;
}

pair<GameObject*, vector<pair<int, int>>> Collider::isCollision(GameObject* o, vector<pair<int, int>> c)
{
	for (pair<GameObject*, vector<pair<int, int>>> p : activeObjs) {
		if (p.first == o)
			continue;
		for (pair<int, int> nO : c) {
			if(find((p.second).begin(), (p.second).end(), nO) == (p.second).end())
				return p;
		}
	}
	throw 0;
}

Collider* collider;
