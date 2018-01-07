#include <stdio.h>
#include <limits.h>

#define N 5

int min_mat_chain_order_rec(int *mat, int i, int j) {
	int k, min=INT_MAX, c;
	if (i == j)
		return 0;

	for (k=i; k<j; k++) {
		c = min_mat_chain_order_rec(mat, i, k) +
			min_mat_chain_order_rec(mat, k+1, j) +
			mat[i-1] * mat[k] * mat[j];

		if (c < min)
			min = c;
	}

	return min;
}

int main () {
	int mats[N] = {20, 10, 30, 40, 30};
	printf ("Minimum number of multiplication required are %d\n", 
						min_mat_chain_order_rec(mats, 1, N-1));
}

