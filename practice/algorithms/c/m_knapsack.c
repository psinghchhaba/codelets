#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a > b) ? a : b)

int T[10][10];
int knapsack(int wt[], int val[], int W, int n) {
	if (n == 0 || W == 0)
		return 0;
	if (T[W][n] != -1)
		return T[W][n];

	//printf ("%d%d\n", W, n);
	if (wt[n-1] <= W)
		return T[W][n] = MAX(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1),
			   knapsack(wt, val, W, n-1));
	else
		return knapsack(wt, val, W, n-1);		
}

int main() 
{
	int wt[] = { 1, 3, 4, 5, 6};
	int val[] = {1, 4, 5, 7, 8};
	int W = 9;
	int n = 5;
	memset(T, -1, sizeof(T));
	printf ("profit %d\n", knapsack(wt, val, W, n));
}
