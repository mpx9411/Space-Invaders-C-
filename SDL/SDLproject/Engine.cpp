#include "Engine.h"
#include "SDL.h"
#include "Player.h"
#include "Invader.h"
#include "SDL_image.h"
#include "Collider.h"
#include "Session.h"
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
	bool once = false;

	while (!quit) {
		
		vector<Invader*> v1;
		vector<GameObject*> added;
		while (!once) {

			for (int i = 0; i <= 30; i++) {
				if (i % 3 == 0) {
					Invader* inv(Invader::getInstance(10 + (i * 50), 0, 30, 30, 1));
					v1.push_back(inv);

				}if (i % 3 == 1) {
					Invader* inv(Invader::getInstance((i * 50), 31, 30, 30, 2));
					v1.push_back(inv);
				}if (i % 3 == 2) {
					Invader* inv(Invader::getInstance((i * 50), 62, 30, 30, 3));
					v1.push_back(inv);
				}
			}
			Invader* inv3(Invader::getInstance(10, 62, 30, 30, 3));
			v1.push_back(inv3);

			for (Invader* inv : v1) {
				eng.add(inv);
			}

			once = true;
		}
			Uint32 time = SDL_GetTicks();
			while (SDL_PollEvent(&e)) {
				nextTick = SDL_GetTicks() + tickInterval;
				if (e.type == SDL_QUIT) {
					quit = true;
				}
				if (e.type == SDL_KEYDOWN) {
					for (GameObject* c : objects)
						c->keyPressed(e);
				}
			}

			SDL_RenderClear(getRen());
			SDL_RenderCopy(getRen(), bgTex, NULL, NULL);

			for (int i = 0; i < objects.size() - 1; i++) {
				for (int j = 1; j < objects.size(); j++) {
					if (abs(-15 <= objects[i]->getRect().x - objects[j]->getRect().x) <= 15 && -15 <= objects[i]->getRect().y - objects[j]->getRect().y <= 15);
					objects[i]->collidesWith(objects[j]);
				}
			}

			for (GameObject* c : objects) {
				c->tick();
			}
			for (GameObject* c : objects)
				c->draw();

			for (size_t i = 0; i < removed.size(); ++i) {
				delete removed[i];
			}
			removed.clear();

			SDL_RenderPresent(getRen());
			if (tickInterval > (SDL_GetTicks() - time))
			{
				SDL_Delay(tickInterval - (SDL_GetTicks() - time));
			}
		}



	}

void Engine::add(GameObject* o) {
	objects.push_back(o);
	added.push_back(o);
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