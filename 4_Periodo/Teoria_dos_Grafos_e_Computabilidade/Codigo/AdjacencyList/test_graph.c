#include "graph.h"
#include "list.h"

void _printVertexId2(void* data)
{
    Vertex* vertex = (Vertex*)data;
    printf("%s ", vertex->id);
}

int compareInt(void* a, void* b)
{
    int *intA = (int*)a;
    int *intB = (int*)b;
    return (*intA == *intB) ? 0 : (*intA < *intB) ? -1 : 1;
}

int main(void)
{
    Graph* graph = createGraph();

    Vertex* v1 = createVertex("A");
    Vertex* v2 = createVertex("B");
    Vertex* v3 = createVertex("C");
    Vertex* v4 = createVertex("D");

    addVertex(v1, graph);
    addVertex(v2, graph);
    addVertex(v3, graph);
    addVertex(v4, graph);

    addEdge(v1, v2, graph); addEdge(v2, v1, graph);
    addEdge(v1, v3, graph); addEdge(v3, v1, graph);
    addEdge(v2, v4, graph); addEdge(v4, v2, graph);
    addEdge(v3, v4, graph); addEdge(v4, v3, graph);

    printf("Graph:\n");
    printGraph(graph);

    removeEdge(v1, v2, graph);
    printf("Graph after removing edge (A, B):\n");
    printGraph(graph);

    removeVertex(v3, graph);
    printf("Graph after removing vertex (C):\n");
    printGraph(graph);
    
    freeGraph(graph);
    
    return 0;
}