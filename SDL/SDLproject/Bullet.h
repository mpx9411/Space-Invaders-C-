#ifndef BULLET_H
#define BULLET_H
#include "MovingObject.h"
#include <memory>
using namespace std;

class Bullet : public MovingObject{

public:
	static Bullet* getInstance(int x, int y, int h, int w, const char* path);
	void draw() const;
	void tick();
	void collidesWith(GameObject* o);
	~Bullet();

protected:
	Bullet(int x, int y, int h, int w, const char* path);
	
private:
	bool out_of_bounds = false;
	bool isOutOfBounds();
	SDL_Texture* bTx;
};

#endif