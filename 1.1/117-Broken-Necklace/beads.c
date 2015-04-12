/*
ID: wadewei1
LANG: C
TASK: beads
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXOFBEADS 350

int main() {

	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");

	int n;
	fscanf(fin, "%d", &n);
	char necklace[MAXOFBEADS];
	fscanf(fin, "%s", necklace);

	int max = 0;
	char beads[2*MAXOFBEADS];
	strcpy(beads, necklace);
	strcat(beads, necklace);

	int BeginPos = 0;
	char CurCorlor, PreCorlor;
	int nCur = 0, nPre = 0, nW = 0, i = 0, num = 0;

	while(BeginPos < n) {
		if(beads[i] == CurCorlor) {
			nCur = nCur + nW + 1;
			nW = 0;
		}
		else
		{
			if(beads[i] == PreCorlor) {
				num = nPre + nCur + nW;
				max = (num > max) ? num : max;
				PreCorlor = CurCorlor;
				CurCorlor = beads[i];
				BeginPos += nPre;
				nPre = nCur;
				nCur = nW + 1;
				nW = 0;
			}
			else
			{
				if(beads[i] == 'w') {
					nW++;
				}
				else {
					if(!CurCorlor) {
						CurCorlor = beads[i];
						nCur = nW + 1;
						nW = 0;
					}
					else {
						PreCorlor = CurCorlor;
						CurCorlor = beads[i];
						nPre = nCur;
						nCur = 1;
					}			
				}
			}		
		}

		i++;
	}

	fprintf(fout, "%d\n", max);

	exit(0);
}
