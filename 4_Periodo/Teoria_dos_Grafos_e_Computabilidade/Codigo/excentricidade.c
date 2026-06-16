#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// -------------------------------------- Queue

typedef struct s_Queue 
{
    int *items;
    int size;
    int max_size;
} Queue;

void free_Queue( Queue* q )
{
    if( q != NULL )
    {
        if( q->items != NULL ) {
            free( q->items );
        }
        free( q );
    }
}

void init_Queue( int value, Queue* q )
{
    if( q != NULL && q->items != NULL ) 
    {
        for( int i = 0; i < q->max_size; i = i + 1 ) {
            q->items[i] = value;
        }
    }
}

Queue* new_Queue( int max_size ) 
{
    Queue* q = (Queue*) malloc( sizeof(Queue) );
    if( q != NULL )
    {
        q->items = (int*) malloc( max_size * sizeof(int) );
        if( q->items != NULL ) {
            init_Queue( 0, q );
            q->max_size =  max_size;
            q->size = 0;
        } else {
            free_Queue( q );
        }
    }
    return q;
}

bool isEmpty( Queue* q ) {
    return ( q == NULL || q->size == 0 );
}

void enqueue( int value, Queue* q ) 
{
    if( q != NULL && q->items != NULL )
    {
        if( q->size < q->max_size ) 
        {
            q->items[q->size] = value;
            q->size++;
        }
    }
}

int dequeue( Queue *q ) 
{
    int value = -1;
    if( q != NULL && q->items != NULL )
    {
        if( q->size != 0 )
        {
            value = q->items[0];
            for( int i = 0; i < q->size-1; i = i + 1 ) {
                q->items[i] = q->items[i+1];
            }
            q->size--;
        }
    }
    return value;
}

// -------------------------------------- Util

void print_Array( char* label, int size, int* a )
{
    if( a != NULL )
    {
        printf( "%s - [ ", label );
        for( int i = 0; i < size; i = i + 1 ) {
            printf( "%d ", a[i] );
        }
        printf( "]\n" );
    }
}

// -------------------------------------- Eccentricity

int eccentricity( const int start, const int num_vertices, int graph[][MAX_VERTICES], bool debug ) 
{
    int x = 0;                             // Excentricidade, valor a ser calculado
    Queue* q = new_Queue( num_vertices );  // Fila
    int distance[MAX_VERTICES] = {0};      // Vetor com as distâncias de cada vértica
    bool visited[MAX_VERTICES] = {false};  // Vetor indicando se o vértice foi visitado ou não

    distance[start] = 0;                   // Inicia com a distância do vértice 'v' igual a 0
    enqueue( start, q );                   // Insere o vértice 'v' na fila
    visited[start] = true;                 // Marca o vértice 'v' como visitado
    
    while( isEmpty( q ) == false )                     // Enquanto a fila não estiver vazia
    {
        if( debug ) 
        {
            print_Array( "Grau", num_vertices, distance );
            print_Array( "Fila", q->size, q->items );
        }

        int v = dequeue( q );                          // Remove o vértice da fila 

        for( int u = 0; u < num_vertices; u = u + 1 )  // Para todo 'u' vizinho do vértice 'v' 
        {
            if( graph[v][u] && !visited[u] )           // Se o 'u' não foi visitada
            { 
                distance[u] = distance[v] + 1;         // Incrementa a distância do vértice 'u' em 1 unidade
                enqueue( u, q );                       // Insere 'u' na fila
                visited[u] = true;                     // Marca 'u' como visitado
            }
        }
    }
    free_Queue( q );

    // Calculando a excentricidade: o maior valor de distance[v]
    for( int i = 0; i < num_vertices; i = i + 1 ) 
    {
        if( distance[i] > x ) {
            x = distance[i];
        }
    }

    return x;
}

// -------------------------------------- Main

int main( void ) 
{
    int num_vertices = 9;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    /**
     *  G = (V,E), Simples e Não-Direcionado
     *  V = { A, B, C, D, E, F, G, H, I}
     *  E = { {A,B}, [B,C], {C,D}, {C,E}, {C,F}, {C,G}, {G,H}, {G,I} }
     */
    graph[0][1] = graph[1][0] = 1; // A - B
    graph[1][2] = graph[2][1] = 1; // B - C
    graph[2][3] = graph[3][2] = 1; // C - D
    graph[2][4] = graph[4][2] = 1; // C - E
    graph[2][5] = graph[5][2] = 1; // C - F
    graph[2][6] = graph[6][2] = 1; // C - G
    graph[6][7] = graph[7][6] = 1; // G - H
    graph[6][8] = graph[8][6] = 1; // G - I

    printf( "G = (V,E), Simples e Nao-Direcionado\n" );
    printf( "V = { A, B, C, D, E, F, G, H, I}\n" );
    printf( "E = { {A,B}, [B,C], {C,D}, {C,E}, {C,F}, {C,G}, {G,H}, {G,I} }\n" );
    printf( "|V| = %d\n", num_vertices );
    printf( "|E| = %d\n\n", 8 );

    printf( "Excentricidade (A) = %d\n", eccentricity( 0, num_vertices, graph, true ) );
    printf( "Excentricidade (B) = %d\n", eccentricity( 1, num_vertices, graph, false ) );
    printf( "Excentricidade (C) = %d\n", eccentricity( 2, num_vertices, graph, false ) );
    printf( "Excentricidade (D) = %d\n", eccentricity( 3, num_vertices, graph, false ) );
    printf( "Excentricidade (E) = %d\n", eccentricity( 4, num_vertices, graph, false ) );
    printf( "Excentricidade (F) = %d\n", eccentricity( 5, num_vertices, graph, false ) );
    printf( "Excentricidade (G) = %d\n", eccentricity( 6, num_vertices, graph, false ) );
    printf( "Excentricidade (H) = %d\n", eccentricity( 7, num_vertices, graph, false ) );
    printf( "Excentricidade (I) = %d\n", eccentricity( 8, num_vertices, graph, false ) );

    return 0;
}
