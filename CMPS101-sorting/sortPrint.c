/******************************
 * By: Brandon Gomez (brlgomez)
 *****************************/

#include <stdio.h>
#include <stdlib.h>
#include "myinclude.h"
#include "heap.h"
#include "heapSort.h"
#include "insertionSort.h"

/*
  Prints the contents of the file in order using
  insertion sort and heap sort. The first number
  tells how many numbers are in the file.
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
	   heap[count + 1] = key;
           array[count] = key;
	   count++;
	   continue;	  
	}
      fclose(input);
      insertionSort(array, numOfKeys);
      heapSort(heap, numOfKeys);
      int i;
      printf("Insertion sort print:\n");
      for(i = 0; i < numOfKeys; i++)
	{
	  printf("%d ", array[i]);
	}
      printf("\nHeap sort print:\n");
      for(i = 1; i <= numOfKeys; i++)
	{
	  printf("%d ", heap[i]);
	}					
      printf("\n");
    }
}
