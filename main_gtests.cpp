
#include "gtest/gtest.h"
#include "partie.h"
#include "definitions.h"

#include <iostream>


/*

*/


TEST(TestClassePartie, testdetest) { // test le bon fonctionnement d'un simple test

 Partie partie_test;
 Joueur joueur1=NOIR;
 Joueur joueur2=NOIR;
 Coup coup_test1;
 coup_test1.joueur=joueur1;
 coup_test1.x=1;
 coup_test1.y=1;
 Coup coup_test2;
 coup_test2.joueur=joueur2;
 coup_test2.x=1;
 coup_test2.y=1;

	EXPECT_EQ(1,1);
	EXPECT_EQ(1,2);
	EXPECT_TRUE( partie_test.jouer(coup_test1)  );
	EXPECT_FALSE( partie_test.jouer(coup_test2)  );
	EXPECT_EQ(1,3);
}
