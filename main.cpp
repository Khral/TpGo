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
    partie.coupUtilisateur(NOIR);
    affichagePlateau(partie.getPlateau());

    return 0;
}

