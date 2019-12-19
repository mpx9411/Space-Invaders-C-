#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
class GameObject
{
public:
	virtual void keyPressed(const SDL_Event& event){}


	virtual ~GameObject(){}

	SDL_Rect getRect() const { return rect; }
	virtual void draw() const = 0;
	virtual void tick() = 0;
    GameObject(const GameObject&) = delete;
    const GameObject& operator=(const GameObject&) = delete;

protected:
	GameObject(int x, int y, int w, int h);
	void setWH(int w, int h);

private:
	SDL_Rect rect;
};

#endif


