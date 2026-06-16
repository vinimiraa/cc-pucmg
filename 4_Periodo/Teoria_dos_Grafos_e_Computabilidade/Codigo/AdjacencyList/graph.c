#include "graph.h"
#include <string.h>

// ----------------------------
// Error Handling
// ----------------------------

/**
 *  @brief Error codes for graph operations.
 *  These codes are used to identify specific errors that may occur during graph operations.
 */
enum _errorCodes
{
    ERROR_VERTEX_MEMORY_ALLOCATION = 1,
    ERROR_GRAPH_MEMORY_ALLOCATION,
    ERROR_FREE_GRAPH,
    ERROR_NULL_GRAPH,
    ERROR_NULL_VERTEX,
    ERROR_EMPTY_GRAPH
};

/**
 *  @brief Prints error messages based on the error code.
 *  @param errorCode The error code to be printed.
 */
void _printErrorGraph(int errorCode)
{
    switch(errorCode)
    {
        case ERROR_VERTEX_MEMORY_ALLOCATION:
            fprintf(stderr, "Error: Memory allocation failed for new vertex.\n");
            break;
        case ERROR_GRAPH_MEMORY_ALLOCATION:
            fprintf(stderr, "Error: Memory allocation failed for new graph.\n");
            break;
        case ERROR_FREE_GRAPH:  
            fprintf(stderr, "Error: Attempt to free a NULL graph.\n");
            break;
        case ERROR_NULL_GRAPH:
            fprintf(stderr, "Error: Attempt to operate on a NULL graph.\n");
            break;
        case ERROR_NULL_VERTEX:
            fprintf(stderr, "Error: Attempt to operate on a NULL vertex.\n");
            break;
        case ERROR_EMPTY_GRAPH:
            fprintf(stderr, "Error: Attempt to operate on an empty graph.\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown error code %d.\n", errorCode);
    }
}

// ----------------------------
// Other Functions
// ----------------------------

/**
 *  @brief Compares two strings for equality.
 *  @param a The first string.
 *  @param b The second string.
 *  @return 0 if equal, -1 if a < b, 1 if a > b.
 */
int _compareString(void* a, void* b)
{
    char* strA = (char*)a;
    char* strB = (char*)b;
    return strcmp(strA, strB);
}

/**
 *  @brief Prints the id of a vertex.
 *  @param data The vertex to be printed.
 */
void _printVertexId(void* data)
{
    Vertex* vertex = (Vertex*)data;
    printf("%s ", vertex->id);
}

// ----------------------------
// Vertex Functions
// ----------------------------

/**
 *  @brief Creates a new vertex with the given id.
 *  @param id The id of the vertex.
 *  @return A pointer to the newly created vertex.
 */
Vertex* createVertex(char* id)
{
    Vertex* newVertex = (Vertex*) malloc(sizeof(Vertex));
    if(newVertex == NULL)
    {
        _printErrorGraph(ERROR_VERTEX_MEMORY_ALLOCATION);
    }
    else
    {
        newVertex->id = strdup(id);
        newVertex->adjacents = listCreate();
        newVertex->indegree = 0;
        newVertex->outdegree = 0;
        newVertex->degree = 0;
        newVertex->visited = false;
    }
    return newVertex;
}

/**
 *  @brief Frees the memory allocated for the vertex and its adjacent vertices.
 *  @param vertex The vertex to be freed.
 */
void freeVertex(Vertex* vertex)
{
    if(vertex == NULL)
    {
        _printErrorGraph(ERROR_NULL_VERTEX);
    }
    else
    {
        listFree(vertex->adjacents);
        free(vertex->id);
        free(vertex);
        vertex = NULL;
    }
}

void printVertex(Vertex* vertex)
{
    if(vertex == NULL)
    {
        _printErrorGraph(ERROR_NULL_VERTEX);
    }
    else
    {
        printf("Vertex ID: %s\n", vertex->id);
        printf("Indegree.: %d\n", vertex->indegree);
        printf("Outdegree: %d\n", vertex->outdegree);
        printf("Degree...: %d\n", vertex->degree);
        printf("Visited..: %s\n", vertex->visited ? "true" : "false");
    }
}

// ----------------------------
// Graph Functions
// ----------------------------

/**
 *  @brief Creates a new graph and initializes its vertices and size.
 *  @return A pointer to the newly created graph.
 */
