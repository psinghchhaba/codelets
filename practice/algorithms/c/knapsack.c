#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)

int knapsack(int wt[], int val[], int W, int n) {
	if (n == 0 || W == 0)
		return 0;
	//printf ("%d%d\n", W, n);
	if (wt[n-1] <= W)
		return MAX(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1),
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
	printf ("profit %d\n", knapsack(wt, val, W, n));
}
