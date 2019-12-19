#include "Engine.h"
#include "SDL.h"
#include "Player.h"
#include "SDL_image.h"

Engine::Engine(){}

void Engine::start() {
    int w=900;
    int h=600;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
		"SPACE INVADER", //TITLE
		100, 100, // coordinates on the screen, in pixels, of the window's upper left corner
		w, h, // window's length and height in pixels
		0);
	ren = SDL_CreateRenderer(window, -1, 0);
	//TODO Change the string to the right ABSOLUTE path plz

	/* MAGNUS*/
	//SDL_Surface* hSurf = SDL_LoadBMP("C:\\Users\\olema\\Downloads\\6e4.bmp");
    //SDL_Surface* hSurf = SDL_LoadBMP("C:\\Users\\olema\\Downloads\\6e4.bmp");
	/* SINA */
    SDL_Surface* hSurf = IMG_Load("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/background.png");
    SDL_Surface* pSurf = IMG_Load("/Users/sina/Desktop/CProg/CPROG_Inlupp/SDL/Images/player.png");

    /* ELSA */
    //SDL_Surface* hSurf = IMG_Load("/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/background.png");
    //SDL_Surface* pSurf = IMG_Load("/Users/elsabergman/Documents/DSV/År 3/HT19/CPROG_Inlupp/SDL/Images/player.png");

	SDL_Texture* hTex = SDL_CreateTextureFromSurface(ren, hSurf);
	SDL_FreeSurface(hSurf);



    SDL_Texture* pTx = SDL_CreateTextureFromSurface(ren,pSurf);
    SDL_Rect pRect= {(w-(pSurf -> w))/2,h-((pSurf-> h)),(pSurf -> w), (pSurf-> h)};
    //SDL_Rect sdlRect= {0,0,hSurf -> w, hSurf-> h};
    //gubbsurf är en pekare och för att hämta info från själva objektet så använder vi av piloperatorn
    //Uint32 white = SDL_MapRGB(pSurf->format,255,255,255);
    //SDL_SetColorKey(pSurf,true,white);// alla pixlar som är vita kommer bli genomskilliga

    SDL_FreeSurface(pSurf);


    SDL_Event e;
    bool quit = false;
    bool drag = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                switch (e.key.keysym.sym) {
                    case SDLK_UP: pRect.y--; break;
                    case SDLK_DOWN: pRect.y++; break;
                    case SDLK_RIGHT: pRect.x++; break;
                    case SDLK_LEFT: pRect.x--; break;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                SDL_Point p = {e.button.x, e.button.y};
                if (SDL_PointInRect(&p,&pRect))
                drag = true;
            }
            if (e.type == SDL_MOUSEBUTTONUP){
                drag = false;
            }
            if (e.type == SDL_MOUSEMOTION){
                if (drag){
                    pRect.x += e.motion.xrel;
                    pRect.y += e.motion.yrel;

                }
            }
        }

        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, hTex, NULL, NULL);
        SDL_RenderCopy(ren,pTx,NULL,&pRect);
        SDL_RenderPresent(ren);
    }



}

SDL_Renderer* Engine::getRen() const{
	return ren;
}

 Engine :: ~Engine() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

 Engine eng;