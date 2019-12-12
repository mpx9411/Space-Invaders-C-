#include "Session.h"
#include <SDL.h>
#include "Engine.h"

Session::Session(){}

void Session::add(GameObject o) {
	objects.push_back(o);
}

void Session::run() {
	SDL_SetRenderDrawColor(eng.getRen, 0, 0, 0, 0);
	bool keepGoing = true;

	while (keepGoing) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_Quit: keepGoing = false; break;
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

		SDL_RenderClear(eng.getRen());
		for (GameObject* o : objects)
			o->draw();
		SDL_RenderPresent(eng.getRen());
	}
}