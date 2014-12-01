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

void coupUtilisateur (Joueur){
    Coup Coupcourrant;
    cout << "Voulez vous passer votre tour ? O/N ";
    char reponse;
    cin >> reponse;
    while ((reponse != 'O') && (reponse != 'N')){
        cout << "Repondez avec O/N: " << endl;
        cin >> reponse;
    }
    if (reponse == 'O'){
        Coupcourrant.x=-1;
        Coupcourrant.y=-1;
    }
    cin >> Coupcourrant.x ;
    cin >> Coupcourrant.y ;
}


int main(int argc, char** argv) {

    //Initialisation de la partie
    Partie partie;

    affichagePlateau(partie.getPlateau());

    return 0;
}

