#include "Collider.h"
#include <utility>
#include <algorithm>
using namespace std;

GameObject* firstCollider;
GameObject* secondCollider;

GameObject* Collider::getFCollider(){
	return firstCollider;
}

GameObject* Collider::getSCollider() {
	return secondCollider;
}

void Collider::addObject(GameObject* o, vector<pair<int, int>> c) {
	activeObjs.push_back(pair<GameObject*, vector<pair<int, int>>>(o, c));
}

//GameObject* Collider::setObject(GameObject* o, vector<pair<int, int>> c)
//{
	/*pair<GameObject*, vector<pair<int, int>>> collidingObject;
	try {collidingObject = isCollision(o, c); }
	catch (int e) { 
		addObject(o, c);
	}

	throw collidingObject.first;*/
//}

bool Collider::isCollision(GameObject* f, GameObject* s)
{
}

Collider::~Collider() {
    activeObjs.clear();
}

Collider* collider;
