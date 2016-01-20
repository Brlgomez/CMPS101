/*******************************
 * By: Brandon Gomez (brlgomez)
 * With help from MSI Leader
 * on insering logic
 *****************************/

/******************************
 * This program, store, takes in
 * a formated file and store
 * the book ID to the appropraite
 * customer.
 ******************************/
 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "myinclude.h"
#include "longList.h"

int exit_status = EXIT_SUCCESS;
char *prog_name = NULL;

int main(int argc, char **argv)
{
  prog_name = basename (argv[0]);
  char buffer[64];  
  char custBuf[64];   
  char purBuf[64];
  char *filename = argv[1];
  FILE *input = fopen(filename, "r");
  /* keeps track of how many items are in the file */
  int count = 0; 
  int numOfCust = 0;
  int numOfPur = 0;
  /* for for loops */
  int i;
  int j;
  char c;
  ListHndl * custBookList;
  if (input != NULL) 
    {
      /*
       * if count == 0 numOfCust is obtained
       * if count == 1 numOfPur is obtained
       * if count > 1 bookId is inserted to the repected cust
       */
      do
	{
	if(count == 0)
	  {
	    c = fscanf(input, "%s", custBuf);
	    numOfCust = atoi(custBuf);
	    if(numOfCust == 0)
	      {
		printf("The first input was not a illegal integer\n");
		return(1);
	      }
	    custBookList = malloc(sizeof(ListHndl) * (numOfCust + 1));
	    for(i = 0; i < numOfCust + 1; i++)
	      {
		custBookList[i] = newList();
	      }
	  }
	if(count == 1)
          {
            c = fscanf(input, "%s", purBuf);
	    numOfPur = atoi(purBuf);
	    if(numOfPur == 0)
              {
                printf("The second input was not a illegal integer\n");
                return(1);
              }
          }
	if(count > 1)
	  {
	    int custId;
	    long bookId;
	    c = fscanf(input, "%d %ld", &custId, &bookId);
	    if(custId == 0)
	      {
		printf("There was an illegal input in the file\n");
                return(1);
	      }
	    if(bookId == 0)
	      { 
                printf("There was an illegal input in the file\n");
                return(1);
              }
	    insertAtFront(custBookList[custId], bookId);
	  }
	count++;
      } 
      while(c != EOF);
      /* print statements */
      printf("customer#   books purchased\n");
      for(j = 1; j < numOfCust + 1; j++)
	{
	  printf("%d           ", j);
	  printList(input, custBookList[j]);
	}
      /* free statements */
      for(j = 1; j < numOfCust + 1; j++)
	{
	  /* while(!isEmpty(custBookList[j]))
	    {
	      deleteFirst(custBookList[j]);
	      }*/
	  freeList(&custBookList[j]);
	}
      fclose (input);
    }
  /* if file not found */
  else 
    {
      exit_status = EXIT_FAILURE;
      fflush (NULL);
      fprintf (stderr, "%s: %s: %s\n", prog_name,
	       filename, strerror (errno));
      fflush (NULL);
    }

  return exit_status;
}
