#include "Session.h"
#include <SDL.h>
#include "SDL_image.h"
#include "Engine.h"
#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include "Invader.h"
#include <memory>
using namespace std;

#define FPS 500



Session::Session(){

}

void Session::add(GameObject* o) {
	objects.push_back(o);
}

void Session::remove(GameObject* o) {	
	removed.push_back(o);
}
void Session::addBullet() {
	std::shared_ptr<Bullet> bullet = Bullet::getInstance(player->getRect().x + 20, player->getRect().y + 30, 30, 30, "");
	Bullet& bObj = *bullet;
	storage.push_back(bullet);
}
void Session::run() {

    /**
	 * Background
	 */

    //TODO Choose your ABSOLUTE path plz

    /* ELSA */
    //SDL_Surface* bgSurf = IMG_Load("/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/background.png");

    /* Sina */
    SDL_Surface* bgSurf = IMG_Load("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/background.png");


    /* Magnus */
    //SDL_Surface* bgSurf = IMG_Load("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/background.png");
    SDL_Texture* bgTex = SDL_CreateTextureFromSurface(eng.getRen(), bgSurf);
    SDL_FreeSurface(bgSurf);
	Uint32 tickInterval = 1000 / FPS;
    SDL_Event e;
    bool quit = false;
    bool once = false;
    while (!quit){

        while(!once) {
            Invader *inv(Invader::getInstance(10, 0, 40, 30));

            added.push_back(inv);
            ses.add(inv);
            once =true;
        }

        Uint32 time = SDL_GetTicks();
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
		/*if ((SDL_GetTicks() / 1000) % 4 == 0){
			for(int i = 0; i <= 10; i++){
				Invader* inv(Invader::getInstance(10 + (60 * i), 0, 40, 30));
				added.push_back(inv);
				ses.add(inv);
			}
		}*/
			
        SDL_RenderClear(eng.getRen());
        SDL_RenderCopy(eng.getRen(), bgTex, NULL, NULL);
		for (GameObject* c : objects){
            //if((SDL_GetTicks() / 1000) % 4 == 0)
		    c->tick();
		}
        for (GameObject* c : objects)
            c->draw();
		for (shared_ptr<Bullet> b : storage) {
			b->tick();
			b->draw();
		}
        SDL_RenderPresent(eng.getRen());
		if (tickInterval > (SDL_GetTicks() - time))
		{
			SDL_Delay(tickInterval - (SDL_GetTicks() - time)); //SDL_Delay pauses the execution.
		}
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

