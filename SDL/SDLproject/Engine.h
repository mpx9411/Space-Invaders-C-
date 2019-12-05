#pragma once
#include "SDL.h"

class Engine
{
public:
	SDL_Window* window;
	void start();
	void terminate();
};

