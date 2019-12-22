#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"
class Bullet : public GameObject{

public:
	static Bullet* getInstance(int x, int y, int h, int w, const char* path);
	void draw() const;
	void tick();

	~Bullet();

protected:
	Bullet(int x, int y, int h, int w, const char* path);
	SDL_Texture* bTx;

};

#endif