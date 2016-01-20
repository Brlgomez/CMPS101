/******************************
 * By: Brandon Gomez (brlgomez)
 *     Dylan Ma (dylma)
 *****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "List.h"
#include "graph.h"
#include "myinclude.h"

int main(int argc, char** argv)
{
  int numVerts;
  int numQueries;
  int from;
  char edge[1024];
  int to;
  int start;
  int end;
  char *filename = argv[1];
  FILE *input = fopen(filename, "r");
  int i = 0;
  char *c;
  if(input != NULL)
    {
      fscanf(input, "%d", &numVerts);
      fscanf(input, "%d", &numQueries);
      /*printf("%d %d\n", numVerts, numQueries);*/
      Graph G = newGraph(numVerts);
      for(i = 0; i < numVerts; i++)
	{
	  fscanf(input, "%d", &from);
	  /*printf("%d ", from);*/
	  fgets(edge, 1024, input);  
	  c = strtok(edge, " \n");  
	  while(c != NULL)
	    {
	      addEdge(G, from, atoi(c));
	      c = strtok(NULL, " \n");
	    }
	}
      for(i = 0; i < numQueries; i++)
	{
	  fscanf(input, "%d", &start);
	  fscanf(input, "%d", &end);
	  doBFS(G, start);
	  if(getDistance(G, end) > 0)                                                 
	    {                                                                         
	      printf("The shortest path from %d to %d requires %d edges:\n",          
		     start, end, getDistance(G, end));                                
	      ListHndl L = getPathTo(G, end);                                         
	    }                                                                         
	  else                                                                        
	    {                                                                         
	      printf("No path from %d to %d exists.\n", start, end);                  
	    } 
	}
    }
  fclose(input);
  return(0);
}
