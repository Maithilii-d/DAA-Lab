#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LENGTH 100

int max(int a, int b){if(a>b){return a;}else{return b;}}

int lcsOf3(char X[], char Y[], char Z[], int m, int n, int o){
	while (m > 0 && (X[m - 1] == '\n' || X[m - 1] == '\r')) m--;
	while (n > 0 && (Y[n - 1] == '\n' || Y[n - 1] == '\r')) n--;
	while (o > 0 && (Z[o - 1] == '\n' || Z[o - 1] == '\r')) o--;

	int L[105][105][105];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= o; k++) {
				if (i == 0 || j == 0 || k == 0) {
					L[i][j][k] = 0;
				} 
				else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1]) {
					L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
				} 
				else {
					L[i][j][k] = max(max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
				}
			}
		}
	}
	return L[m][n][o];
}

int main()
{	char x[MAX_LENGTH], y[MAX_LENGTH],z[MAX_LENGTH];
    fgets(x, MAX_LENGTH, stdin);
    fgets(y, MAX_LENGTH, stdin);
    fgets(z, MAX_LENGTH, stdin);
	printf("%d", lcsOf3(x, y, z, strlen(x), strlen(y), strlen(z)));
	
	return 0;
}