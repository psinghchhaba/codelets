#include <stdio.h>
#include <limits.h>

#define N 10

int R[128][128] = {{0}};
static int counter;
static int count;
int min_mat_chain_order_rec(int *mat, int i, int j) {
	int k, min=INT_MAX, c;
	if (i == j)
		return 0;
    count++;    
	//printf ("function called %d times\n", count);

	for (k=i; k<j; k++) {
		c = min_mat_chain_order_rec(mat, i, k) +
			min_mat_chain_order_rec(mat, k+1, j) +
			mat[i-1] * mat[k] * mat[j];

		if (c < min)
			min = c;
	}
	return min;
}

int min_mat_chain_order_rec_with_memo(int *mat, int i, int j) {
	int k, min=INT_MAX, c;


	if (i == j)
		return 0;

	if (R[i][j] != 0)
		return R[i][j];
    counter++;
	//printf ("function called %d times\n", ++counter);

	for (k=i; k<j; k++) {
		c = min_mat_chain_order_rec_with_memo(mat, i, k) +
			min_mat_chain_order_rec_with_memo(mat, k+1, j) +
			mat[i-1] * mat[k] * mat[j];

		if (c < min)
			min = c;
	}
	R[i][j] = min;
	return min;
}

int main () {
	int mats[N] = {20, 10, 30, 40, 30, 15, 20, 10, 50, 60};
	printf ("Minimum number of multiplication required are %d\n", 
						min_mat_chain_order_rec(mats, 1, N-1));
	printf ("function called %d times\n", count);
	printf ("Minimum number of multiplication required are %d\n", 
						min_mat_chain_order_rec_with_memo(mats, 1, N-1));
	printf ("function called %d times\n", ++counter);
}

