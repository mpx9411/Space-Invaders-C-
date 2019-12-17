#ifndef ENGINE_H
#define ENGINE_H
#include "SDL.h"



class Engine
{
public:
	Engine();
	~Engine();
	SDL_Renderer* getRen() const;
	void start();
private:
	SDL_Window* window;
	SDL_Renderer* ren;
	bool dontStop;
};

extern Engine eng;

#endif