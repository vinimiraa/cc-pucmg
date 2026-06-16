#ifndef __Graph_GRAPH_H__
#define __Graph_GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  @brief Adjacency Matrix structure.
 *  @struct s_Graph
 *  @param size The number of vertices in the graph.
 *  @param data Pointer to the adjacency matrix (2D array of booleans).
 *  @param isDirected Boolean flag indicating whether the graph is directed or undirected.
 *  @note The adjacency matrix is a square matrix where the element at row i and column j indicates whether 
 *  there is an edge from vertex i to vertex j.
 */
typedef struct s_Graph
{
    bool** data;      // Pointer to the adjacency matrix (2D array of booleans)
    int size;         // Number of vertices in the graph
    bool isDirected;  // Flag indicating whether the graph is directed or undirected
} Graph;

Graph* createGraph(int size, bool isDirected);
void   freeGraph(Graph* graph);
void   addEdge(int v1, int v2, Graph* graph);
void   removeEdge(int v1, int v2, Graph* graph);
void   printGraph(Graph* graph);
void   printAsAdjList(Graph* graph);


#endif // __Graph_GRAPH_H__