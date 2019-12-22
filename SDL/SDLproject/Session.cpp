#include "Session.h"
#include <SDL.h>
#include "SDL_image.h"
#include "Engine.h"
#include "GameObject.h"
using namespace std;

#define FPS 60



Session::Session(){

}

void Session::add(GameObject* o) {
	objects.push_back(o);
    added.push_back(o);
}

void Session::remove(GameObject* o) {	
	removed.push_back(o);
}
void Session::run() {

    /**
	 * Background
	 */


    /* ELSA */
    //SDL_Surface* bgSurf = IMG_Load("/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/background.png");

    /* Sina */
    //SDL_Surface* bgSurf = IMG_Load("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/background.png");


    /* Magnus */
    //SDL_Surface* bgSurf = IMG_Load("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/background.png");


    SDL_Texture* bgTex = SDL_CreateTextureFromSurface(eng.getRen(), bgSurf);
    SDL_FreeSurface(bgSurf);
	Uint32 tickInterval = 1000 / FPS;
    SDL_Event e;
    bool quit = false;
    //bool drag = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
			nextTick = SDL_GetTicks() + tickInterval;
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                for (GameObject* c : objects)
                    c->keyPressed(e);
            }

        }
        SDL_RenderClear(eng.getRen());
        SDL_RenderCopy(eng.getRen(), bgTex, NULL, NULL);
		for (GameObject* c : objects)
			c->tick();
        for (GameObject* c : objects)
            c->draw();
        SDL_RenderPresent(eng.getRen());
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
    }


    /*
    SDL_SetRenderDrawColor(eng.getRen(), 0, 0, 0, 0);
	bool keepGoing = true;

	Uint32 tickInterval = 1000 / FPS;

	while (keepGoing) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: keepGoing = false; break;
			case SDLK_RIGHT:
				for (GameObject* o : objects)
					o->keyRight(event);
				break;
			case SDLK_LEFT:
				for (GameObject* o : objects)
					o->keyLeft(event);
				break;
			case SDLK_SPACE:
				for (GameObject* o : objects)
					o->keySpace(event);

			}
		}

		for (GameObject* o : objects)
			o->tick();

		for (GameObject* o : added) 
			objects.push_back(o);
		added.clear();
		
		for(GameObject* o : removed)
			for(vector<GameObject*>::iterator i = objects.begin(); i != objects.end();)
				if (*i == o) {
					i = objects.erase(i);
				}
				else
					i++;
		removed.clear();

		SDL_RenderClear(eng.getRen());
		for (GameObject* o : objects)
			o->draw();
		SDL_RenderPresent(eng.getRen());

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
     */
}

Session::~Session() {
    for (GameObject* c : objects)
        delete c;
}

Session ses;

