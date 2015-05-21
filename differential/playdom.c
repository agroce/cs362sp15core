#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  initializeGame(2, k, atoi(argv[1]), p);
  
  int money = 0;
  int smithyPos = -1;
  int adventurerPos = -1;
  int i=0;

  int numSmithies = 0;
  int numAdventurers = 0;

  while (!isGameOver(p)) {
    money = 0;
    smithyPos = -1;
    adventurerPos = -1;
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
    money++;
      else if (handCard(i, p) == silver)
    money += 2;
      else if (handCard(i, p) == gold)
    money += 3;
      else if (handCard(i, p) == smithy)
    smithyPos = i;
      else if (handCard(i, p) == adventurer)
    adventurerPos = i;
    }

    int r;

    if (whoseTurn(p) == 0) {
      if (smithyPos != -1) {
	r = playCard(smithyPos, -1, -1, -1, p); 
        printf("0: smithy played from position %d [%d]\n", smithyPos, r); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        r = buyCard(province, p);
        printf("0: bought province [%d]\n", r); 
      }
      else if (money >= 6) {
        r = buyCard(gold, p);
        printf("0: bought gold [%d]\n", r); 
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        r = buyCard(smithy, p);
        printf("0: bought smithy [%d]\n", r); 
        numSmithies++;
      }
      else if (money >= 3) {
        r = buyCard(silver, p);
        printf("0: bought silver [%d]\n", r); 
      }

      printf("0: end turn\n");
      endTurn(p);
    }
    else {
      if (adventurerPos != -1) {
	r = playCard(adventurerPos, -1, -1, -1, p); 
        printf("1: adventurer played from position %d [%d]\n", adventurerPos, r);
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        r = buyCard(province, p);
        printf("1: bought province [%d]\n", r);

      }
      else if ((money >= 6) && (numAdventurers < 2)) {
	r = buyCard(adventurer, p);
        printf("1: bought adventurer [%d]\n", r);
	numAdventurers++;
      }else if (money >= 6){
	    r = buyCard(gold, p);
	    printf("1: bought gold [%d] \n", r);
        }
      else if (money >= 3){
	r = buyCard(silver, p);

        printf("1: bought silver\n [%d]", r);
      }
      printf("1: endTurn\n");
      
      endTurn(p);      
    }

      printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
	    
  } // end of While

  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));

  return 0;
}
