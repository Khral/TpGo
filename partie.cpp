/*
 * File:   Partie.cpp
 * Author: Etienne
 *
 * Created on 1 décembre 2014, 10:26
 */

#include "partie.h"

#include <iostream>
#include <algorithm>

using namespace std;

Partie::Partie() {
    listePlateaux.resize(1);
    listePlateaux[0].resize(TAILLE);
    for(int i=0; i<TAILLE; i++)
    {
        listePlateaux[0][i].resize(TAILLE);
        for(int j=0; j<TAILLE; j++)
        {
            listePlateaux[0][i][j]=RIEN;
        }
    }
}

Partie::Partie(const Partie& orig) {
}

std::vector<std::vector<Joueur> > Partie::getPlateau() const {
    return listePlateaux.back();
}

void Partie::coupUtilisateur (Joueur jouerCourrant){

    // On enregistre les instructions
    Coup Coupcourrant;
    Coupcourrant.joueur = jouerCourrant;
    cout << "Voulez vous passer votre tour ? O/N ";
    char reponse;
    cin >> reponse;
    while ((reponse != 'O') && (reponse != 'N')){
        cout << "Repondez avec O/N: " << endl;
        cin >> reponse;
    }
    if (reponse == 'O'){
        Coupcourrant.x=-1; // par convention
        Coupcourrant.y=-1; // par convention
    }
    if (reponse == 'N'){
        bool jouable = false;
        while (jouable == false){
            cout << "Position du coup (en x):" ;
            cin >> Coupcourrant.x ;
            cout << "Position du coup (en y):" ;
            cin >> Coupcourrant.y ;
            jouable = jouer(Coupcourrant);
        }
    }

    // On place ces instructions dans la liste de coups
    listeCoups.push_back(Coupcourrant);
}

void Partie::actualiserPlateau() { // EN COURS
    /*<std::vector<std::vector<Joueur> >  newPlateau;
    listePlateaux.push_back(newPlateau)
    */
}

Partie::~Partie() {
}

bool Partie::jouer(Coup nouveauCoup) {

    //Si il y a déjà une pierre, on ne peut pas jouer
    if(getPlateau()[nouveauCoup.x][nouveauCoup.y]!=RIEN)
        return false;

    plateauCourant = getPlateau();
    plateauCourant[nouveauCoup.x][nouveauCoup.y] = nouveauCoup.joueur;

    //On regarde si on capture un truc
    prisonniersCourant = 0;
    Coup coupTest;
    switch (nouveauCoup.joueur) {
        case BLANC:
            coupTest.joueur = NOIR;
            break;
        case NOIR:
            coupTest.joueur = BLANC;
            break;
    }

    if(nouveauCoup.x-1>=0 && plateauCourant[nouveauCoup.x-1][nouveauCoup.y]==coupTest.joueur) {
        coupTest.x = nouveauCoup.x-1;
        coupTest.y = nouveauCoup.y;

        testVivante.clear();
        if(!estVivante(coupTest))
            retirerGroupe(coupTest.x,coupTest.y, plateauCourant);
    }

    if(nouveauCoup.x+1<TAILLE && plateauCourant[nouveauCoup.x+1][nouveauCoup.y]==coupTest.joueur) {
        coupTest.x = nouveauCoup.x+1;
        coupTest.y = nouveauCoup.y;

        testVivante.clear();
        if(!estVivante(coupTest))
            retirerGroupe(coupTest.x,coupTest.y, plateauCourant);
    }

    if(nouveauCoup.y-1>=0 && plateauCourant[nouveauCoup.x][nouveauCoup.y-1]==coupTest.joueur) {
        coupTest.x = nouveauCoup.x;
        coupTest.y = nouveauCoup.y-1;

        testVivante.clear();
        if(!estVivante(coupTest))
            retirerGroupe(coupTest.x,coupTest.y, plateauCourant);
    }

    if(nouveauCoup.y+1<TAILLE && plateauCourant[nouveauCoup.x][nouveauCoup.y+1]==coupTest.joueur) {
        coupTest.x = nouveauCoup.x;
        coupTest.y = nouveauCoup.y+1;

        testVivante.clear();
        if(!estVivante(coupTest))
            retirerGroupe(coupTest.x,coupTest.y, plateauCourant);
    }

    //On regarde si on ne s'est pas suicidé
    testVivante.clear();
    if(!estVivante(nouveauCoup))
        return false;

    //On gère le KO
    if(testKo(plateauCourant))
        return false;

    //On envoie !
    switch(nouveauCoup.joueur) {
        case NOIR:
            prisonniersNoir+=prisonniersCourant;
            break;
        case BLANC:
            prisonniersBlanc+=prisonniersCourant;
            break;
    }
    listePlateaux.push_back(plateauCourant);
    return true;

}

bool Partie::estVivante(Coup pierre) {
    for(int i=0;i<testVivante.size();i++) {
        if(testVivante[i].x==pierre.x && testVivante[i].y==pierre.y)
            return false;
    }
    testVivante.push_back(pierre);

    if(pierre.x-1>=0 && plateauCourant[pierre.x-1][pierre.y]==RIEN)
        return true;
    if(pierre.x+1<TAILLE && plateauCourant[pierre.x+1][pierre.y]==RIEN)
        return true;
    if(pierre.y-1>=0 && plateauCourant[pierre.x][pierre.y-1]==RIEN)
        return true;
    if(pierre.y+1<TAILLE && plateauCourant[pierre.x][pierre.y+1]==RIEN)
        return true;

    Coup coupTest;
    coupTest.joueur = pierre.joueur;

    if(pierre.x-1>=0 && plateauCourant[pierre.x-1][pierre.y]==pierre.joueur) {
        coupTest.x = pierre.x-1;
        coupTest.y = pierre.y;
        if(estVivante(coupTest))
            return true;
    }
    if(pierre.x+1<TAILLE && plateauCourant[pierre.x+1][pierre.y]==pierre.joueur) {
        coupTest.x = pierre.x+1;
        coupTest.y = pierre.y;
        if(estVivante(coupTest))
            return true;
    }
    if(pierre.y-1>=0 && plateauCourant[pierre.x][pierre.y-1]==pierre.joueur) {
        coupTest.x = pierre.x;
        coupTest.y = pierre.y-1;
        if(estVivante(coupTest))
            return true;
    }
    if(pierre.y+1<TAILLE && plateauCourant[pierre.x][pierre.y+1]==pierre.joueur) {
        coupTest.x = pierre.x;
        coupTest.y = pierre.y+1;
        if(estVivante(coupTest))
            return true;
    }
    return false;
}

void Partie::retirerGroupe(int x, int y, std::vector<std::vector<Joueur> > & plateau) {
    if(x-1>=0 && plateau[x-1][y]==plateau[x][y])
        retirerGroupe(x-1, y, plateau);
    if(x+1<TAILLE && plateau[x+1][y]==plateau[x][y])
        retirerGroupe(x+1, y, plateau);
    if(y-1>=0 && plateau[x][y-1]==plateau[x][y])
        retirerGroupe(x, y-1, plateau);
    if(y+1<TAILLE && plateau[x][y+1]==plateau[x][y])
        retirerGroupe(x, y+1, plateau);

    plateau[x][y] = RIEN;
    prisonniersCourant++;
}

bool Partie::testKo(vector<vector<Joueur> > plateau){
    for(int k=0;k<listePlateaux.size();k++){
        for(int i=0; i<TAILLE;i++) {
            for(int j=0;j<TAILLE;j++) {
                if(listePlateaux[k][i][j]!=plateau[i][j])
                    return false;
            }
        }
    }
    return true;
}

