#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"
#include <memory>
using namespace std;

class Bullet : public GameObject{

public:
	static Bullet* getInstance(int x, int y, int h, int w, const char* path);
	void draw() const;
	void tick();
    bool isOutOfBounds();
	void collidesWith(GameObject* o);
	~Bullet();

protected:
	Bullet(int x, int y, int h, int w, const char* path);
	SDL_Texture* bTx;
	bool out_of_bounds = false;

};

#endif