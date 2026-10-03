#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
	int u;
	int v;
	int weight;
};
int find(int parent[], int x) {
	if (parent[x] != x)
		parent[x] = find(parent, parent[x]);
	return parent[x];
}
void unionSet(int parent[], int rank[], int x, int y) {
	x = find(parent, x);
	y = find(parent, y);
	if (x == y)
		return;
	if (rank[x] < rank[y]) {
		parent[x] = y;
	} else if (rank[x] > rank[y]) {
		parent[y] = x;
	} else {
	parent[y] = x;
		rank[x]++;
	}
}
void kruskalMST(int **cost, int V) {
	int maxEdges = V * (V - 1) / 2;
	struct Edge *edges =
		(struct Edge *)malloc(maxEdges * sizeof(struct Edge));
	int edgeCount = 0;
	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			if (cost[i][j] != 9999) {
				edges[edgeCount].u = i;
				edges[edgeCount].v = j;
				edges[edgeCount].weight = cost[i][j];
				edgeCount++;
			}
		}
	}
	for (int i = 0; i < edgeCount - 1; i++) {
		for (int j = 0; j < edgeCount - i - 1; j++) {
			if (edges[j].weight > edges[j + 1].weight) {
				struct Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
	int *parent = (int *)malloc(V * sizeof(int));
	int *rank = (int *)malloc(V * sizeof(int));
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	int mstEdges = 0;
	int totalCost = 0;
	for (int i = 0; i < edgeCount && mstEdges < V - 1; i++) {
		int u = edges[i].u;
		int v = edges[i].v;
		int rootU = find(parent, u);
		int rootV = find(parent, v);
		if (rootU != rootV) {
			printf("Edge %d:(%d, %d) cost:%d\n",
					mstEdges,
					u,
					v,
					edges[i].weight);
			totalCost += edges[i].weight;
			mstEdges++;
			unionSet(parent, rank, rootU, rootV);
		}
	}
	printf("Minimum cost= %d\n", totalCost);
	free(edges);
	free(parent);
	free(rank);
}
int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}