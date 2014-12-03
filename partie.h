/*
 * File:   Partie.h
 * Author: Etienne
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

    void coupUtilisateur(Joueur joueurCourrant); // place le coup choisi dans la liste des coups
    void retirerGroupe(int x, int y, std::vector<std::vector<Joueur> > & plateau);

private:
    bool estVivante(Coup pierre);
    bool testKo(std::vector<std::vector<Joueur> > plateau);

    std::vector<Coup> listeCoups;
    std::vector<std::vector<std::vector<Joueur> > > listePlateaux;
    std::vector<Coup> testVivante;

    int prisonniersBlanc=0;
    int prisonniersNoir=0;

    //Permet de gérer les cas où on revient en arrière
    int prisonniersCourant;
    std::vector<std::vector<Joueur> > plateauCourant;
};

#endif	/* PARTIE_H */

