/*
 * File:   main.cpp
 * Author: Etienne et Samuel
 *
 * Created on 1 décembre 2014, 09:42
 */


#include <cstdlib>

#include "definitions.h"
#include "partie.h"
#include "affichage.h"

using namespace std;



int main(int argc, char** argv) {

    //Initialisation de la partie
    Partie partie;
    affichagePlateau(partie.getPlateau());

    // Boucle de jeu
    int k=0;
    while (k<10){ // remplacer par une condition de fin de partie
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
        k++;
    }
    return 0;
}

