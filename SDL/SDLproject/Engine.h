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
	void terminate();
private:
	SDL_Window* window;
	bool dontStop;
	void gameLoop();
};

extern Engine eng;

#endif