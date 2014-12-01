/*
 * File:   definitions.h
 * Author: Etienne
 *
 * Created on 1 décembre 2014, 09:58
 */

#ifndef DEFINITIONS_H
#define	DEFINITIONS_H

const int TAILLE=5;

enum Joueur {BLANC, NOIR};

struct Coup{
    Joueur joueur;
    int x;
    int y;
};

#endif	/* DEFINITIONS_H */

