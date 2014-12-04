/*
 * File:   main.cpp
 * Author: Etienne et Samuel
 *
 * Created on 1 décembre 2014, 09:42
 */

#define GRAPHIQUE 1
//Mettre 0 ou 1

#include <cstdlib>

#include <SDL.h>
#include <SDL_image.h>

#include "definitions.h"
#include "partie.h"
#include "affichage.h"
#include "affichageSDL.h"

#ifdef GRAPHIQUE

#include <SDL.h>
#include <SDL_image.h>

#endif // GRAPHIQUE


using namespace std;



int main(int argc, char** argv) {

   //Initialisation de la partie
    Partie partie;
    affichagePlateau(partie.getPlateau());

    // Boucle de jeu
    int k = partie.getPassesConsecutifs();
    while (k < 2){ // remplacer par une condition de fin de partie
        cout << "Nombre de passes: " << partie.getPassesConsecutifs() << endl;
        if (k%2==0){
            cout << "Au joueur noir de jouer: " ;
            partie.coupUtilisateur(NOIR);
            affichagePlateau(partie.getPlateau());
        }
        else {
            cout << "Au joueur blanc de jouer: " ;
            partie.coupUtilisateur(BLANC);
            affichagePlateau(partie.getPlateau());
        }
        k = partie.getPassesConsecutifs();
    }
    return 0;
}



/* MAIN GRAPHIQUE TEST */

/*
 void pause();

void pause(){
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}



int main ( int argc, char** argv ){


   //Fonction d'initialisation (chargement des surfaces)
        //bool init();

        //Gestion du jeu lors d'un clic
        //void clic(int , int);

        //Fonction d'affichage
        //void aff(SDL_Surface *screen);


    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Surface *goblanc = NULL, *gonoir = NULL, *goblancprison = NULL, *gonoirprison = NULL;
    SDL_Rect positionFond, positiongonoir, positiongoblanc;


    // placement initial
    positionFond.x = 0;
    positionFond.y = 0;

    positiongonoir.x = 50;
    positiongonoir.y = 50;
    positiongoblanc.x = 60;
    positiongoblanc.y = 50;

    Partie partie;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Jeu de Go - LIEVIN-PEILLARD-PETIT-TRESONTANI", NULL);


    // Boucle de jeu
    int k=0;
    imageDeFond = SDL_LoadBMP("Images\\terrain.bmp");
    while (k<15){ // remplacer par une condition de fin de partie
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        if (k%2==0){
            cout << "Au joueur noir de jouer: " ;
            partie.coupUtilisateur(NOIR);
            affichagePlateauSDL(partie.getPlateau(), ecran);
            //affichagePlateau(partie.getPlateau());
        }
        else {
            cout << "Au joueur blanc de jouer: " ;
            partie.coupUtilisateur(BLANC);
            //affichagePlateau(partie.getPlateau());
            affichagePlateauSDL(partie.getPlateau(), ecran);
        }
        k++;
    }


    //Test chargement d'images PNG ET BMP dans une surface




    //gonoir = IMG_Load("Images\\gonoir.png");
    //goblanc= IMG_Load("Images\\goblanc.png");
    //gonoirprison = IMG_Load("Images\\gonoir.png");
    //goblancprison = IMG_Load("Images\\goblanc.png");

    // On blitte par-dessus l'écran

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    //SDL_BlitSurface(goblanc, NULL, ecran, &positiongonoir);
    //SDL_BlitSurface(gonoir, NULL, ecran, &positiongoblanc);

    SDL_Flip(ecran);
    pause();

    SDL_FreeSurface(imageDeFond); // On libère la surface
    SDL_Quit();

    return 0;
}

*/

