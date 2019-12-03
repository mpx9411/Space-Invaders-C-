#include "Engine.h"
#include "SDL.h"

void Engine::start() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
		"SPACE INVADER", //TITLE
		10, 25, // coordinates on the screen, in pixels, of the window's upper left corner
		640, 480, // window's length and height in pixels  
		SDL_WINDOW_OPENGL);
	SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);
}

void Engine::play() {

}

void Engine::terminate() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}