/*
 * File:   Partie.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:26
 */

#include "partie.h"
#include <iostream>

using namespace std;

using namespace std;

Partie::Partie() {
    listePlateaux.resize(1);
    listePlateaux[0].resize(TAILLE);
    for(int i=0; i<TAILLE; i++)
    {
        listePlateaux[0][i].resize(TAILLE);
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
    if(getPlateau()[nouveauCoup.x][nouveauCoup.y]!=NULL)
        return false;

    plateauCourant = getPlateau();
    plateauCourant[nouveauCoup.x][nouveauCoup.y] = nouveauCoup.joueur;
    testVivante.clear();

    //Attention, il faut gérer les kills !
    //estVivante(nouveauCoup)

}

bool Partie::estVivante(Coup pierre) {
    for(int i=0;i<testVivante.size();i++) {
        if(testVivante[i].x==pierre.x and testVivante[i].y==pierre.y)
            return false;
    }
    testVivante.push_back(pierre);

    if(pierre.x-1>=0 and plateauCourant[pierre.x-1][pierre.y]==NULL)
        return true;
    if(pierre.x+1<TAILLE and plateauCourant[pierre.x+1][pierre.y]==NULL)
        return true;
    if(pierre.y-1>=0 and plateauCourant[pierre.x][pierre.y-1]==NULL)
        return true;
    if(pierre.y+1<TAILLE and plateauCourant[pierre.x][pierre.y+1]==NULL)
        return true;

    Coup coupTest;
    coupTest.joueur = pierre.joueur;

    if(pierre.x-1>=0 and plateauCourant[pierre.x-1][pierre.y]==pierre.joueur) {
        coupTest.x = pierre.x-1;
        coupTest.y = pierre.y;
        if(estVivante(coupTest))
            return true;
    }
    if(pierre.x+1<TAILLE and plateauCourant[pierre.x+1][pierre.y]==pierre.joueur) {
        coupTest.x = pierre.x+1;
        coupTest.y = pierre.y;
        if(estVivante(coupTest))
            return true;
    }
    if(pierre.y-1>=0 and plateauCourant[pierre.x][pierre.y-1]==pierre.joueur) {
        coupTest.x = pierre.x;
        coupTest.y = pierre.y-1;
        if(estVivante(coupTest))
            return true;
    }
    if(pierre.y+1<TAILLE and plateauCourant[pierre.x][pierre.y+1]==pierre.joueur) {
        coupTest.x = pierre.x;
        coupTest.y = pierre.y+1;
        if(estVivante(coupTest))
            return true;
    }
    return false;
}

