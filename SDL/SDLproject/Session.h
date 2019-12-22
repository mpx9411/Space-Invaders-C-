#ifndef SESSION_H
#define SESSION_H
#include <SDL.h>
#include "Engine.h"
#include <vector>
#include "GameObject.h"

class Session
{
public: 
	Session();
	void add(GameObject* o);
	void remove(GameObject* o);
	void run();
	~Session();
private:
	std::vector<GameObject*> objects;
	std::vector<GameObject*> added, removed;
};

extern Session ses;

#endif