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
    int k = 0;
    affichagePlateau(partie.getPlateau());
    while (k<10){
        if (k%2==1){
            cout << "Le joueur noir joue: ";
            partie.coupUtilisateur(NOIR);
            affichagePlateau(partie.getPlateau());
        }
        else {
            cout << "Le joueur blanc joue: ";
            partie.coupUtilisateur(BLANC);
            affichagePlateau(partie.getPlateau());
        }
        k++;
    }
    return 0;
}

