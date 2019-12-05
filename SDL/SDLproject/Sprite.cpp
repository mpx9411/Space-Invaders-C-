#include "Sprite.h"
#include "SDL.h"

Sprite::Sprite(SDL_Window &spr) {
	spr_pointer = &spr;
}