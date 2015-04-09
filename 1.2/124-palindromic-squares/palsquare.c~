/*
ID: wadewei1
LANG: C
TASK: palsquare
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXNUM 300
int isPal(int num, int b) {
	int i, count = 0;
	int result[5];
	while(num >= b) {
		result[count] = num % b;
		num /= b;
		count++;
	}
	result[count] = num;

	for(i = 0; i < count - i; i++) {
		if(result[i] != result[count -i])
			return 0;
	}
	return 1;
}

int main() {

	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");

	int base, i, square;
	fscanf(fin, "%d", &base);

	for(i = 1; i <= MAXNUM; i++) {
		square = i * i;

		if(isPal(square, base))
			fprintf(fout, "%d %d\n", i, square);
	}
}
