
#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
using namespace std;
#define V 6

bool Breadthfs
(int m[V][V], int s, int t, int parent[])
{

	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (visited[v] == false && m[u][v] > 0) {
				if (v == t) {
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return false;
}
int Fordf(int graph[V][V], int s, int t)
{
	int u, v;
	int m[V][V];
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			m[u][v] = graph[u][v];

	int parent[V];
	int mflow = 0;
	while (Breadthfs(m, s, t, parent)) {
		int pflow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			pflow = min(pflow, m[u][v]);
		}
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			m[u][v] -= pflow;
			m[v][u] += pflow;
		}
		mflow += pflow;
	}
	return mflow;
}
int main()
{
	// int graph[V][V]
	// 	= { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
	// 		{ 0, 4, 0, 0, 14, 0 }, { 0, 0, 9, 0, 0, 20 },
	// 		{ 0, 0, 0, 7, 0, 4 }, { 0, 0, 0, 0, 0, 0 } };

    int graph[V][V] = {
    {0, 10, 8, 0, 0, 0},{0, 0, 6, 7, 0, 0},{0, 3, 0, 0, 9, 0},
    {0, 0, 5, 0, 0, 15},{0, 0, 0, 4, 0, 2},{0, 0, 0, 0, 0, 0}
    };
    
	cout << "The maximum possible flow is "
		<< Fordf
    (graph, 0, 5);

	return 0;
}
