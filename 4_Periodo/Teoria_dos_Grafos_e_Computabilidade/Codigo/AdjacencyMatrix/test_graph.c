#include "graph.h"

int main(void)
{
    Graph* graph = createGraph(5, false);

    addEdge(0, 1, graph);
    addEdge(0, 2, graph);
    addEdge(1, 2, graph);
    addEdge(2, 3, graph);
    addEdge(3, 4, graph);

    printf("Adjacency Matrix:\n");
    printGraph(graph);

    printf("Adjacency List:\n");
    printAsAdjList(graph);

    removeEdge(0, 1, graph);
    printf("\nAfter removing edge (0, 1):\n");
    printGraph(graph);

    freeGraph(graph);

    return 0;
}