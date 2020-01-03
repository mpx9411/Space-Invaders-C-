#include "Session.h"
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Engine.h"
#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include "Invader.h"
#include "Collider.h"
#include <memory>
#include <iostream>
#include <cstdlib>
using namespace std;

#define FPS 500



Session::Session(){

}

void Session::add(GameObject* o) {

    objects.push_back(o);
	added.push_back(o);

}

void Session::remove(GameObject* o) {	
	removed.push_back(o);
}
void Session::addBullet() {
	std::shared_ptr<Bullet> bullet = Bullet::getInstance(player->getRect().x+8, player->getRect().y + 30, 30, 30, "");
	Bullet& bObj = *bullet; //what does this do?? *Sina*
	storage.push_back(bullet);

}
void Session::run() {

    /**
	 * Background
	 */

    //TODO Choose your ABSOLUTE path plz

    /* ELSA */
    //SDL_Surface* bgSurf = IMG_Load("/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/background.png");

    /* Sina */
    SDL_Surface* bgSurf = IMG_Load("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/background.png");



    /* Magnus */
   // SDL_Surface* bgSurf = IMG_Load("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/background.png");
    SDL_Texture* bgTex = SDL_CreateTextureFromSurface(eng.getRen(), bgSurf);
    SDL_FreeSurface(bgSurf);
	Uint32 tickInterval = 1000 / FPS;
    SDL_Event e;
    bool quit = false;
    bool once = false;
    int varv =0;

    /**
     * game loop
     */

    while (!quit){
        bool collision = false;
        /**
         * adding invaders once
         */
        vector<Invader*> v1;
        while(!once) {

            for(int i=0;i<=30;i++){
                if(i%3==0) {
                    Invader *inv(Invader::getInstance(10 + (i * 50), 0, 30, 30, 1));
                    v1.push_back(inv);

                }if(i%3==1) {
                    Invader *inv(Invader::getInstance( (i * 50), 31, 30, 30, 2));
                    v1.push_back(inv);
                }if (i%3==2){
                    Invader *inv(Invader::getInstance( (i * 50), 62, 30, 30, 3));
                    v1.push_back(inv);
                }
            }

            Invader *inv3(Invader::getInstance( 10, 62, 30, 30, 3));
            v1.push_back(inv3);

            for(Invader* inv : v1){
                //added.push_back(inv);
                //objects.push_back(inv);
                ses.add(inv);
            }

            once =true;
        }

        /**
         * SDL EVENTs
         */
        Uint32 time = SDL_GetTicks();
        while (SDL_PollEvent(&e)){
			nextTick = SDL_GetTicks() + tickInterval;
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                for (GameObject* c : objects)
                    c->keyPressed(e);
            }

        }
		/*if ((SDL_GetTicks() / 1000) % 4 == 0){
			for(int i = 0; i <= 10; i++){
				Invader* inv(Invader::getInstance(10 + (60 * i), 0, 40, 30));
				added.push_back(inv);
				ses.add(inv);
			}
		}*/

			/**
			 * Rendering
			 */
        SDL_RenderClear(eng.getRen());
        SDL_RenderCopy(eng.getRen(), bgTex, NULL, NULL);

        /**
         * checking for collision.
         */

        handleCollision();

        //CHECK försök att sätta spanet till rektangels bredd... CHECK
        //CHECK ta bort invader från object vector(inte bara att göra den osynlig)
        //TODO invader ska skjuta tillbaka
        //CHECK Deklarera Health variabel för invader
        //CHECK tänk på en animation/ljud när invader dör/träffas
        // TODO player kan träffas och dö också
        //CHECK gör att man  inte kan flytta player upp eller ner
        // CHECK player kan inte gå utanför rutan
        // CHECK bullet ska försvinna när den går utanför rutan.
        // TODO ADD GAME OVER AND YOU WON SCREEN/label
        // TODO Start sida

		for (GameObject* c : objects){

            if(Invader *invader =dynamic_cast<Invader *> (c)){
                if (varv % (5+invader->getHealth()) == 0) {
                    c->tick();


                }
            }

		}
        for (GameObject* c : objects)
            c->draw();
		for (int j =0; j<storage.size();j++) {
            storage[j]->tick();
			if(storage[j]->isOutOfBounds()){
                removedBullets.push_back(storage[j]);

                storage.erase(storage.begin() + j);
			}else

            storage[j]->draw();
		}
        SDL_RenderPresent(eng.getRen());
		if (tickInterval > (SDL_GetTicks() - time))
		{
			SDL_Delay(tickInterval - (SDL_GetTicks() - time)); //SDL_Delay pauses the execution.
		}
		varv++;
    }



}

Session::~Session() {
    added.clear();

    //for (GameObject* c : objects)
        //delete c;
    objects.clear();
    storage.clear();
    removed.clear();
    removedBullets.clear();


}

void Session::handleCollision() {


    /**
     * first checking in the new collisions in all of invaders
     */
    for(int i =0; i<objects.size();i++){
        if(Invader *invader =dynamic_cast<Invader *> (objects[i])){
            for(int j =0; j<storage.size();j++){


                if(abs(invader->getRect().x - storage[j]->getRect().x)<=15 && invader->getRect().y == storage[j]->getRect().y ){
                    cout<<"Boom \n";
                    collision = true;
                    invader->hit();
                    invader->reactToCollision();

                    if(!invader->isAlive()){
                        //moving it to the removed vector.
                        removed.push_back(invader);

                        objects.erase(objects.begin() + i); //not sure tbh

                    }
                    removedBullets.push_back(storage[j]);

                    storage.erase(storage.begin() + j);


                } else{
                    //DO NOTHING YET
                }

            }

        }

    }


}


Session ses;

