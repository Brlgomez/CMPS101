/******************************
 * By: Brandon Gomez (brlgomez)
 *****************************/

/* 
 *     Header (.h) file for list-of-longs ADT
 *
 * This contains the operations and types exported
 * by the module.  The module implements a the ADT "list"
 * using dynamic memory allocation. The state of a list 
 * is a (possibly empty) sequence of longs.
 *
 * USE OF THIS ADT ALSO REQUIRES THAT "myinclude.h" be
 * included.
 */

/*
 * The following is the List handle type
 * Users should declare (and initialize to null)
 * one variable of type "ListHndl" for each stack they
 * want to have.  After declaration (and initialization
 * to null), the "newList()" procedure must be called before
 * any List operations can be performed.
 */

typedef struct ListStruct*  ListHndl;

/*
 * The procedure "newList()" creates a new list object
 * and returns a pointer to it.  This function should be used
 * to initialize each list before any other operations are performed
 * on that list.  There is no precondition.
 * The postcondition is that the stack is initialized to an empty stack.
 */

ListHndl newList();

/* 
 * The procedure "freeList" should be called once on each
 * stack when the stack is no longer. Its purpose is to free up 
 * the storage used by the list.  
 * Precondition: List has been initialized by "newList",
 *               List need not be empty.
 * Postcondition: List is set to null
 * Note: "Boolean" is defined in myinclude.h
 */

void freeList(ListHndl* List);

/* The access function isEmpty returns true if the sequence
 * represented by the list is the empty sequence.
 * Precondition: none;
 * Postcondition: returns true if the sequence is empty,
 *                and false otherwise.
 */

Boolean isEmpty(ListHndl List);

/* The access function offEnd returns true if the sequence                              
 * represented by the list is the empty sequence.                                       
 * Precondition: List cannot be NULL                                                     
 * Postcondition: returns true if the current is empty,                                 
 *                and false otherwise.                                                   
 */

Boolean offEnd(ListHndl List);

/* The access function atFirst returns true if the sequence                              
 * represented by the list is empty sequence.                                  
 * Precondition: List cannot be NULL                                            
 * Postcondition: returns true if the current equals first,                             
 *                and false otherwise.                                                   
 */

Boolean atFirst(ListHndl List);

/* The access function atLast returns true if the sequence                              
 * represented by the list is the empty sequence.                                        
 * Precondition: List cannot be NULL                                                     
 * Postcondition: returns true if the current equals last,                             
 *                and false otherwise.                                                   
 */

Boolean atLast(ListHndl List);

/* The access function getFirst returns the number at first                              
 * Precondition: isEmpty cannot be true                                                  
 * Postcondition: returns the long at the first position                                 
 */

long getFirst(ListHndl List);

/* The access function getFirst returns the number at last                              
 * Precondition: isEmpty cannot be true                                                  
 * Postcondition: returns the long at the last position                                 
 */

long getLast(ListHndl List);

/* The access function getFirst returns the number at current                            
 * Precondition: isEmpty cannot be true                                                  
 * Postcondition: returns the long at the current position                               
 */

long getCurrent(ListHndl List);

/* The manipulation procedure makeEmpty deletes all elements from
 * the list
 * precondition: none
 * postcondition: isEmpty and offEnd must be true
 */

void makeEmpty(ListHndl List);

/* The manipulation procedure changes the current to 
 * where the first is.                                                                   
 * precondition: isEmpty must be false                                                  
 * postcondition: offEnd must be false                                        
 */

void moveFirst(ListHndl List);

/* The manipulation procedure changes the current to                                     
 * where the last is.                                                                   
 * precondition: isEmpty must be false                                                   
 * postcondition: offEnd must be false                                                   
 */

void moveLast(ListHndl List);

/* The manipulation procedure changes the current to                                     
 * one before it.                                                                   
 * precondition: offEnd must be false                                                   
 * postcondition: offEnd and atFirst must be true                                      
 */

void movePrev(ListHndl List);

/* The manipulation procedure changes the current to                                     
 * one after it.                                                                        
 * precondition: offEnd must be false                                                    
 * postcondition: offEnd and atLast must be true                                        
 */

void moveNext(ListHndl List);

/* The manipulation procedure inserts a new element
 * before the first.
 * precondition: none                                                    
 * postcondition: isEmpty must be false and it does
 * not change the current element.
 */

void insertAtFront(ListHndl List, long data);

/* The manipulation procedure inserts a new element                                      
 * before the last.                                                                     
 * precondition: none                                                                    
 * postcondition: isEmpty must be false and it does                                      
 * not change the current element.                                                       
 */

void insertAtBack(ListHndl List, long data);

/* The manipulation procedure inserts a new element                                      
 * before the current.                                                                  
 * precondition: none                                                                    
 * postcondition: isEmpty must be false and it does                                      
 * not change the current element.                                                       
 */

void insertBeforeCurrent(ListHndl List, long data);

/* The manipulation procedure deletes the first element.                                
 * precondition: isEmpty must be false                                                  
 * postcondition: none                                                       
 */

void deleteFirst(ListHndl List);

/* The manipulation procedure deletes the last element.                                 
 * precondition: isEmpty must be false                                                   
 * postcondition: none                                                                   
 */

void deleteLast(ListHndl List);

/* The manipulation procedure deletes the current element.                               
 * precondition: isEmpty must be false                                                   
 * postcondition: none                                                                   
 */

void deleteCurrent(ListHndl List);

/* The procedure prints out the list.                                  
 * precondition: none                                                   
 * postcondition: none                                                                   
 */

void printList(FILE* out, ListHndl List);
