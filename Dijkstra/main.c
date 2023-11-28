

// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
 
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
 
// Number of vertices in the graph
#define V 9

int minDistance(int d[], bool S[]);
void printSolution(int d[]);
void printArray(int *arr, int n);
void dijkstra(int graph[V][V], int src);

// driver's code
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    // Function call
    dijkstra(graph, 0);
 
    return 0;
}
 
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int d[], bool S[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (S[v] == false && d[v] <= min)
            min = d[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance
// array
void printSolution(int d[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, d[i]);
}
 
// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int d[V]; // holds the shortest
        // distance from src to i
 
    bool S[V]; // S[i] will be true if vertex i is
            // included in shortest path tree
            // or shortest distance from src to i is finalized
    
    int pi[V]; // store the predecessors/parent for each vertex
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        d[i] = INT_MAX, S[i] = false, pi[i] = -1; //INT_MAX is a macro containing the highest possible val of int
 
    // Distance of source vertex from itself is always 0
    d[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(d, S);
 
        // Mark the picked vertex as processed
        S[u] = true;
 
        // Update d value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            // Update d[v] only if is not in S,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of d[v]
            if (!S[v] && graph[u][v]  &&  d[u] != INT_MAX  &&  d[u] + graph[u][v] < d[v])
            {
                d[v] = d[u] + graph[u][v];
                pi[v] = u; // Update the predecessor for vertex v
            }
    }
 
    // print the constructed distance array
    printSolution(d);
    printArray(pi, V);
}

void printArray(int *arr, int n) {
    printf("Vertex \t\t Predecessor Index\n");
    for(int i=0; i<n; i++) {
        printf("%d \t\t %d\n", i, *(arr+i));
    }
    printf("\n");
}
 

