/*
ID: wadewei1
LANG: C
TASK: palsquare
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXNUM 300
#define MAXCOUNT 20

void baseConvert(int foo, int* bar, const int b) {
	int i, count = 1;
	while(foo >= b) {
		bar[count] = foo % b;
		foo /= b;
		count++;
	}
	bar[count] = foo;
	bar[0] = count;
}

int isPal(const int* num) {
	int size = num[0];
	int i;
	for(i = 1; i < size + 1 - i; i++) {
		if(num[i] != num[size + 1 -i])
			return 0;
	}
	return 1;
}

char* display(int* num) {
	int i;
	char numstr[MAXCOUNT], str[2];
	for(i = num[0]; i > 0; i++) {
		sprintf(str, "%d", num[i]);
		strcat(numstr, str);
	}

	return numstr;
}

int main() {

	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");

	int base, i;
	fscanf(fin, "%d", &base);

	for(i = 1; i <= MAXNUM; i++) {
		int number[MAXCOUNT], square[MAXCOUNT];
		baseConvert(i, number, base);	
		baseConvert(i * i, square, base);

		if(isPal(square))
			fprintf(fout, "%s %s\n", display(number), display(square));
	}
}
