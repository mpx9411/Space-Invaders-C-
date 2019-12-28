#include "Invader.h"
#include "SDL_image.h"
#include "Engine.h"




Invader::Invader(int x, int y, int w, int h) : GameObject{x, y, w, h} {

    /* Sina */
    iTx = IMG_LoadTexture(eng.getRen(), "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/Invader.png");

    /* Elsa */
    //iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/invader.png");




    /* Magnus */
    //iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/invader.png");


    setXY(x, y);

}

Invader* Invader::getInstance(int x, int y, int w, int h) {
	return new Invader(x, y, w, h);
}

void Invader::draw() const {
	SDL_Rect iRect = getRect();
	SDL_RenderCopy(eng.getRen(), iTx, NULL, &iRect);
}

void Invader::tick() {

    if(getRect().y % 2 ==0) // invader is going to right
    {
        if(getRect().x==eng.getWinW()) //we are going down!
            setXY(getRect().x,getRect().y+31);
        else
            setXY(getRect().x+1,getRect().y);

    }
    else{ // invader is going to left

        if(getRect().x==0) //we are going down!
            setXY(getRect().x,getRect().y+31);
        else
            setXY(getRect().x-1,getRect().y);
    }

}

Invader::~Invader() {
	SDL_DestroyTexture(iTx);
}