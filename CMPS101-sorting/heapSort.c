/******************************
 * By: Brandon Gomez (brlgomez)
 *****************************/

#include "myinclude.h" /* Some C defines I routinely use */
#include "heapSort.h"  /* contains the header file */
#include "heap.h"      /* contains the ADT of heap */

/* 
     Code given by the professor
     It takes the array and inserts it
     into a heap.
     It then puts the max of the heap back 
     into the array, giving it a sorted order.
     n = number of elements in A;
     H = newHeap(n);
     for each element x in A
           insert(H, x);
     for i=ndownto1do
         SortedA[i] = maxValue(H);
         deleteMax(H);
*/

void heapSort(int keys[], int numKeys)
{
  int i;
  int n = numKeys;
  heapHndl heap = newHeap(n);
  for(i = 1; i <= n; i++)
    {
      insert(heap, keys[i]);
    }
  for(i = n; i >= 1; i--)
    {
      int max = maxValue(heap);
      keys[i] = max;
      deleteMax(heap);
    }
   freeHeap(heap);
}
