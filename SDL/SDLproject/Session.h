#ifndef SESSION_H
#define SESSION_H
#include <SDL.h>
#include "Engine.h"
#include <vector>

class Session
{
public: 
	void add(GameObject* o);
	void remove(GameObject* o);
	void run();
private:
	std::vector<GameObject*> objects;
	std::vector<GameObject*> added, removed;
};

#endif