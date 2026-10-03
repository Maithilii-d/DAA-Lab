#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	int distance[MAX], pred[MAX], visited[MAX];
	int i, j, count, min_distance, nextnode;
	for (i = 1; i <= n; i++) {
		visited[i] = 0;
		pred[i] = startnode;
		if (i == startnode) {
			distance[i] = 0;
		} else if (G[startnode][i] == 0) {
			distance[i] = INFINITY;
		} else {
			distance[i] = G[startnode][i];
		}
	}
	visited[startnode] = 1;
	count = 1;
	while (count < n) {
		min_distance = INFINITY;
		nextnode = -1;
		for (i = 1; i <= n; i++) {
			if (distance[i] < min_distance && !visited[i]) {
				min_distance = distance[i];
				nextnode = i;
			}
		}
		if (nextnode == -1 || min_distance == INFINITY) {
			break;
		}
		visited[nextnode] = 1;
		for (i = 1; i <= n; i++) {
			if (!visited[i] && G[nextnode][i] > 0) {
				if (min_distance + G[nextnode][i] < distance[i]) {
					distance[i] = min_distance + G[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}
		count++;
	}
	printf("Node\tDistance\tPath\n");
	for (i = 1; i <= n; i++) {
		if (i != startnode) {
			if (distance[i] == INFINITY) {
				printf("%4d\t%8s\tNO PATH\n", i, "INF");
			} else {
				printf("%4d\t%8d\t", i, distance[i]);
				j = i;
				printf("%d", j);
				while (j != startnode) {
					j = pred[j];
					printf("<-%d", j);
				}
				printf("\n");
			}
		}
	}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 