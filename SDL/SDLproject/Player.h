#ifndef PLAYERH
#define PLAYER_H

#include "GameObject.h"
#include "Engine.h"
#include "SDL.h"
#include <string>
using namespace std;

class Player :	public GameObject{
public:
	static Player* getInstance(int x, int y, int h, int w, const char *path);


	void draw() const;
	void tick();
	void keyPressed(const SDL_Event& e);
     //void keySpace(const SDL_Event& event);

	~Player();
protected:
	Player(int x, int y, int h, int w, const char *path);
    SDL_Texture* pTx;
    bool moving = false;
	void shootB();
};
extern Player* player;

#endif


