/******************************
 * By: Brandon Gomez (brlgomez)
   with help from my MSI tutor
   on deleteMax. I was missing 
   one case.
 *****************************/

/* 
 *     Source code (.c) file for heap ADT
 *
 * This contains the implementation of the operations and types 
 * exported by the heap.h file.
 */

#include <assert.h>     /* This allows me to use the "assert" macro */
#include "myinclude.h"  /* Some C defines I routinely use */
#include "heap.h"       /* The ADT header file */

/*
  The file heap.h contains the following:
 
  heapHndl newHeap (int maxSize); 
  void freeHeap (heapHndl H);
  Boolean isFull(heapHndl H);
  Boolean isEmpty(heapHndl H);
  int maxValue(heapHndl H);
  void deleteMax(heapHndl H);
  void insert(heapHndl H, int priority);
*/

struct heapStruct
{
  int maxSize;
  int *data;
  int currSize;
}heapStruct;

/*** Constructors-Destructors ***/

heapHndl newHeap (int maxSize)
{
  heapHndl newHeap;
  newHeap = malloc(sizeof(struct heapStruct));
  newHeap->data = malloc(sizeof(int)*maxSize);
  newHeap->maxSize = maxSize;
  newHeap->currSize = 0;
  return (newHeap);
}

void freeHeap (heapHndl H)
{
  free(H->data);
  free(H);
}

/*** Access functions ***/

/* returns true if the heap is full else returns false */
Boolean isFull(heapHndl H)
{
  return (H->currSize == H->maxSize);
}

/* returns true if the heap is empty else returns false */
Boolean isEmpty(heapHndl H)
{
  assert (H != NULL);
  
  return (H->currSize == 0);
}

/* returns the top of the heap, which should be the max value.
   The heap cannot be empty */
int maxValue(heapHndl H)
{
  assert (H != NULL);
  
  return (H->data[1]);
}

/* Deletes the top of the heap by swap the 1 and last elements
   and then sorting the new top back to the bottom
   The heap cannot be empty */
void deleteMax(heapHndl H)
{
  
  assert(H != NULL);
 
  swap(H, 1, H->currSize);
  H->data[H->currSize] = -1;
  H->currSize--;  
  int parent = 1;
  while(parent < H->currSize)
    {
      int left = parent * 2;
      int right = parent * 2 + 1;
      int child;
      if(left > H->currSize)
        {
	   break;
	}
      else if(left <= H->currSize && right > H->currSize)
	{
	  if(H->data[left] >= H->data[parent])
	    {
	      swap(H, left, parent);
	      parent = left;
	      continue;
	    }
	  else
	    {
	      break;
	    }
	}
      if(H->data[left] >= H->data[right])
	{
	  child = left;
	}
      else
	{
	  child = right;
	}
      if(H->data[child] >= H->data[parent])
	{
	  swap(H, child, parent);
	  parent = child;
	}
      else
	{
	  break;
	}
    }
}

/* adds a new elememt into the heap.
   It adds it by creating a new element on the end of the 
   heap and then swaping places with the parent
   if it needs swapping
   The heap cannot be full */
void insert(heapHndl H, int priority)
{ 
  assert(isFull(H) != TRUE);

  H->currSize++;
  H->data[H->currSize] = priority;
  int i;
  for(i = H->currSize; i > 1; i = i/2)
    {
      int upper = i/2;
      if(H->data[i] <= H->data[upper])
	{
	  break;
	}
      swap(H, i, upper);
    }
}

/* This method swaps two elements from the data array */
void swap(heapHndl H, int i, int j)
{
  int temp = H->data[i];
  H->data[i] = H->data[j];
  H->data[j] = temp;
}
