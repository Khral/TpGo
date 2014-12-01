/*
 * File:   Partie.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:26
 */

#include "partie.h"
#include <iostream>

using namespace std;

using namespace std;

Partie::Partie() {
    listePlateaux.resize(1);
    listePlateaux[0].resize(TAILLE);
    for(int i=0; i<TAILLE; i++)
    {
        listePlateaux[0][i].resize(TAILLE);
    }
}

Partie::Partie(const Partie& orig) {
}

std::vector<std::vector<Joueur> > Partie::getPlateau() const {
    return listePlateaux.back();
}

void Partie::coupUtilisateur (Joueur jouerCourrant){

    // On enregistre les instructions
    Coup Coupcourrant;
    Coupcourrant.joueur = jouerCourrant;
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
    cout << "Position du coup (en x):" ;
    cin >> Coupcourrant.x ;
    cout << "Position du coup (en y):" ;
    cin >> Coupcourrant.y ;



    // On place ces instructions dans la liste de coups
    listeCoups.push_back(Coupcourrant);
}


Partie::~Partie() {
}

bool Partie::jouer(Coup nouveauCoup) {

    //Si il y a déjà une pierre, on ne peut pas jouer
    if(getPlateau()[nouveauCoup.x][nouveauCoup.y]!=NULL)
        return false;

    vector<vector<Joueur> > plateauCourant = getPlateau();
    plateauCourant[nouveauCoup.x][nouveauCoup.y] = nouveauCoup.joueur;

}

bool Partie::estVivante(Coup pierre) {

}

