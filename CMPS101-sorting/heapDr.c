/******************************
 * By: Brandon Gomez (brlgomez)
 *****************************/

/*

  The driver file for my heap.c file

 */

#include <stdio.h>
#include <stdlib.h>
#include "myinclude.h"
#include "heap.h"

int main()
{
  heapHndl heap = newHeap(16);
  insert(heap, 1);
  printf("max = 1 is %d\n", maxValue(heap));
  insert(heap, 6);
  printf("max = 6 is %d\n", maxValue(heap));
  insert(heap,74);
  printf("max = 74 is %d\n", maxValue(heap));
  insert(heap, 3);
  insert(heap, 99);
  printf("max = 99 is %d\n", maxValue(heap));
  insert(heap, 101);
  printf("max = 101 is %d\n", maxValue(heap));
  if(isFull(heap))
    {
      printf("Heap should not be full. The test failed\n");
    }
  else
    {
      printf("Heap is not full. Test worked\n");
    }
  if(isEmpty(heap))
    {
      printf("Heap is not empty. The test failed\n");
    }
  else
    {
      printf("Heap shouold not be empty. The test worked\n");
    }
  printf("The max value should be 101. It is %d \n",maxValue(heap));
  deleteMax(heap);
  printf("the max value should be 99. It is %d \n", maxValue(heap));
  deleteMax(heap);  
  printf("The max value should be 74. It is %d \n",maxValue(heap));
  deleteMax(heap);
  printf("Ths max value should be 6. It is %d \n",maxValue(heap));
  deleteMax(heap);
  printf("Ths max value should be 3. It is %d \n",maxValue(heap));
  deleteMax(heap);
  printf("Ths max value should be 1. It is %d \n",maxValue(heap));
  return(0);
}
