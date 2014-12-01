/*
 * File:   Partie.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:26
 */

#include "partie.h"

Partie::Partie() {
    plateau.resize(TAILLE);
    for(int i=0; i<TAILLE; i++)
    {
        plateau[i].resize(TAILLE);
    }
}

Partie::Partie(const Partie& orig) {
}

std::vector<std::vector<int> > Partie::getPlateau() const {
    return plateau;
}

Partie::~Partie() {
}

