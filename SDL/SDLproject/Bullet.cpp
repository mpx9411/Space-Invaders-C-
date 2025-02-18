#include <SDL_image.h>
#include "Bullet.h"
#include "Engine.h"
#include <memory>
#include <iostream>

using namespace std;

Bullet::Bullet(int x, int y, int h, int w, const char* path) : GameObject{x, y, h, w}{

    //TODO Choose your ABSOLUTE path plz

    /* Elsa */
    path = "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/bullet.png";

    /* Sina */
    //path = "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/bullet.png";

    /* Magnus */
//    path = "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/bullet.png";

	bTx = IMG_LoadTexture(eng.getRen(), path);
}

shared_ptr<Bullet> Bullet::getInstance(int x, int y, int h, int w, const char* path) {
	shared_ptr<Bullet> bullet (new Bullet(x, y, h, w, path));
	return bullet;
}

void Bullet::draw() const {
    if(!out_of_bounds) {
        SDL_Rect pewpew = getRect();
        SDL_RenderCopy(eng.getRen(), bTx, NULL, &pewpew);
    }
}

void Bullet::tick() {
    int bulletY = getRect().y -1;
    if(bulletY>0-(getRect().h))
	setXY(getRect().x, bulletY);

    else{
        cout<<"out";
        out_of_bounds= true;

    }
}

Bullet::~Bullet() {
	SDL_DestroyTexture(bTx);
}

bool Bullet::isOutOfBounds(){
    return out_of_bounds;
}