#include <SDL_image.h>
#include "Player.h"
#include "Engine.h"
#include <iostream>
#include "Bullet.h"
#include "Session.h"
using namespace std;

Player::Player(int x, int y, int w, int h, const char *path) : GameObject{x, y, w, h}{

    /* Sina */
    //path = "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/player.png";

    /* Elsa */
    //path ="/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/player.png";
	pTx = IMG_LoadTexture(eng.getRen(),path);

}

Player* Player::getInstance(int x, int y, int w, int h, const char *path) {
	return new Player(x, y, w, h, path);
}

void Player::draw() const {
    SDL_Rect toffla = getRect();
    SDL_RenderCopy(eng.getRen(),pTx,NULL,&toffla);
}

void Player::tick() {

}

void Player::shootB() {
	Bullet* bullet = Bullet::getInstance(this->getRect().x + 30, this->getRect().y + 30, 30, 30, "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/bullet.png");
	ses.add(bullet);
}

Player::~Player() {
    SDL_DestroyTexture(pTx);

}

void Player::keyPressed(const SDL_Event& e) {
    SDL_Rect playerRect = getRect();
    //cout<< playerRect.h;
    switch (e.key.keysym.sym) {
        case SDLK_UP:
            setXY(getRect().x,getRect().y-10);
            //cout<< GameObject::getRect().y << "\n";
            break;
        case SDLK_DOWN:
            setXY(getRect().x,getRect().y+10);
            //cout<< GameObject::getRect().y << "\n";
            break;
        case SDLK_RIGHT:
            //cout << playerRect.h ;
            setXY(getRect().x+10,getRect().y);
           // cout << " : " << playerRect.h << "\n" ;
            break;
        case SDLK_LEFT:
            setXY(getRect().x-10,getRect().y);
            //cout << "Change x-";
            break;
		case SDLK_SPACE:
			shootB();
			break;
    }
    //cout<<"pos för rect. Y: " << playerRect.y << ", X: " << playerRect.x;
}



/*void Player::keySpace(const SDL_Event &event) {
    GameObject::keySpace(event);
}*/

//SKRIV DRAW METOD

