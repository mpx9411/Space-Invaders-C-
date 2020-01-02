#include "Invader.h"
#include "SDL_image.h"
#include "Engine.h"
#include "Session.h"
#include <iostream>

using namespace std;




Invader::Invader(int x, int y, int w, int h,int type) : GameObject{x, y, w, h} {

    //TODO Choose your ABSOLUTE path plz for each invader type!

    if (type == 1){
        /* Sina */
        iTx = IMG_LoadTexture(eng.getRen(), "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/Invader.png");

    /* Elsa */
    //iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/invader.png");

    /* Magnus */
    //iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/invader.png");
    }if (type == 2){
        /* Sina */
        iTx = IMG_LoadTexture(eng.getRen(), "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/Invader2.png");

        /* Elsa */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/invader2.png");

        /* Magnus */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/invader2.png");
    }if (type == 3){
        /* Sina */
        iTx = IMG_LoadTexture(eng.getRen(), "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/Invader3.png");

        /* Elsa */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/invader3.png");

        /* Magnus */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/invader3.png");
    }

    setXY(x, y);
	//coor = collisionSurface();

}

Invader* Invader::getInstance(int x, int y, int w, int h,int t) {
	return new Invader(x, y, w, h, t);
}

void Invader::draw() const {
	if(alive) {
        SDL_Rect iRect = getRect();
        SDL_RenderCopy(eng.getRen(), iTx, NULL, &iRect);
    }
}

void Invader::tick() {

    /**
     * first version, with one invader going down
     */
/*
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
*/

    /**
    * second version, with invaders going left and right
    */

    if(right!=0) {

            if(right==1)
                left=20;

            right--;
            //left++;
            setXY(getRect().x + 1, getRect().y);

    }else {
        if(left==1)
            right=20;

        left--;
        //left++;
        setXY(getRect().x - 1, getRect().y);
    }

}

void Invader::kill() {
    alive = false;
}

bool Invader::isAlive(){
    return alive;
}

Invader::~Invader() {
	SDL_DestroyTexture(iTx);
}
