/******************************
 * By: Brandon Gomez (brlgomez)
 *     Dylan Ma (dylma)
 *****************************/

/* 
 *     Header (.h) file for the graph ADT
 *    Uses implementations of the list ADT using list.h
 */

typedef struct GraphStruct *Graph;

/*
 * creates a new graph with n vertices numbered 
 * 0 to n - 1 and no edges and returns a handle to it.
 * PRE: none
 * POST: Initialized graph with all vertices color white,
 *  distance infinity, and parents null.
 */

Graph newGraph(int n);

/*
 * adds the edge (from, to) to the graph.
 * PRE: graph exists.
 * POST: none.
 */

void addEdge(Graph G, int from, int to);

/*
 * frees the storage used by a no longer needed 
 * Graph ADT object.
 * PRE: graph exist.
 * POST: graph is freed.
 */

void freeGraph(Graph G);

/*
 * performs BFS and updates the graph’s parent and distance 
 * arrays. This will erase the results of any previous BFS.
 * PRE: graph has at least 1 vert.
 * POST: all verts are visited and are black.
 */

void doBFS(Graph G, int source);

/*
 * return the number of edges in the shortest path from the 
 * last BFS source to the destination. returns NULL if no path.
 * PRE: graph exist.
 * POST: returns NULL or int.
 */

int getDistance(Graph G, int destination);

/*
 * return a List containing the path from the last doBFS source 
 * to the destination, or a null pointer if no such path exists.
 * PRE: graphs or list exists
 * POST: none
 */

ListHndl getPathTo(Graph G, int destination);

/*
 * For debugging purposes.
 */

void printGraph(Graph G);

void printBFSTree(ListHndl L);
