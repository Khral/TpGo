/*
 * File:   clickSDL.cpp
 * Author: Quentin&Valentin
 *
 * Created on 4 décembre 2014, 15:19
 */


#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "definitions.h"
#include "partie.h"
#include "clickSDL.h"

 // déclaration d'un évènement
// SDL_WaitEvent: bloque l'execution tant qu'aucun évènement ne se produit

Coup clickSDL(){
    SDL_Event event;
    Coup nouveaucoup;
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
                break;

        // souris
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) // si on veut jouer
                    nouveaucoup.x = event.button.x;
                    nouveaucoup.y = event.button.y;
                break;
                if (event.button.button == SDL_BUTTON_RIGHT) // si on veut passer
                    continuer = 1;
                break;
        }
    }
    return nouveaucoup;
}

void ancrage(int &xint, int &yint){


}
