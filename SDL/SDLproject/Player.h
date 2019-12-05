#pragma once
#include "Sprite.h"
#include "SDL.h"
class Player :	public Sprite{
public:
	Player getInstance(int x);
	void draw() const;
	void tick();

};

