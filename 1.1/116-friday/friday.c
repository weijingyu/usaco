/*
ID: wadewei1
LANG: C
TASK: friday
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");

	int N, extra;
	int nDays[7] = {0};
	fscanf(fin, "%d", &N);

	int i, j, year, day;
	for(i = 0; i < N; i++) {
		year = 1900 + i;
		for(j = 1; j <= 12; j++) {
			day = (13 + extra) % 7;
			nDays[day]++;

			if(j==4||j==6||j==9||j==11)
				extra = (extra + 2) % 7;
			else
				if(j == 2) {
					if ((year%4==0 && year%100 != 0) || year%400 == 0)
						extra = (extra + 1) % 7;
				}
				else
					extra = (extra + 3) % 7;
		}
	}

	fprintf(fout, "%d", nDays[6]);
	for(i = 0; i < 6; i++)
		fprintf(fout, " %d", nDays[i]);
	fprintf(fout, "\n");

	exit(0);
}
