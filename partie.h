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
private:
    std::vector<coup> listeCoups;
};

#endif	/* PARTIE_H */

