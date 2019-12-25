#ifndef ENGINE_H
#define ENGINE_H
#include "SDL.h"



class Engine
{
public:
	Engine();
	~Engine();
	SDL_Renderer* getRen() const;
	int getWinW() const;
	int getWinH() const;
	void start();
private:
	SDL_Window* window;
	SDL_Renderer* ren;
	bool dontStop;
	int width;
	int height;
};

extern Engine eng;

#endif