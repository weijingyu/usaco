/*
ID: wadewei1
LANG: C
TASK: xxxx
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

	FILE *fin = fopen("test.in", "r");
	FILE *fout = fopen("test.out", "w");

	int a, b;

	fscanf(fin, "%d %d", &a, &b);
	fprintf(fout, "%d\n", a + b);

	exit(0);
}