Graph* createGraph(void)
{
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    if(newGraph == NULL)
    {
        _printErrorGraph(ERROR_GRAPH_MEMORY_ALLOCATION);
    }
    else
    {
        newGraph->vertices = listCreate();
        newGraph->size = 0;
    }
    return newGraph;
}

/**
 *  @brief Frees the memory allocated for the graph and its vertices.
 *  @param graph The graph to be freed.
 */
void freeGraph(Graph* graph)
{
    if(graph == NULL)
    {
        _printErrorGraph(ERROR_FREE_GRAPH);
    }
    else
    {
        listFree(graph->vertices);
        free(graph);
        graph = NULL;
    }
}

/**
 *  @brief Adds a vertex to the graph with the given data and id.
 *  @param graph The graph to which the vertex will be added.
 *  @param vertex The vertex to be added.
 */
void addVertex(Vertex* vertex, Graph* graph)
{
    if(graph == NULL)
    {
        _printErrorGraph(ERROR_NULL_GRAPH);
    }
    else if(vertex == NULL)
    {
        _printErrorGraph(ERROR_NULL_VERTEX);
    }
    else
    {
        listInsertAtEnd(vertex, graph->vertices);
        graph->size++;
    }
}

/**
 *  @brief Adds an edge between two vertices in the graph.
 *  @param v1 The origin vertex.
 *  @param v2 The destination vertex.
 *  @param graph The graph to which the edge will be added.
 */
void addEdge(Vertex* v1, Vertex* v2, Graph* graph)
{
    if(graph == NULL)
    {
        _printErrorGraph(ERROR_NULL_GRAPH);
    }
    else if(v1 == NULL || v2 == NULL)
    {
        _printErrorGraph(ERROR_NULL_VERTEX);
    }
    else
    {
        listInsertAtEnd(v2, v1->adjacents);
        v1->outdegree++;
        v2->indegree++;
        v1->degree++;
        v2->degree++;
    }
}

/**
 *  @brief Removes an edge between two vertices in the graph.
 *  @param v1 The origin vertex.
 *  @param v2 The destination vertex.
 *  @param graph The graph from which the edge will be removed.
 */
void removeEdge(Vertex* v1, Vertex* v2, Graph* graph)
{
    if(graph == NULL)
    {
        _printErrorGraph(ERROR_NULL_GRAPH);
    }
    else if(v1 == NULL || v2 == NULL)
    {
        _printErrorGraph(ERROR_NULL_VERTEX);
    }
    else
    {
        int index = listSearch(v1->adjacents, v2, _compareString);
        if(index != -1)
        {
            listRemoveAt(index, v1->adjacents);
            v1->outdegree--;
            v2->indegree--;
            v1->degree--;
            v2->degree--;
        }
    }
}

/**
 *  @brief Removes a vertex from the graph and frees its memory.
 *  @param vertex The vertex to be removed.
 *  @param graph The graph from which the vertex will be removed.
 */
void removeVertex(Vertex* vertex, Graph* graph)
{
    if(graph == NULL)
    {
        _printErrorGraph(ERROR_NULL_GRAPH);
    }
    else if(vertex == NULL)
    {
        _printErrorGraph(ERROR_NULL_VERTEX);
    }
    else
    {
        // Remove all edges to this vertex from other vertices
        for(int i = 0; i < graph->size; i = i + 1)
        {
            Vertex* currentVertex = (Vertex*)listGetAt(i, graph->vertices);
            if(currentVertex != NULL && currentVertex != vertex)
            {
                removeEdge(currentVertex, vertex, graph);
            }
        }
        // Remove the vertex from the graph
        int index = listSearch(graph->vertices, vertex, _compareString);
        if(index != -1)
        {
            listRemoveAt(index, graph->vertices);
        }

        freeVertex(vertex);
        graph->size--;
    }
}

/**
 *  @brief Prints the graph and its vertices using the provided print function.
 *  @param graph The graph to be printed.
 *  @param printFunc The function used to print the vertex data.
 */
void printGraph(Graph* graph)
{
    if(graph == NULL)
    {
        _printErrorGraph(ERROR_NULL_GRAPH);
    }
    else if(graph->size == 0)
    {
        _printErrorGraph(ERROR_EMPTY_GRAPH);
    }
    else
    {
        for(int i = 0; i < graph->size; i++)
        {
            Vertex* vertex = (Vertex*)listGetAt(i, graph->vertices);
            printf("Vertex %s: ", vertex->id);
            listPrint(vertex->adjacents, _printVertexId);
        }
    }
}
