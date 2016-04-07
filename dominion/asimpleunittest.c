#include "dominion.h"

int failed = 0;

int myassert(int b,char* msg) {
  if (b == 0) {
    printf("FAILED ASSERTION: %s\n",msg);
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("TEST SUCCESSFULLY COMPLETED.\n");
  }
}

int main() {
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  myassert(r == 0, "No duplicates, 2 players, should succeed");

  int k2[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,adventurer};

  r = initializeGame(2, k2, 5, &g);

  myassert(r == -1,"Duplicate card in setup, should fail");

  r = initializeGame(200, k, 5, &g);

  myassert(r == 0,"I should be allowed to play with a lot of people!");

  checkasserts();
}
