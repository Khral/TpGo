/*
 * File:   affichage.cpp
 * Author: Etienne et Samuel
 *
 * Created on 1 décembre 2014, 09:53
 */

#include "affichage.h"

using namespace std;

void affichagePlateau(std::vector<std::vector<Joueur> > plateau){
    int i,j;

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


