#include <SDL_image.h>
#include "Bullet.h"
#include "Engine.h"

Bullet::Bullet(int x, int y, int h, int w, const char* path) : GameObject{x, y, h, w}{

    //TODO Choose your ABSOLUTE path plz

    /* Elsa */
    //path = "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/bullet.png";

    /* Sina */
    //path = "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/bullet.png";

    /* Magnus */
    //path = "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/bullet.png";

	bTx = IMG_LoadTexture(eng.getRen(), path);
}

Bullet* Bullet::getInstance(int x, int y, int h, int w, const char* path) {
	return new Bullet(x, y, h, w, path);
}

void Bullet::draw() const {
	SDL_Rect pewpew = getRect();
	SDL_RenderCopy(eng.getRen(), bTx, NULL, &pewpew);
}

void Bullet::tick() {
	setXY(getRect().x, getRect().y - 1);
}

Bullet::~Bullet() {
	SDL_DestroyTexture(bTx);
}