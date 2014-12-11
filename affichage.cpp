/*
 * File:   affichage.cpp
 * Author: Etienne et Samuel
 *
 * Created on 1 décembre 2014, 09:53
 */

#include "affichage.h"

using namespace std;

void affichagePlateau(std::vector<std::vector<Joueur> > plateau){
    system("cls");

    for(int i=0; i<TAILLE; i++)
    {
        for(int j=0; j<TAILLE; j++)
        {
            if(plateau[i][j] == RIEN) {
                cout << '.';
            }
            else if(plateau[i][j]== NOIR){
                 cout <<  "N";
            }
            else if(plateau[i][j]== BLANC) {
                cout << "B";
            }
            else{
                cout <<"X"; // permet de gérer au cas où
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void coupUtilisateur (Partie &partie, Joueur joueurCourant){

    // On enregistre les instructions
    Coup coupCourant;
    coupCourant.joueur = joueurCourant;
    cout << "Voulez vous passer votre tour ? O/N ";
    char reponse;
    cin >> reponse;
    while ((reponse != 'O') && (reponse != 'N')){
        cout << "Repondez avec O/N: " << endl;
        cin >> reponse;
    }
    if (reponse == 'O'){
        coupCourant.x=-1; // par convention
        coupCourant.y=-1; // par convention
        partie.jouer(coupCourant);
    }
    if (reponse == 'N'){
        bool jouable = false;
        while (jouable == false){
            cout << "Position du coup (en x):" ;
            cin >> coupCourant.x ;
            cout << "Position du coup (en y):" ;
            cin >> coupCourant.y ;
            jouable = partie.jouer(coupCourant);
        }
    }
}
