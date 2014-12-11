/*
 * File:   affichage.h
 * Author: Etienne et Samuel
 *
 * Created on 1 décembre 2014, 09:54
 */

#ifndef AFFICHAGE_H
#define	AFFICHAGE_H

#include <vector>
#include <iostream>
#include <cstdlib>

#include "definitions.h"
#include "partie.h"


void affichagePlateau(std::vector<std::vector<Joueur> > plateau);

void coupUtilisateur(Partie &partie, Joueur joueurCourant);

#endif	/* AFFICHAGE_H */

