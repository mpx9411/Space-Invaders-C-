#ifndef ENGINE_H
#define ENGINE_H
#include "SDL.h"
#include "GameObject.h"



class Engine
{
public:
	Engine();
	~Engine();
	SDL_Renderer* getRen() const;
	int getWinW() const;
	int getWinH() const;
	void start(const char* background, const int FPS, vector<GameObject*> preLoad);
	void addPlayers(GameObject* o);
	void add(GameObject* o);
	void remove(GameObject* o);

private:
	SDL_Window* window;
	SDL_Renderer* ren;
	bool dontStop;
	int width;
	int height;
	Uint32 tickInterval;
	Uint32 nextTick;
	vector<GameObject*> objects;
	vector<GameObject*> added;
	vector<GameObject*> removed;
	vector<GameObject*> keyPlayers;
	
};

extern Engine eng;

#endif