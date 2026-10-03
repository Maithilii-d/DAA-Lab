#include <stdio.h>
int n;
int elements[100];
int target_sum;
int discovered_subsets[2000][100];
int subset_sizes[2000];
int subset_count = 0;
int current_subset[100];

void backtrack(int index, int current_sum, int current_size) {
	if (index == n) {
		if (current_sum == target_sum) {
			subset_sizes[subset_count] = current_size;
			for (int i = 0; i < current_size; i++) {
				discovered_subsets[subset_count][i] = current_subset[i];
			}
			subset_count++;
		}
		return;
	}
	current_subset[current_size] = elements[index];
	backtrack(index + 1, current_sum + elements[index], current_size + 1);
	backtrack(index + 1, current_sum, current_size);
}

int main() {
	if (scanf("%d", &n) != 1) return 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &elements[i]);
	}
	scanf("%d", &target_sum);
	backtrack(0, 0, 0);
	if (subset_count == 0) {
		printf("-1\n");
	} else {
		for (int i = subset_count - 1; i >= 0; i--) {
			for (int j = 0; j < subset_sizes[i]; j++) {
				printf("%d ", discovered_subsets[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}