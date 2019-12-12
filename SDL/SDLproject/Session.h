#include <SDL.h>
#include "Engine.h"

class Session
{
public: 
	Session();
	void add(GameObject*);
	void run();
	~Session();
private:
	std::vector<GameObject*> objects;
};

