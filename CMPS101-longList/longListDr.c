#include "myinclude.h"

#include "longList.h"

int main()
{
  ListHndl FirstList;
  ListHndl SecList;

  FirstList = NULL;
  SecList = NULL;

  FirstList = newList ();
  SecList = newList ();
    
  if (isEmpty(FirstList) ) {printf ("IsEmpty test worked \n");}
  else {printf("IsEmpty test not ok \n"); }
    
  if (isEmpty(SecList) ) {printf ("IsEmpty test worked \n");}
  else {printf("IsEmpty test not ok \n"); }

  insertAtFront(FirstList, 10);
  insertAtFront(FirstList, 12);
  insertAtFront(FirstList, 11);
  if (isEmpty(FirstList) ) {printf ("IsEmpty test failed \n");}
  else {printf("IsEmpty test ok \n"); }

  printList(NULL, FirstList);
  printf("%lu ", getFirst(FirstList));
  printf("%lu ", getLast(FirstList));
  printf("%lu\n ", getCurrent(FirstList));

  return(0);  
}
