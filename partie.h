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
    
    std::vector<std::vector<int> > getPlateau();
    bool jouer(Coup nouveauCoup); //renvoie true si le coup est pris en compte
    
private:
    std::vector<Coup> listeCoups;
    std::vector<std::vector<int> > plateau;
};

#endif	/* PARTIE_H */

