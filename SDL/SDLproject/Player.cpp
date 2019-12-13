

#include "Player.h"

Player::Player(int x, int y, int w, int h, string fLoc) :GameObject{x, y, w, h}{
	char* image = new char[fLoc.length() + 1];
	strcpy(image, fLoc.c_str);
	SDL_Surface* pSprite = SDL_LoadBMP(image);
	SDL_Texture* pTex = SDL_CreateTextureFromSurface(eng.getRen(), pSprite);

}

Player* Player::getInstance(int x, int y, int h, int w, string fLoc) {
	return new Player(x, y, h, w, fLoc);
}

//SKRIV DRAW METOD