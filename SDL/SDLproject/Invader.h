#ifndef INVADER_H
#define INVADER_H

#include "GameObject.h"
#include "Engine.h"
#include "SDL.h"
#include <memory>

class Invader : public GameObject {
public:
	static Invader* getInstance(int x, int y, int w, int h,int type);
	void draw() const;
	void tick();
	void kill();
	void hit();
    bool isAlive();
    void reactToCollision();
    int getHealth();


	~Invader();
protected:
	Invader (int x, int y, int w, int h,int type);
	SDL_Texture* iTx;

    bool alive = true;
    int right = 20;
    int left = 0;
    int health = 3;
    int type;

};

#endif