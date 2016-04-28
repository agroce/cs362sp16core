#include "dominion.h"

int failed = 0; 

void myassert(int bool) {
  if (!bool) {
    printf ("YOU HAVE FAILED ME.\n");
    failed = 1;
  }

}

int main() {
  struct gameState g;
  g.numPlayers = 2;
  myassert(g.numPlayers == 2);
  g.whoseTurn = 1;
  myassert(whoseTurn(&g) == 1);
  if (!failed) {
    printf("TEST SUCCESSFULLY COMPLETED\n");
  }
  return 0;
}
