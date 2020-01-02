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
	vector<pair<int, int>> coor;
	SDL_Rect getRect() const { return rect; }
	virtual void draw() const = 0;
	virtual void tick() = 0;
    GameObject(const GameObject&) = delete;
    const GameObject& operator=(const GameObject&) = delete;
	//vector<pair<int, int>> collisionSurface();

protected:
	GameObject(int x, int y, int w, int h);
	void setWH(int w, int h);
	void setXY(int x, int y);

private:
	SDL_Rect rect;
	
};

#endif


