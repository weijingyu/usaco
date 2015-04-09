/*
ID: wadewei1
LANG: C
TASK: milk2
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXN 10000

int main() {

	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	int timeline[MAXN] = { 0 };
	int i = 0, j, start = 0, end = 0;
	int START = MAXN, END = 0;
	
	while(i < n) {
		fscanf(fin, "%d %d", &start, &end);
		start /= 100;
		end /= 100;
		for(j = start; j < end; j++) {
			timeline[j] = 1;			
		}
		if(start < START) START = start;
		if(end > END) END = end;
		i++;
	}
	
	i = START;

	int type, count;
	int continuous = 0, idle = 0;
	while(i < END) {
		type = timeline[i];
		count = 0;
		while(timeline[i] == type) {
			count++;
			i++;
		}
		if(type == 1)
			continuous = (count > continuous) ? count : continuous;
		else
			idle = (count > idle) ? count : idle;
	}
	
	fprintf(fout, "%d %d\n", continuous*100, idle*100);

	exit(0);
}
