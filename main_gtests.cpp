
#include "gtest\gtest.h"
#include "partie.h"
#include "definitions.h"




/*
*
*
*
*
*/




TEST(Partie, testdetest) {

 Partie partie_test;
 Joueur joueur = NOIR;
 Coup coup_test1 = {joueur, 1 , 1};
 Coup coup_test2 = {joueur, 10 , 10};
	
	EXPECT_TRUE( partie_test.jouer(coup_test1)  );
	EXPECT_FALSE( partie_test.jouer(coup_test2)  );

}
