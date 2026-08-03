#include<stdio.h>
int main(){
	int m,n;
	
	if(scanf("%d %d", &m, &n) != 2) return 0;
	
	int A[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &A[i][j]);
		}
	}

	int n_B,p;
	if(scanf("%d %d", &n_B,&p) != 2) return 0;

	if(n != n_B){
		printf("Invalid input\n");
		return 0;
}

	int B[n_B][p];
	for(int i=0;i<n_B;i++){
		for(int j=0;j<p;j++){
			scanf("%d",&B[i][j]);
		}
	}

	int C[m][p];
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			C[i][j] = 0;
			for(int k = 0;k<n;k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			printf("%d",C[i][j]);
			if (j < p-1){
				printf(" ");
			}
		}
	printf(" \n");
	}
return 0;
}