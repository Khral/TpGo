/*
 * File:   Partie.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:26
 */

#include "partie.h"

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

