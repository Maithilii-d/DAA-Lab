#include <stdio.h>
#include <limits.h>

#define INF (INT_MAX / 2)

int main() {
	int n;
	scanf("%d", &n);

	int cost[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == -1)
				cost[i][j] = INF;
		}
	}

	int states = 1 << n;
	int dp[states][n];

	for (int mask = 0; mask < states; mask++) {
		for (int i = 0; i < n; i++) {
			dp[mask][i] = INF;
		}
	}

	dp[1][0] = 0;

	for (int mask = 1; mask < states; mask++) {
		for (int u = 0; u < n; u++) {
			if (dp[mask][u] == INF)
				continue;

			for (int v = 0; v < n; v++) {
				if (!(mask & (1 << v)) && cost[u][v] != INF) {
					int newMask = mask | (1 << v);
					int newCost = dp[mask][u] + cost[u][v];

					if (newCost < dp[newMask][v]) {
						dp[newMask][v] = newCost;
					}
				}
			}
		}
	}

	int ans = INF;
	int fullMask = states - 1;

	for (int i = 1; i < n; i++) {
		if (dp[fullMask][i] != INF && cost[i][0] != INF) {
			int total = dp[fullMask][i] + cost[i][0];

			if (total < ans)
				ans = total;
		}
	}

	if (n == 1) {
		printf("0\n");
	} else if (ans == INF) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}