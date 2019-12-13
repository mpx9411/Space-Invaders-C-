#include "Session.h"
#include <SDL.h>
#include "Engine.h"
#include "GameObject.h"
using namespace std;

#define FPS 60

Session::Session(){}

void Session::add(GameObject* o) {
	added.push_back(o);
}

void Session::remove(GameObject* o) {	
	removed.push_back(o);
}
void Session::run() {
	SDL_SetRenderDrawColor(eng.getRen, 0, 0, 0, 0);
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
}