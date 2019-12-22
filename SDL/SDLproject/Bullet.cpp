#include <SDL_image.h>
#include "Bullet.h"
#include "Engine.h"

Bullet::Bullet(int x, int y, int h, int w, const char* path) : GameObject{x, y, h, w}{
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
	
}

Bullet::~Bullet() {
	SDL_DestroyTexture(bTx);
}