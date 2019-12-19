#include "Engine.h"
#include "SDL.h"
#include "Player.h"
#include "SDL_image.h"

Engine::Engine(){}

void Engine::start() {

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
		"SPACE INVADER", //TITLE
		10, 25, // coordinates on the screen, in pixels, of the window's upper left corner
		640, 480, // window's length and height in pixels  
		SDL_WINDOW_OPENGL);
	ren = SDL_CreateRenderer(window, -1, 0);
	//TODO Change the string to the right ABSOLUTE path plz
	/* MAGNUS*/

	//SDL_Surface* hSurf = SDL_LoadBMP("C:\\Users\\olema\\Downloads\\6e4.bmp");

	/* SINA */
    SDL_Surface* hSurf = IMG_Load("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/Player.png");

    /* ELSA */
    //SDL_Surface* hSurf = IMG_Load("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/Player.png");

	SDL_Texture* hTex = SDL_CreateTextureFromSurface(ren, hSurf);
	SDL_FreeSurface(hSurf);

    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }

        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, hTex, NULL, NULL);
        SDL_RenderPresent(ren);
    }



}

SDL_Renderer* Engine::getRen() const{
	return ren;
}

 Engine :: ~Engine() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

 Engine eng;