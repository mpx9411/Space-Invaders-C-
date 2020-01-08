#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
#include <vector>
#include <utility>
using namespace std;

class GameObject
{
public:
	virtual void keyPressed(const SDL_Event& event){}


	virtual ~GameObject(){}
	SDL_Rect getRect() const { return rect; }
	virtual void draw() const = 0;
	virtual void tick() = 0;
    const GameObject& operator=(const GameObject&) = delete;
	virtual void collidesWith(GameObject* collidingObject) = 0;
	//vector<pair<int, int>> collisionSurface();

protected:
	GameObject(const GameObject&) = delete;
	GameObject(int x, int y, int w, int h);
	void setWH(int w, int h);
	SDL_Rect rect;
private:
	
};

#endif


