/*
ID: wadewei1
LANG: C
TASK: ride
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

	FILE *names = fopen("ride.in", "r");
	FILE *result = fopen("ride.out", "w");

	char comet[7], group[7];
	fscanf(names, "%s", comet);
	fscanf(names, "%s", group);

	int product_1 = 1;
	int product_2 = 1;
	int i = 0;
	for(i = 0; i < 6 && comet[i] != '\0'; i++) {
		product_1 *= comet[i] -'A' +1;	
	}
	for(i = 0; i < 6 && group[i] != '\0'; i++) {
		product_2 *= group[i] -'A' +1;	
	}
	
	if( product_1 % 47 == product_2 % 47)
		fprintf(result, "%s\n", "GO");
	else fprintf(result, "%s\n", "STAY");

	exit(0);
}
