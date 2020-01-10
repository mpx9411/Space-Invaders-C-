#ifndef INVADER_H
#define INVADER_H
#include "MovingObject.h"
#include "Engine.h"
#include "SDL.h"
#include <memory>

class Invader : public MovingObject {
public:
	static Invader* getInstance(int x, int y, int w, int h,int type);
	void draw() const;
	void tick();
	void kill();
	void hit();
    bool isAlive();
	void collidesWith(GameObject* o);
    int getHealth();

	~Invader();
private:
	Invader (int x, int y, int w, int h,int type);
	SDL_Texture* iTx;
	int varv;
    bool alive = true;
    int right = 20;
    int left = 0;
    int health = 3;
    int type;

};

#endif