
/*
 * File:   affichageSDL.h
 * Author: Quentin&Valentin
 *
 * Created on 4 décembre 2014, 10:19
 */

#ifndef AFFICHAGESDL_H
#define	AFFICHAGESDL_H

#include <vector>
#include <iostream>
#include "definitions.h"
#include <SDL.h>
#include <SDL_image.h>

struct pos {
    int xpos;
    int ypos;
};

void affichagePlateauSDL(std::vector<std::vector<Joueur> > plateau, SDL_Surface *ecran);
// affichage du plateau pendant le jeu

SDL_Rect conversionPosition(int xin, int yin);
// converti les données de l'utilisateur en pixels

pos conversionPos(int xin, int yin);

void affichagePlateauFinSDL(std::vector<std::vector<Joueur> > plateau, SDL_Surface *ecran);
// affichage du plateau de fin avec les prisonniers


#endif	/* AFFICHAGESDL_H */
