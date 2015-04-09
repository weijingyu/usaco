#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXPEOPLE 10
#define NAMELEN 32

typedef struct Person Person;
struct Person {
	char name[NAMELEN];
	int total;
};

Person people[MAXPEOPLE];
int nPeople;

void addPerson(char *name){
	assert(nPeople < MAXPEOPLE);
	strcpy(people[nPeople].name, name);
	nPeople++;
}


Person* lookup(char *name) {
	int i;

	/* look ofr name in people table */
	for(i = 0; i < nPeople; i++)
		if(strcmp(name, people[i].name) == 0)
				return &people[i];

	assert(0);	/* should have found name */
}


int main(void) {
	char name[NAMELEN];
	FILE *fin, *fout;
	int i, j, np, amt,ng;
	Person *giver, *receiver;

	fin = fopen("gift1.in", "r");
	fout = fopen("gift1.out", "w");

	fscanf(fin, "%d", &np);
	assert(np <= MAXPEOPLE);

	for(i = 0; i < np; i++)	{
		fscanf(fin, "%s", name);
		addPerson(name);
	}

	/* process gift lines */
	for (i = 0; i < np; i++) {
		fscanf(fin, "%s %d %d", name, &amt, &ng);
		giver = lookup(name);

		for(j = 0; j < ng; j++) {
			fscanf(fin, "%s", name);
			receiver = lookup(name);
			giver->total -= amt/ng;
			receiver->total += amt/ng;
		}
	}

	/* print gift totals */
	for(i = 0; i < np; i++)
		fprintf(fout, "%s %d\n", people[i].name, people[i].total);

	exit(0);
}
