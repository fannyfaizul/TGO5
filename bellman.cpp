// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;

// The main function that finds shortest
// distances from src to all other vertices
// using Bellman-Ford algorithm. The function
// also detects negative weight cycle
// The row graph[i] represents i-th edge with
// three values u, v and w.
void BellmanFord(int graph[][3], int V, int E,
				int src)
{
	// Initialize distance of all vertices as infinite.
	int dis[V];
	for (int i = 0; i < V; i++)
		dis[i] = INT_MAX;

	// initialize distance of source as 0
	dis[src] = 0;
    int exp = 0;

	// Relax all edges |V| - 1 times. A simple
	// shortest path from src to any other
	// vertex can have at-most |V| - 1 edges
	for (int i = 0; i < V - 1; i++) {

		for (int j = 0; j < E; j++) {
            exp++;
			if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] <
							dis[graph[j][1]])
				dis[graph[j][1]] =
				dis[graph[j][0]] + graph[j][2];
		}
	}

	// check for negative-weight cycles.
	// The above step guarantees shortest
	// distances if graph doesn't contain
	// negative weight cycle. If we get a
	// shorter path, then there is a cycle.
	for (int i = 0; i < E; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dis[x] != INT_MAX &&
				dis[x] + weight < dis[y])
			cout << "Graph contains negative"
					" weight cycle"
				<< endl;
	}

	cout << "Vertex Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i+1 << "\t\t" << dis[i] << endl;
    printf("Expanding Node %d times\n",exp);
}

// Driver program to test above functions
int main()
{
	int V = 11; // Number of vertices in graph
	int E = 44; // Number of edges in graph

	// Every edge has three values (u, v, w) where
	// the edge is from vertex u to v. And weight
	// of the edge is w.
	int graph[][3] = { { 0, 1, 2 }, { 1, 0 , 2 },
					{ 0, 2, 8 }, { 2, 0 , 8 },
					{ 0, 3, 1 }, { 3, 0 , 1 },
					{ 1, 4, 1 }, { 4, 1 , 1 },
					{ 1, 2, 6 }, { 2, 1 , 6 },
					{ 2, 3, 7 }, { 3, 2 , 7 },
					{ 2, 4, 5 }, { 4, 2 , 5 },
					{ 2, 5, 1 }, { 5, 2 , 1 },
					{ 2, 6, 2 }, { 6, 2 , 2 },
					{ 3, 6, 9 }, { 6, 3 , 9 },
					{ 4, 5, 3 }, { 5, 4 , 3 },
					{ 4, 7, 2 }, { 7, 4 , 2 },
					{ 4, 8, 9 }, { 8, 4 , 9 },
					{ 5, 6, 4 }, { 6, 5 , 4 },
					{ 5, 8, 6 }, { 8, 5 , 6 },
					{ 6, 8, 3 }, { 8, 6 , 3 },
					{ 6, 9, 1 }, { 9, 6 , 1 },
					{ 7, 10, 9 }, { 10, 7 , 9 },
					{ 7, 8, 7 }, { 8, 7 , 7 },
					{ 8, 9, 1 }, { 9, 8 , 1 },
					{ 8, 10, 2 }, { 10, 8 , 2 },
					{ 9, 10, 4 }, { 10, 9 , 4 }
					 };
    double time_spent = 0.0;
 
    clock_t begin = clock();
    
    // do some stuff here
	BellmanFord(graph, V, E, 0);

    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
	return 0;
}
