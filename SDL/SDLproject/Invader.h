#ifndef INVADER_H
#define INVADER_H

#include "GameObject.h"
#include "Engine.h"
#include "SDL.h"
#include <memory>

class Invader : public GameObject {
public:
	static Invader* getInstance(int x, int y, int w, int h);
	void draw() const;
	void tick();

	~Invader();
protected:
	Invader (int x, int y, int w, int h);
	SDL_Texture* iTx;
};

#endif