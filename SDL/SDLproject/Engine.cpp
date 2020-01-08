#include "Engine.h"
#include "SDL.h"
#include "Player.h"
#include "Invader.h"
#include "SDL_image.h"
#include "Collider.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Invader.h"
#include <memory>
#include <iostream>
#include <cstdlib>

Engine::Engine(){
    int w=900;
    int h=600;
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(
            "GAME", //TITLE
            100, 100, // coordinates on the screen, in pixels, of the window's upper left corner
            w, h, // window's length and height in pixels
            0);
    ren = SDL_CreateRenderer(window, -1, 0);
    SDL_GetWindowSize(window, &width, &height);
}

void Engine::start(const char* background, const int FPS, vector<GameObject*> preLoad) {
	SDL_Surface* bgSurf = IMG_Load(background);
	SDL_Texture* bgTex = SDL_CreateTextureFromSurface(getRen(), bgSurf);
	SDL_FreeSurface(bgSurf);
	Uint32 tickInterval = 100 / FPS;
	SDL_Event e;
	bool quit = false;

	while (!quit) {
			Uint32 time = SDL_GetTicks();
			while (SDL_PollEvent(&e)) {
				nextTick = SDL_GetTicks() + tickInterval;
				if (e.type == SDL_QUIT) {
					quit = true;
				}
				if (e.type == SDL_KEYDOWN) {
					for(GameObject* p: keyPlayers)
						p->keyPressed(e);
				}
			}

			SDL_RenderClear(getRen());
			SDL_RenderCopy(getRen(), bgTex, NULL, NULL);

			

			for (GameObject* c : objects)
				c->tick();
			for (GameObject* c : objects)
				c->draw();

			for (int i = 0; i < objects.size(); i++) {
				for (int j = 1; j < objects.size(); j++) {
					if (i != j && abs(objects[i]->getRect().x - objects[j]->getRect().x) <= 15 && objects[i]->getRect().y == objects[j]->getRect().y)
					objects[i]->collidesWith(objects[j]);
				}
			}

			for (int i = 0; i < removed.size(); ++i) {
				GameObject* rem = removed[i];
				objects.erase(find(objects.begin(), objects.end(), rem));
			}
			removed.clear();

			SDL_RenderPresent(getRen());
			if (tickInterval > (SDL_GetTicks() - time))
			{
				SDL_Delay(tickInterval - (SDL_GetTicks() - time));
			}
		}



	}

void Engine::addPlayers(GameObject* o)
{
	keyPlayers.push_back(o);
	add(o);
}

void Engine::add(GameObject* o) {
	objects.push_back(o);
}

void Engine::remove(GameObject* o) {
	removed.push_back(o);
}

SDL_Renderer* Engine::getRen() const{
	return ren;
}



 Engine :: ~Engine() {
     SDL_DestroyWindow(window);
     SDL_DestroyRenderer(ren);
     SDL_Quit();
}

int Engine::getWinH() const {
    return height;
}

int Engine::getWinW() const {
    return width;
}

Engine eng;