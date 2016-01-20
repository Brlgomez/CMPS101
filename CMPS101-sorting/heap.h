/******************************
 * By: Brandon Gomez (brlgomez)
 *****************************/

typedef struct heapStruct * heapHndl;

/*** Constructors-Destructors ***/

heapHndl newHeap (int maxSize); 

void freeHeap (heapHndl H);

/*** Access functions ***/

Boolean isFull(heapHndl H);

Boolean isEmpty(heapHndl H);

int maxValue(heapHndl H);

void deleteMax(heapHndl H);

void insert(heapHndl H, int priority);
