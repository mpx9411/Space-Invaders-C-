#ifndef PLAYER.H
#define PLAYER.H
#include "GameObject.h"
#include "Engine.h"
#include "SDL.h"
#include <string>
using namespace std;

class Player :	public GameObject{
public:
	Player* getInstance(int x, int y, int h, int w, string fLoc);
	void draw() const;
	void tick();
	~Player();
protected:
	Player(int x, int y, int h, int w, string fLoc);
};

#endif


