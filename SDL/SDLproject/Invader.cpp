#include "Invader.h"
#include "SDL_image.h"
#include "Engine.h"
#include <iostream>
#include "Bullet.h"

using namespace std;




Invader::Invader(int x, int y, int w, int h,int type) : MovingObject{x, y, w, h} {

    //TODO Choose your ABSOLUTE path plz for each invader type!

    /**
     * COLORs = type!
     * 1 == BLUE
     * 2 == GREEN
     * 3 == PINK
     */

    this->type = type;
	varv = 0;

    if (type == 1){ //
        /* Sina */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/invaderBlue3.png");

        /* Elsa */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/invaderBlue3.png");

        /* Magnus */
        iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderBlue3.png");

    }if (type == 2){
        /* Sina */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/InvaderGreen3.png");

        /* Elsa */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/InvaderGreen3.png");

        /* Magnus */
        iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderGreen3.png");
    }if (type == 3){
        /* Sina */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/InvaderPink3.png");

        /* Elsa */
        //iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/InvaderPink3.png");

        /* Magnus */
        iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderPink3.png");
    }

    setXY(x, y);

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
	if (varv % (5 + getHealth()) == 0) {

		if (right != 0) {

			if (right == 1)
				left = 20;

			right--;
			//left++;
			setXY(getRect().x + 1, getRect().y);

		}
		else {
			if (left == 1)
				right = 20;

			left--;
			//left++;
			setXY(getRect().x - 1, getRect().y);
		}
	}
	varv++;
}

void Invader::kill() {
	eng.remove(this);
}

bool Invader::isAlive(){
    return alive;
}

Invader::~Invader() {
	SDL_DestroyTexture(iTx);
}

void Invader::hit() {
    health --;

    if(health==0)
        kill();

}

void Invader::collidesWith(GameObject* o) {
	if (Bullet* bullet = dynamic_cast<Bullet*> (o)) {
		hit();
		switch (health) {
		case 2:
			cout << health << "\n";
			if (type == 1) { //
				/* Sina */
				//iTx = IMG_LoadTexture(eng.getRen(),"/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/invaderBlue2.png");

				/* Elsa */
				//iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/invaderBlue2.png");

				/* Magnus */
				iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderBlue2.png");
			}
			if (type == 2) {
				/* Sina */
				//iTx = IMG_LoadTexture(eng.getRen(),"/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/InvaderGreen2.png");

				/* Elsa */
				//iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/InvaderGreen2.png");

				/* Magnus */
				iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderGreen2.png");
			}
			if (type == 3) {
				/* Sina */
				//iTx = IMG_LoadTexture(eng.getRen(),"/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/InvaderPink2.png");

				/* Elsa */
				//iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/InvaderPink2.png");

				/* Magnus */
				iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderPink2.png");
			}

			break;
		case 1:
			cout << health << "\n";
			if (type == 1) { //
				/* Sina */
				//iTx = IMG_LoadTexture(eng.getRen(),"/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/invaderBlue1.png");

				/* Elsa */
				//iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/invaderBlue1.png");

				/* Magnus */
				iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderBlue1.png");
			}
			if (type == 2) {
				/* Sina */
				//iTx = IMG_LoadTexture(eng.getRen(),"/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/InvaderGreen1.png");

				/* Elsa */
				//iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/InvaderGreen1.png");

				/* Magnus */
				iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderGreen1.png");
			}
			if (type == 3) {
				/* Sina */
				//iTx = IMG_LoadTexture(eng.getRen(),"/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/InvaderPink1.png");

				/* Elsa */
				//iTx = IMG_LoadTexture(eng.getRen(), "/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/InvaderPink1.png");

				/* Magnus */
				iTx = IMG_LoadTexture(eng.getRen(), "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/InvaderPink1.png");
			}
			break;
		case 0:
			cout << health << "\n";
			// die!
			break;
		}
	}
 }

int Invader::getHealth() {
    return health;
}

