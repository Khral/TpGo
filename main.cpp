/*
 * File:   main.cpp
 * Author: Etienne et Samuel
 *
 * Created on 1 décembre 2014, 09:42
 */

#define GRAPHIQUE 0
//Mettre 0 ou 1

#include <cstdlib>

#include "definitions.h"
#include "partie.h"

#if GRAPHIQUE
#include <SDL.h>
#include <SDL_image.h>
#include "affichageSDL.h"
#include "affichageSDL.cpp"
#else
#include "affichage.h"
#include "affichage.cpp"
#endif // GRAPHIQUE

using namespace std;


int main(int argc, char** argv) {

   //Initialisation de la partie
    Partie partie;
    Joueur joueur = NOIR;

    #if GRAPHIQUE
    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Surface *goblanc = NULL, *gonoir = NULL, *goblancprison = NULL, *gonoirprison = NULL;
    SDL_Rect positionFond, positiongonoir, positiongoblanc;

    // placement initial
    positionFond.x = 0;
    positionFond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Jeu de Go - LIEVIN-PEILLARD-PETIT-TRESONTANI", NULL);
    imageDeFond = SDL_LoadBMP("Images\\terrain.bmp");

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    #else
    affichagePlateau(partie.getPlateau());
    #endif // GRAPHIQUE

    // Boucle de jeu
    int k = partie.getPassesConsecutifs();

    while (k < 2){ // remplacer par une condition de fin de partie
        //Pré-affichage
        #if GRAPHIQUE
        #else
        switch(joueur) {
            case NOIR:
                cout << "Au joueur noir de jouer: " ;
                break;
            case BLANC:
                cout << "Au joueur blanc de jouer: " ;
                break;
        }
        #endif // GRAPHIQUE

        //Demande de coup
        #if GRAPHIQUE
        clickSDL(partie, joueur);
        #else
        coupUtilisateur(partie, joueur);
        #endif // GRAPHIQUE

        //Ré-affichage
        #if GRAPHIQUE
        affichagePlateauSDL(partie.getPlateau(), ecran);
        #else
        affichagePlateau(partie.getPlateau());
        #endif // GRAPHIQUE

        switch(joueur) {
            case NOIR:
                joueur = BLANC;
                break;
            case BLANC:
                joueur = NOIR;
                break;
        }

        k = partie.getPassesConsecutifs();
    }

    //Fin
    #if GRAPHIQUE
    SDL_FreeSurface(imageDeFond); // On libère la surface
    SDL_Quit();
    #else
    cout << "C'est fini !" << endl;
    cout << "Score NOIR : " << partie.getScoreNoir() << endl;
    cout << "Score BLANC : " << partie.getScoreBlanc() << endl;
    if(partie.getScoreBlanc()>partie.getScoreNoir())
        cout << "Blanc gagne" << endl;
    else
        cout << "Noir gagne" << endl;
    #endif // GRAPHIQUE

    return 0;
}


