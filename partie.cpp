/*
 * File:   Partie.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:26
 */

#include "partie.h"

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

std::vector<std::vector<int> > Partie::getPlateau() const {
    return listePlateaux.back();
}

Partie::~Partie() {
}

