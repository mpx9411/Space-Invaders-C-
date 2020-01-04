#include "Session.h"
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_mixer.h"
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
	vector<GameObject*> startObjects;
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
	/*SDL_Surface* bgSurf = IMG_Load("/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/background.png");
    SDL_Texture* bgTex = SDL_CreateTextureFromSurface(eng.getRen(), bgSurf);
    SDL_FreeSurface(bgSurf);
	Uint32 tickInterval = 1000 / FPS;
    SDL_Event e;
    bool quit = false;*/
    //bool once = false;
    //int varv =0;

    /*while (!quit){
       /* bool collision = false;
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
                ses.add(inv);
            }

            once =true;
        }
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
		
        SDL_RenderClear(eng.getRen());
        SDL_RenderCopy(eng.getRen(), bgTex, NULL, NULL);

        handleCollision();

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
    }*/



}

const char* Session::getBG()
{
	return "/Users/olema/Documents/GitHub/CPROG_Inlupp/SDL/Images/background.png";
}

int Session::getFPS()
{
	return 60;
}

vector<GameObject*> Session::preLoad()
{
	return startObjects;
}

Session::~Session() {
    added.clear();
    objects.clear();
    storage.clear();
    removed.clear();
    removedBullets.clear();


}

void Session::handleCollision() {
    for(int i =0; i<objects.size();i++){
        if(Invader *invader =dynamic_cast<Invader *> (objects[i])){
            for(int j =0; j<storage.size();j++){


                if(abs(invader->getRect().x - storage[j]->getRect().x)<=15 && invader->getRect().y == storage[j]->getRect().y ){
                    cout<<"Boom \n";
                    collision = true;
                    invader->hit();
                   // invader->reactToCollision();

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

