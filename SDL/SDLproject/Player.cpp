#include <SDL_image.h>
#include "Player.h"
#include "Engine.h"
#include <iostream>
#include <SDL_mixer.h>
#include "Bullet.h"
#include "Session.h"
using namespace std;

Player::Player(int x, int y, int w, int h, const char *path) : GameObject{x, y, w, h}{

    //TODO Choose your ABSOLUTE path plz (1 / 2)

    /* Sina */
    path = "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/player.png";

    /* Elsa */
    //path ="/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/player.png";

    /* Magnus */
    //path = "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/player.png";

    /**
     * fixing the position of the player and the texture
     */
    SDL_Surface* pSurf = IMG_Load(path);
    setXY((eng.getWinW()-(pSurf->w))/2,(eng.getWinH()-(pSurf->h)*2)-10);

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

/*void Player::shootB() {

	Bullet* bullet = Bullet::getInstance(this->getRect().x + 30, this->getRect().y + 30, 30, 30, "");
	ses.add(bullet);
}*/

Player::~Player() {
    SDL_DestroyTexture(pTx);

}

void Player::keyPressed(const SDL_Event& e) {
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2,4096);

    //TODO Choose your ABSOLUTE path plz (2 / 2)

    /* Sina */
    Mix_Chunk* pew = Mix_LoadWAV("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Sounds/shoot.wav");

    /* Elsa */
    //Mix_Chunk* pew = Mix_LoadWAV("/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Sounds/shoot.wav");

    /* Magnus */
    //Mix_Chunk* pew = Mix_LoadWAV("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Sounds/shoot.wav");

    switch (e.key.keysym.sym) {
        case SDLK_UP:
            setXY(getRect().x,getRect().y-10);

            break;
        case SDLK_DOWN:
            setXY(getRect().x,getRect().y+10);

            break;
        case SDLK_RIGHT:
            //cout << playerRect.h ;
            setXY(getRect().x+10,getRect().y);

            break;
        case SDLK_LEFT:
            setXY(getRect().x-10,getRect().y);

            break;
		case SDLK_SPACE:
            Mix_PlayChannel(-1,pew,0);
			ses.addBullet();
			break;
    }

}

Player* player;

/*void Player::keySpace(const SDL_Event &event) {
    GameObject::keySpace(event);
}*/

//SKRIV DRAW METOD

