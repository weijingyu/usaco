/*
ID: wadewei1
LANG: C
TASK: gift1
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {

	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");

	int total = 0;
	char person[10][14];
	int money[10] = {0};

	int i = 0;
	fscanf(fin, "%d", &total);
	for (i = 0; i < total; i++) {
		fscanf(fin, "%s", person[i]); 
	}

	for(i = 0; i < total; i++) {

		char Giver[14];
		int Gift, NumOfReceiver;
		fscanf(fin, "%s", Giver);
		fscanf(fin, "%d %d", &Gift, &NumOfReceiver);

		if (NumOfReceiver) {
			int MoneyReceived = Gift / NumOfReceiver;
			int MoneyKept = Gift % NumOfReceiver;
			
			char Receiver[14];
	
			int j, k;
			for(j = 0; j < NumOfReceiver; j++) {
				fscanf(fin, "%s", Receiver);
				for(k = 0; k < total; k++) {
					if(strcmp(Receiver, person[k]) == 0)
						money[k] += MoneyReceived;
				}
			}

			if (Gift) {
				for(k = 0; k < total; k++) {
					if(strcmp(Giver, person[k]) == 0)
						money[k] = money[k] - Gift + MoneyKept;
				}

			}
		}
	}

	for(i = 0; i < total; i++) {
		fprintf(fout, "%s %d\n", person[i], money[i]);
	}

	exit(0);
}
