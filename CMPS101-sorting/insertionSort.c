/******************************
 * Looked on rosettacode for 
   insertion sort.
 *****************************/

#include "insertionSort.h"  /* contains the header file */
#include "myinclude.h"      /* Some C defines I routinely use */

void insertionSort(int keys[], int numKeys)
{
  int i;
  int j;
  for(i = 1; i < numKeys; i++)
    {
      int temp = keys[i];
      for(j = i; temp < keys[j - 1] && j > 0; j--)
	{
	  keys[j] = keys[j - 1];
	}
      keys[j] = temp;
    }
}
