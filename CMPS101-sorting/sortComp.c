/******************************
 * By: Brandon Gomez (brlgomez)
 *****************************/

#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <stdlib.h>     
#include "myinclude.h"
#include "heap.h"
#include "heapSort.h"
#include "insertionSort.h"

/*
  This program check the time to run insertion sort
  and heap sort by checking a file. The first number is the 
  number of numbers in the text.
 */

int main(int argc, char **argv)
{
  char numKeys[100000];
  char buffer[100000];
  char *filename = argv[1];
  FILE *input = fopen(filename, "r");
  char c;
  int numOfKeys;
  int key;
  int count = 0;
  clock_t startTime,  duration;
  if(input != NULL)
    {
      c = fscanf(input, "%s", numKeys);
      numOfKeys = atoi(numKeys);
      int heap[numOfKeys + 1];
      int array[numOfKeys];
      while(c != EOF)
	{
	    c = fscanf(input, "%s", buffer);
            key = atoi(buffer);
	    heap[count+1] = key;
	    array[count] = key;
	    count++;  
	}
      fclose(input);
      startTime = clock();
      insertionSort(array, count);
      duration = clock() - startTime;
      printf ("Insertion Sort took %f seconds.\n", ((float) duration ) / CLOCKS_PER_SEC);
      startTime = clock();
      heapSort(heap, count);
      duration = clock() - startTime;
      printf ("Heap Sort took %f seconds.\n", ((float) duration ) / CLOCKS_PER_SEC);
      return(0);
    }
}
