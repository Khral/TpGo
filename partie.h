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
    std::vector<std::vector<Joueur> > getPlateauFin();
    bool jouer(Coup nouveauCoup); //renvoie true si le coup est pris en compte

    void retirerGroupe(int x, int y, std::vector<std::vector<Joueur> > & plateau);
    void rendrePrisonniers(int x, int y);
    int getScoreBlanc() const;
    int getScoreNoir() const;
    int getPassesConsecutifs() const;

    void compterPoints();
    void compterIntersections(int x, int y);

private:
    bool estVivante(Coup pierre);
    bool testKo(std::vector<std::vector<Joueur> > plateau);

    std::vector<Coup> listeCoups;
    std::vector<std::vector<std::vector<Joueur> > > listePlateaux;
    std::vector<Coup> testVivante;
    std::vector<std::vector<Joueur> > plateauFin;

    int prisonniersBlanc=0; //Nombre de prisonniers de Blanc
    int prisonniersNoir=0;

    //Permet de gérer les cas où on revient en arrière
    int prisonniersCourant;
    std::vector<std::vector<Joueur> > plateauCourant;
    int intersectionBlanc=0;
    int intersectionNoir=0;

    int passesConsecutifs = 0; // Détecte la fin du jeu

    std::vector<Coup> interDejaTestees;
    std::vector<Coup> interCourantes;
};

#endif	/* PARTIE_H */

