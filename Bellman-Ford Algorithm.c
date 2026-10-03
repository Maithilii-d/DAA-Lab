#include <stdio.h>
#include <limits.h>

#define INF 1000000000

typedef struct {
	int u, v, w;
} Edge;

int parent[1005];

void printPath(int v, int src) {
	if (v == src) {
		printf("%d", src);
		return;
	}
	printPath(parent[v], src);
	printf("->%d", v);
}

int main() {
	int V, E;
	scanf("%d", &V);
	scanf("%d", &E);

	Edge edges[10005];

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	}

	int src;
	scanf("%d", &src);

	int dist[1005];

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
		parent[i] = -1;
	}

	dist[src] = 0;


	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = edges[j].u;
			int v = edges[j].v;
			int w = edges[j].w;

			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				parent[v] = u;
			}
		}
	}


	for (int j = 0; j < E; j++) {
		int u = edges[j].u;
		int v = edges[j].v;
		int w = edges[j].w;

		if (dist[u] != INF && dist[u] + w < dist[v]) {
			printf("Negative cycle detected");
			return 0;
		}
	}


	for (int i = 1; i <= V; i++) {
		if (i == src)
			continue;

		if (dist[i] == INF) {
			printf("%d INF None\n", i);
		} else {
			printf("%d %d ", i, dist[i]);
			printPath(i, src);
			printf("\n");
		}
	}

	return 0;
}