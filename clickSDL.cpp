/*
 * File:   clickSDL.cpp
 * Author: Quentin&Valentin
 *
 * Created on 4 décembre 2014, 15:19
 */



// N EST PLUS UTILISE CAR DEPLACE DANS PARTIE

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "definitions.h"
#include "partie.h"
#include "clickSDL.h"

/*
Coup clickSDL(Joueur joueurCourrant){
    SDL_Event event;
    Coup nouveaucoup;
    nouveaucoup.joueur = joueurCourrant;
    bool continuer;

    while (continuer){
        SDL_WaitEvent(&event);
        switch(event.type){

        // clavier
            case SDL_QUIT: // si on veutbquitter
                continuer = 0;
                break;
            case SDLK_SPACE: // si on veut passer
                continuer = 1;
                nouveaucoup.x = -1;
                nouveaucoup.y = -1;
                break;

        // souris
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) // si on veut jouer
                    continuer = 1;
                    nouveaucoup.x = event.button.x;
                    nouveaucoup.y = event.button.y;
                break;
                if (event.button.button == SDL_BUTTON_RIGHT) // si on veut passer
                    continuer = 1;
                    nouveaucoup.x = -1;
                    nouveaucoup.y = -1;
                break;
        }
    }
    return nouveaucoup;
}

void ancrage(int &xint, int &yint){


}*/
