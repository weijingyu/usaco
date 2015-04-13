/*
ID: wadewei1
LANG: C
PROG: namenum
*/

/*
 * This is what copied from Internet because I didn't com
 * up with a good solution.
 * Hope I won't do this again.
 */

#include <stdio.h>
#include <string.h>

#define MAX_NUM 5010
#define NAME_LEN 16

char map[30] = {"2223334445556667777888999"};
char srcname[MAX_NUM][NAME_LEN];
char dstname[MAX_NUM][NAME_LEN];
int dstlen;

void init()
{
	FILE *fdict = fopen("dict.txt", "r");
	int i = 0, len, j;
	while(EOF != fscanf(fdict, "%s", srcname[i]))
	{
		len = strlen(srcname[i]);
		for(j = 0; j < len; ++j)
		{
			if(srcname[i][j] == 'Z' || srcname[i][j] == 'Q')
			{
				dstname[i][j] = 'X';
				continue;
			}
			dstname[i][j] = map[srcname[i][j] - 'A'];
		}
		dstname[i][j] = '\0';
		++i;
	}
	dstlen = i;
	fclose(fdict);
}

void work()
{
	FILE *fin = fopen("namenum.in", "r");
	FILE *fout = fopen("namenum.out", "w");
	
	char name[NAME_LEN];
	int i, len, flag;
	fscanf(fin, "%s", name);
	flag = 0;
	for(i = 0; i < dstlen; ++i)
	{
		if(!strcmp(name, dstname[i]))
		{
			fprintf(fout, "%s\n", srcname[i]);
			flag = 1;
		}
	}
	if(!flag) fprintf(fout, "NONE\n");
	fclose(fin);
	fclose(fout);
}

int main(int argc, char **argv)
{
	init();
	work();
	
	return 0;
}
