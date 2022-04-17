#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <queue>
using namespace std; 
// Number of vertices in the graph
#define V 11
#define pii pair<int,int>
 
// A utility function to print the constructed distance array
// int printSolution(int dist[], int n,int exp)
// {
//     printf("Vertex   Distance from Source\n");
//     for (int i = 0; i < V; i++)
//         printf("%d \t\t %d\n", i+1, dist[i]);
//     printf("Expanding Node %d times\n",exp);
// }
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void astar(int graph[V][V], int src,int dest)
{
    int exp = 0;
    int dist[V]; 
    priority_queue <pii, vector <pii>, greater <pii> > q;
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
 
    q.push({0,src});
    dist[src] = 0;

    while(!q.empty()){
        pii current = q.top();
        q.pop();

        if(current.second == dest) break;

        for(int i=0;i<V;i++){
            if(graph[current.second][i]){
                int g_cost = dist[current.second] + graph[current.second][i];
                if(dist[i] == INT_MAX || g_cost < dist[i]){
                    dist[i] = g_cost;
                    int f_cost = g_cost + 4;
                    q.push({f_cost,i});
                }
            }
        }
    }
    printf("Jarak dari %d ke %d adalah %d\n",src,dest,dist[dest]);
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
    astar(graph, 0, 10);

    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
    
 
    return 0;
}