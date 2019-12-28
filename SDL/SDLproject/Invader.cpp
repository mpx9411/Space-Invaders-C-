#include "Invader.h"
#include "SDL_image.h"
#include "Engine.h"




Invader::Invader(int x, int y, int w, int h) : GameObject{x, y, w, h} {
	
	iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/invader.png");
	setXY(x, y);

}

Invader* Invader::getInstance(int x, int y, int w, int h) {
	return new Invader(x, y, w, h);
}

void Invader::draw() const {
	SDL_Rect iRect = getRect();
	SDL_RenderCopy(eng.getRen(), iTx, NULL, &iRect);
}

void Invader::tick() {

}

Invader::~Invader() {
	SDL_DestroyTexture(iTx);
}