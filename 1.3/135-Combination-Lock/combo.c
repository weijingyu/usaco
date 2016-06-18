/*
ID: wadewei1
LANG: C
TASK: combo
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int openLock(int [], int []); 
int withinTwo(int, int);
int n=0;

int main() {

	FILE *fin = fopen("combo.in", "r");
	FILE *fout = fopen("combo.out", "w");

	int keys = 0;
	int john[3], master[3];

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d %d %d", &john[0], &john[1], &john[2]);
	fscanf(fin, "%d %d %d", &master[0], &master[1], &master[2]);
	
	int i[3];
	for(i[0] = 1; i[0] <= n; i[0]++) {
		for(i[1] = 1; i[1] <= n; i[1]++) {
			for(i[2] = 1; i[2] <= n; i[2]++) {
				if(openLock(i, john) || openLock(i, master)) {
					keys += 1;
					//fprintf(fout, "%d %d %d\n", i[0], i[1], i[2]);
				}
			}
		}
	}

	fprintf(fout, "%d\n", keys);

	exit(0);
}


int openLock(int i[], int lock[]) {
	if(withinTwo(i[0], lock[0]) &&
	   withinTwo(i[1], lock[1]) &&
	   withinTwo(i[2], lock[2]) )
		//printf("%s %d %d %d\n", "True", i[0], i[1], i[2]);
		return 1;
	else
		return 0;
}

int withinTwo(int i, int j) {
	if(abs(i-j) < 3 || n - abs(i-j) < 3)
		return 1;
	else 
		return 0;
}
