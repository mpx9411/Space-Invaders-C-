#ifndef SESSION_H
#define SESSION_H
#include <SDL.h>
#include "Engine.h"
#include <vector>
#include "GameObject.h"
#include "Bullet.h"

class Session
{
public: 
	Session();
	void add(GameObject* o);
	void remove(GameObject* o);
	void addBullet();
	void run();

	~Session();
private:
	std::vector<GameObject*> objects;
	std::vector<GameObject*> added, removed;
	std::vector<shared_ptr<Bullet>> storage, removedBullets;
	bool collision = false;
	Uint32 tickInterval;
	Uint32 nextTick;
	void handleCollision();


};

extern Session ses;

#endif