/*
 * File:   Partie.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:26
 */

#ifndef PARTIE_H
#define	PARTIE_H

#include <vector>

#include "definitions.h"

class Partie {
public:
    Partie();
    Partie(const Partie& orig);
    virtual ~Partie();
    std::vector<std::vector<int> > getPlateau() const;
    bool jouer(Coup nouveauCoup); //renvoie true si le coup est pris en compte

    void coupUtilisateur(Joueur joueurCourrant); // place le coup choisi dans la liste des coups

private:
    std::vector<Coup> listeCoups;
    std::vector<std::vector<std::vector<int> > > listePlateaux;
};

#endif	/* PARTIE_H */

