/*
 * File:   affichageSDL.cpp
 * Author: Quentin&Valentin
 *
 * Created on 4 décembre 2014, 10:19
 */

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "definitions.h"
#include "partie.h"
#include "affichageSDL.h"

using namespace std;

SDL_Rect conversionPosition(int xin, int yin){
    // k: MARGIN + TRAIT + (CASE + TRAIT)*k
    SDL_Rect position;
    position.x = MARGIN + TRAIT + (CASE + TRAIT)*xin;
    position.y = MARGIN + TRAIT + (CASE + TRAIT)*yin;
    return position;
}



pos conversionPos(int xin, int yin){ // NE MARCHE PAS // Sensé désigner l'intersection la plus proche
    // k: MARGIN + TRAIT + (CASE + TRAIT)*k
    pos position;
    int prochex, prochey, diffx, diffy;
    prochex = 1000;
    prochey = 1000;
    for (int i=0; i<19; i++){
        diffx = xin - (MARGIN + TRAIT + (CASE + TRAIT)*i);
        diffx = abs(diffx);
        diffy = xin - (MARGIN + TRAIT + (CASE + TRAIT)*i);
        diffy = abs(diffy);
        if (diffx < prochex){
            prochex = diffx;
        }
        if (diffy < prochey){
            prochey = diffy;
        }
    }
    position.xpos = prochex;
    position.ypos = prochey;
    return position;
}

void affichagePlateauSDL(std::vector<std::vector<Joueur> > plateau, SDL_Surface *ecran){
    SDL_FreeSurface(ecran);

    // initialisation des paramètres
    vector<SDL_Surface> imagesGoblanc;
    vector<SDL_Surface> imagesGonoir;

    //chargement et affichage de l'image de fond
    SDL_Rect positionFond;
    SDL_Surface *imageDeFond;
    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("Images\\terrain.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    // boucle d'affichage
    for(int i=0; i<TAILLE; i++){
        for(int j=0; j<TAILLE; j++){
            SDL_Rect position = conversionPosition(i,j);
            if(plateau[i][j] == RIEN){
                //cout << '.';
            }
           else if(plateau[i][j]== NOIR){
                //cout <<  "N";
                SDL_Surface *gonoir = IMG_Load("Images\\gonoir.png");
                imagesGonoir.push_back(*gonoir);
                SDL_BlitSurface(gonoir, NULL, ecran, &position);
           }
           else if(plateau[i][j]== BLANC) {
                //cout << "B";
                SDL_Surface *goblanc = IMG_Load("Images\\goblanc.png");
                imagesGoblanc.push_back(*goblanc);
                SDL_BlitSurface(goblanc, NULL, ecran, &position);
            }
        }
    }
    SDL_Flip(ecran);

}

void affichagePlateauFinSDL(std::vector<std::vector<Joueur> > plateau, SDL_Surface *ecran){

    // initialisation des paramètres
    vector<SDL_Surface> imagesGoblanc;
    vector<SDL_Surface> imagesGonoir;
    vector<SDL_Surface> imagesGoblancPrison;
    vector<SDL_Surface> imagesGonoirPrison;

    //chargement et affichage de l'image de fond
    SDL_Rect positionFond;
    SDL_Surface *imageDeFond;
    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("Images\\terrain.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    // boucle d'affichage
    for(int i=0; i<TAILLE; i++){
        for(int j=0; j<TAILLE; j++){
            SDL_Rect position = conversionPosition(i,j);
            if(plateau[i][j] == RIEN){
                //cout << '.';
            }
           else if(plateau[i][j]== NOIR){
                //cout <<  "N";
                SDL_Surface *gonoir = IMG_Load("Images\\gonoir.png");
                imagesGonoir.push_back(*gonoir);
                SDL_BlitSurface(gonoir, NULL, ecran, &position);
           }
           else if(plateau[i][j]== BLANC) {
                //cout << "B";
                SDL_Surface *goblanc = IMG_Load("Images\\goblanc.png");
                imagesGoblanc.push_back(*goblanc);
                SDL_BlitSurface(goblanc, NULL, ecran, &position);
            }
            else if(plateau[i][j]== PRISO_NOIR) {
                //cout << "B";
                SDL_Surface *gonoirprison = IMG_Load("Images\\gonoirprison.png");
                imagesGonoirPrison.push_back(*gonoirprison);
                SDL_BlitSurface(gonoirprison, NULL, ecran, &position);
            }
              else if(plateau[i][j]== PRISO_BLANC) {
                //cout << "B";
                SDL_Surface *goblancprison = IMG_Load("Images\\goblancprison.png");
                imagesGoblancPrison.push_back(*goblancprison);
                SDL_BlitSurface(goblancprison, NULL, ecran, &position);
            }
        }
    }
    SDL_Flip(ecran);
}

void clickSDL(Partie &partie, Joueur joueurCourant){
    SDL_Event event;
    bool continuer;
    Coup nouveauCoup;

    nouveauCoup.joueur = joueurCourant;

    while (continuer){
        SDL_WaitEvent(&event);
        switch(event.type){

        // clavier
            case SDL_QUIT: // si on veut quitter
                continuer = 0;
                break;
            case SDLK_SPACE: // si on veut passer
                continuer = 1;
                nouveauCoup.x = -1;
                nouveauCoup.y = -1;
                break;

        // souris
            case SDL_MOUSEBUTTONUP:
                pos position;
                if (event.button.button == SDL_BUTTON_LEFT) // si on veut jouer
                {
                    position = conversionPos(event.button.x-5, event.button.y-5);
                    nouveauCoup.x = position.xpos;
                    nouveauCoup.y = position.ypos;
                    continuer = !(partie.jouer(nouveauCoup));
                }
                break;
        }
    }
}
