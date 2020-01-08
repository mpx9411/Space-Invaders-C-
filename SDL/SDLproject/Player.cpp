#include <SDL_image.h>
#include "Player.h"
#include "Engine.h"
#include <iostream>
#include <SDL_mixer.h>
#include "Bullet.h"
using namespace std;

Player::Player(int x, int y, int w, int h, const char *path) : MovingObject{x, y, w, h}{

    //TODO Choose your ABSOLUTE path plz (1 / 2)

    /* Sina */
    //path = "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/player.png";

    /* Elsa */
    //path ="/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/player.png";

    /* Magnus */
    path = "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/player.png";

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

Player::~Player() {
    SDL_DestroyTexture(pTx);

}

void Player::keyPressed(const SDL_Event& e) {
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2,4096);

    //TODO Choose your ABSOLUTE path plz (2 / 2)

    /* Sina */
    //Mix_Chunk* pew = Mix_LoadWAV("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Sounds/shoot.wav");

    /* Elsa */
    //Mix_Chunk* pew = Mix_LoadWAV("/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Sounds/shoot.wav");

    /* Magnus */
    Mix_Chunk* pew = Mix_LoadWAV("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Sounds/shoot.wav");

    switch (e.key.keysym.sym) {
        case SDLK_RIGHT: {

            int playerX = getRect().x + 10;
            int playerY = getRect().y;
            if (!(playerX > (eng.getWinW()-getRect().w)))
                setXY(playerX, playerY);
			break;
        }
        case SDLK_LEFT: {
            int playerX = getRect().x - 10;
            int playerY = getRect().y;
            if(!(playerX<0))
                setXY(playerX,playerY);
            break;
        }
		case SDLK_SPACE:
            Mix_PlayChannel(-1,pew,0);
			eng.add(Bullet::getInstance(player->getRect().x + 8, player->getRect().y, 30, 30, ""));
			break;
    }
}

void Player::collidesWith(GameObject* o){}

Player* player;

