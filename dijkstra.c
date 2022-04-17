#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
 
// Number of vertices in the graph
#define V 11
 
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance array
int printSolution(int dist[], int n,int exp)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i+1, dist[i]);
    printf("Expanding Node %d times\n",exp);
}
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int exp = 0;
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++){
            exp++;
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            
    }
 
    // print the constructed distance array
    printSolution(dist, V,exp);
}
 
// driver program to test above function
int main()
{
/* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 2, 8, 1, 0, 0, 0, 0, 0, 0, 0 },
                        { 2, 0, 6, 0, 1, 0, 0, 0, 0, 0, 0 },
                        { 8, 6, 0, 7, 5, 1, 2, 0, 0, 0, 0 },
                        { 1, 0, 7, 0, 0, 0, 9, 0, 0, 0, 0 },
                        { 0, 1, 5, 0, 0, 3, 0, 2, 9, 0, 0 },
                        { 0, 0, 1, 0, 3, 0, 4, 0, 6, 0, 0 },
                        { 0, 0, 2, 9, 0, 4, 0, 0, 3, 1, 0 },
                        { 0, 0, 0, 0, 2, 0, 0, 0, 7, 0, 9 },
                        { 0, 0, 0, 0, 9, 6, 3, 7, 0, 1, 2 },
                        { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 4 },
                        { 0, 0, 0, 0, 0, 0, 0, 9, 2, 4, 0 } 
                    };

    double time_spent = 0.0;
 
    clock_t begin = clock();
    
    // do some stuff here
    dijkstra(graph, 0);

    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
    
 
    return 0;
}