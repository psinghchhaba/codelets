#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf jmpbuffer;
static int globalval=1;

void fun2() {
	// Jump back to the jump point which is set in jmpbuffer.
	// Second arg (2) is the value to which setjmp expression will evaluate
	longjmp(jmpbuffer, 2);
}
void fun1(int i, int j, int k, int l) {
	printf ("in fun1\n");
	printf ("globalval %d, autoval %d, regival %d, volaval %d, statval %d\n", globalval, i, j, k, l);
	
	fun2();	
}

int main() {
	int ret;
	int autoval=2;
	register int regival=3;
	volatile int volaval=4;
	static int statval=5;

	// Set the jump point.
	ret = setjmp(jmpbuffer);
	if (ret != 0) {
		// Print the values of various variable of different storage classes after longjmp
		printf ("After longjmp\n");
		printf ("globalval %d, autoval %d, regival %d, volaval %d, statval %d\n", globalval, autoval, regival, volaval, statval);
		exit (0);
	} 

	// Set the values after setjmp
	globalval = 95;
	autoval = 96;
	regival = 97;
	volaval = 98;
	statval=99;
	fun1(autoval, regival, volaval, statval);
	exit(0);
}
