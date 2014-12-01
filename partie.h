/*
 * File:   Partie.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:26
 */

#ifndef PARTIE_H
#define	PARTIE_H

#include <vector>
#include <iostream>
#include <algorithm>

#include "definitions.h"

class Partie {
public:
    Partie();
    Partie(const Partie& orig);
    virtual ~Partie();
    std::vector<std::vector<Joueur> > getPlateau() const;
    bool jouer(Coup nouveauCoup); //renvoie true si le coup est pris en compte
    bool estVivante(Coup pierre);

    void coupUtilisateur(Joueur joueurCourrant); // place le coup choisi dans la liste des coups
    void actualiserPlateau();

private:
    std::vector<Coup> listeCoups;
    std::vector<std::vector<std::vector<Joueur> > > listePlateaux;
    std::vector<Coup> testVivante;
    std::vector<std::vector<Joueur> > plateauCourant;
};

#endif	/* PARTIE_H */

