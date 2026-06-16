#ifndef __ADJLIST_GRAPH_H__
#define __ADJLIST_GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/**
 *  @brief Vertex structure for the adjacency list graph.
 *  @struct s_Vetex
 *  @param id Pointer to the label of the vertex.
 *  @param visited Boolean flag indicating whether the vertex has been visited.
 *  @param adjacents Pointer to the list of adjacent vertices.
 *  @param indegree The number of incoming edges to the vertex.
 *  @param outdegree The number of outgoing edges from the vertex.
 *  @param degree The total degree of the vertex (indegree + outdegree).
 */
typedef struct s_Vetex
{
    char* id;        // Label of the vertex
    bool visited;    // Flag to indicate if the vertex has been visited
    List* adjacents; // List of adjacent vertices
    int indegree;    // Number of incoming edges
    int outdegree;   // Number of outgoing edges
    int degree;      // Total degree of the vertex
} Vertex;

/**
 *  @brief Graph structure for the adjacency list representation.
 *  @struct s_Graph
 *  @param vertices Pointer to the list of vertices in the graph.
 *  @param size The number of vertices in the graph.
 *  @note The graph is represented as a list of vertices, where each vertex has its 
 *  own list of adjacent vertices.
 */
typedef struct s_Graph
{
    List* vertices; // List of vertices in the graph
    int size;       // Number of vertices in the graph
} Graph;

Vertex* createVertex(char* id);
void    freeVertex(Vertex* vertex);
void    printVertex(Vertex* vertex);

Graph* createGraph(void);
void   freeGraph(Graph* graph);
void   addVertex(Vertex* vertex, Graph* graph);
void   addEdge(Vertex* v1, Vertex* v2, Graph* graph);
void   removeEdge(Vertex* v1, Vertex* v2, Graph* graph);
void   removeVertex(Vertex* vertex, Graph* graph);
void   printGraph(Graph* graph);

#endif // __ADJLIST_GRAPH_H__