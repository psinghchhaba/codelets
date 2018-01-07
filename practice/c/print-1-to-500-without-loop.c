#include <stdio.h>

void print_rec(int n) {
	if (n > 1)
		print_rec(n-1);
	printf("%d  ", n);	
}

void print_goto(int n) {
	int i=1;
	go:
		if (i <=n) {
			printf("%d  ", i);
			i++;
			goto go;
		}
}

int main() {
	print_rec(500);
	print_goto(500);
}
