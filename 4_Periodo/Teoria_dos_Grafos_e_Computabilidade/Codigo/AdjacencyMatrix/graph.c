#include "graph.h"

// ----------------------------
// Graph Functions
// ----------------------------

/**
 *  @brief Checks if the graph exists and is valid.
 *  @param graph Pointer to the graph structure.
 *  @return true if the graph exists and is valid, false otherwise.
 */
bool _existsGraph(Graph* graph)
{
    return graph && graph->data;
}

/**
 *  @brief Creates a new graph with the specified number of vertices and directed/undirected flag.
 *  @param numOfVertexs The number of vertices in the graph.
 *  @param isDirected Boolean flag indicating whether the graph is directed or undirected.
 *  @return Pointer to the newly created graph structure, or NULL if memory allocation fails.
 */
Graph* createGraph(int numOfVertexs, bool isDirected)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    if(graph)
    {
        if(numOfVertexs > 0)
        {
            graph->data = (bool**) malloc(numOfVertexs * sizeof(bool*));
            for(int i = 0; i < numOfVertexs; i = i + 1)
            {
                graph->data[i] = (bool*) malloc(numOfVertexs * sizeof(bool));
            }

            if(graph->data)
            {
                for(int r = 0; r < numOfVertexs; r = r + 1)
                {
                    for(int c = 0; c < numOfVertexs; c = c + 1)
                    {
                        graph->data[r][c] = false;
                    }
                }
                graph->size = numOfVertexs;
                graph->isDirected = isDirected == true;
            }
        }
    }
    return graph;
}

/**
 *  @brief Frees the memory allocated for the graph structure and its adjacency matrix.
 *  @param graph Pointer to the graph structure to be freed.
 */
void freeGraph(Graph* graph)
{
    if(graph)
    {
        if(graph->data)
        {
            for(int i = 0; i < graph->size; i = i + 1)
            {
                free(graph->data[i]);
                graph->data[i] = NULL;
            }
            free(graph->data);
            graph->data = NULL;
        }
        free(graph);
        graph = NULL;
    }
}

/**
 *  @brief Adds an edge between two vertices in the graph.
 *  @param v1 The first vertex.
 *  @param v2 The second vertex.
 *  @param graph Pointer to the graph structure.
 *  @note If the graph is undirected, the edge is added in both directions.
 */
void addEdge(int v1, int v2, Graph* graph)
{
    if(_existsGraph(graph))
    {
        if(v1 >= 0 && v1 < graph->size && v2 >= 0 && v2 < graph->size)
        {
            graph->data[v1][v2] = 1;
            if(graph->isDirected == false)
                graph->data[v2][v1] = 1;
        }
    }
}

/**
 *  @brief Removes an edge between two vertices in the graph.
 *  @param v1 The first vertex.
 *  @param v2 The second vertex.
 *  @param graph Pointer to the graph structure.
 *  @note If the graph is undirected, the edge is removed in both directions.
 */
void removeEdge(int v1, int v2, Graph* graph)
{
    if(_existsGraph(graph))
    {
        if(v1 >= 0 && v1 < graph->size && v2 >= 0 && v2 < graph->size)
        {
            graph->data[v1][v2] = 0;
            if (graph->isDirected == false)
                graph->data[v2][v1] = 0;
        }
    }
}

/**
 *  @brief Prints the adjacency matrix representation of the graph.
 *  @param graph Pointer to the graph structure.
 *  @note The adjacency matrix is printed in a tabular format, where each row represents a vertex and 
 *  each column represents the edges to other vertices. A value of 1 indicates an edge exists, while 0
 *  indicates no edge.
 */
void printGraph(Graph* graph)
{
    if(_existsGraph(graph))
    {
        printf("   ");
        for(int c = 0; c < graph->size; c = c + 1) {
            printf("%d: ", c);
        }
        printf("\n");

        for(int r = 0; r < graph->size; r = r + 1)
        {
            printf("%d: ", r);
            for(int c = 0; c < graph->size; c = c + 1)
            {
                printf("%d  ",  graph->data[r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

/**
 *  @brief Prints the adjacency list representation of the graph.
 *  @param graph Pointer to the graph structure.
 */
void printAsAdjList(Graph* graph)
{
    if(_existsGraph(graph))
    {
        for(int r = 0; r < graph->size; r = r + 1)
        {
            printf("%d: ", r);
            for(int c = 0; c < graph->size; c = c + 1)
            {
                if(graph->data[r][c])
                {
                    printf("%d ", c);
                }
            }
            printf("\n");
        }
    }
}
