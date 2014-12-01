/*
 * File:   affichage.cpp
 * Author: Etienne et Samuel
 *
 * Created on 1 décembre 2014, 09:53
 */

using namespace std;

void affichagePlateau(int plateau[TAILLE][TAILLE]){
    int i,j;

    for(int i=0; i<TAILLE; i++)
    {
        for(int j=0; j<TAILLE; j++)
        {
            if(plateau[i][j] == NULL)
            {
                cout << '.';
            }
           if(plateau[i][j]== JOUEURNOIR){
                 cout <<  "N";
           }

           if(plateau[i][j]== JOUEURBLANC)
            {
                cout << "B";
            }
            else{
                cout <<"X"; // permet de gérer le cas où
            }
        }
        cout << endl;
    }
    cout << endl;



}


