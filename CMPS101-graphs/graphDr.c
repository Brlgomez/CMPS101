/******************************
 * By: Brandon Gomez (brlgomez)
 *     Dylan Ma (dylma)
 *****************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
#include "graph.h"

int main(int argc, char** argv)
{ 
  Graph G = newGraph(5);
  addEdge(G, 0, 1);
  addEdge(G, 0, 2);
  addEdge(G, 2, 3);
  addEdge(G, 2, 4);
  addEdge(G, 3, 4);
  addEdge(G, 4, 3);
  addEdge(G, 4, 2);
  doBFS(G, 0);
  printf("To get from 0 to 4 requires %d edges.\n",getDistance(G, 0));
  ListHndl L = getPathTo(G, 4);
  printf("Follow the path ");
  printList(L);
  return(0);
}
