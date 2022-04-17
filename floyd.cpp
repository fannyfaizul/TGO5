// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 11

/* Define Infinite as a large enough
value.This value will be used for
vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int graph[][V])
{
	/* dist[][] will be the output matrix
	that will finally have the shortest
	distances between every pair of vertices */
	int dist[V][V], i, j, k;

	/* Initialize the solution matrix same
	as input graph matrix. Or we can say
	the initial values of shortest distances
	are based on shortest paths considering
	no intermediate vertex. */
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, ..
	k} */
	for (k = 0; k < V; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}

// Driver code
int main()
{
	int graph[V][V] = { { 0, 2, 8, 1, INF, INF, INF, INF, INF, INF, INF },
                        { 2, 0, 6, INF, 1, INF, INF, INF, INF, INF, INF },
                        { 8, 6, 0, 7, 5, 1, 2, INF, INF, INF, INF },
                        { 1, INF, 7, 0, INF, INF, 9, INF, INF, INF, INF },
                        { INF, 1, 5, INF, 0, 3, INF, 2, 9, INF, INF },
                        { INF, INF, 1, INF, 3, 0, 4, INF, 6, INF, INF },
                        { INF, INF, 2, 9, INF, 4, 0, INF, 3, 1, INF },
                        { INF, INF, INF, INF, 2, INF, INF, 0, 7, INF, 9 },
                        { INF, INF, INF, INF, 9, 6, 3, 7, 0, 1, 2 },
                        { INF, INF, INF, INF, INF, INF, 1, INF, 1, 0, 4 },
                        { INF, INF, INF, INF, INF, INF, INF, 9, 2, 4, 0 } 
                    };

    double time_spent = 0.0;
 
    clock_t begin = clock();
    
    // do some stuff here
	floydWarshall(graph);

    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
	return 0;
}

// This code is contributed by Mythri J L
