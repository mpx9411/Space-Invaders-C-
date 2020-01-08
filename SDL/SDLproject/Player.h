#ifndef PLAYERH
#define PLAYER_H

#include "MovingObject.h"
#include "Engine.h"
#include "SDL.h"
#include <string>
using namespace std;

class Player :	public MovingObject{
public:
	static Player* getInstance(int x, int y, int h, int w, const char *path);


	void draw() const;
	void tick();
	void keyPressed(const SDL_Event& e);
	void collidesWith(GameObject* o);
	~Player();

private:
	Player(int x, int y, int h, int w, const char *path);
    SDL_Texture* pTx;
    bool moving = false;
};
extern Player* player;

#endif


