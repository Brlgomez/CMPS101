/******************************
 * By: Brandon Gomez (brlgomez)
 *****************************/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>  
#include <assert.h>
#include "myinclude.h"
#include "intstack.h"

int main()
{ 
  printf("Input a positive number to convert to binary");
  printf("\n");
  int input;
  int scan = scanf("%d", &input);
  int original = input;
  StackHndl Stack;
  Stack = NULL;
  Stack = NewStack();
  scan += 0;

  if(input >= 0)
  {
    if(input == 0)
    {
      Push(Stack, 0);
    }
    while(input > 0)
    {
      if (input%2 != 0)
      {
        Push(Stack, 1);
      }
      else
      { 
        Push(Stack, 0);
      }
      input = input/2;
    }
    printf("Decimal %d is ", original);
    while(!IsEmpty(Stack))
    {
      printf("%d", Top(Stack));
      Pop(Stack);
    }
    printf(" in binary.");
  }

  else
  {
    printf("The number inputed is not positive"); 
  }
  FreeStack(&Stack);
  printf("\n");
  return(0);
}
