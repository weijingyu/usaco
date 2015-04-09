/*
ID: wadewei1
LANG: C++
TASK: transform
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void copy(char **, char **, int);
void rotate(char **, int);
void reflect(char **, int);
bool compare(char **, char **, int);

int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");
    int N, i;
	bool flag = true;
    fin >> N;
	
	char **square, **transform, **reflection;
    
	square = new char*[N];
	transform = new char*[N];
	reflection = new char*[N];
	for(i = 0; i < N; i++) {
		square[i] = new char[N]();
		transform[i] = new char[N]();
		reflection[i] = new char[N]();
	}

	for(i = 0; i < N; i++) {
		fin >> square[i];
	}

	for(i = 0; i < N; i++) {
		fin >> transform[i];
	}
	copy(square, reflection, N);

	if (flag)
		rotate(square, N);
	for(i = 1; flag && i <= 3; i++) {
		if(compare(square,transform, N)) {
			fout << i << endl;
			flag = false;
			break;
		}
		rotate(square, N);
	}

	if(flag) {
		reflect(reflection, N);

		if(compare(reflection, transform, N)) {
			fout << 4 << endl;
			flag = false;
		}
		else {
			for(i = 0; flag && i < 3; i++) {
				rotate(reflection, N);
				if(compare(reflection, transform, N)) {
					fout << 5 << endl;
					flag = false;
					break;
				}
			}
		}
	}

	rotate(square, N);
	if(compare(square, transform, N)) {
		fout << 6 << endl;
		flag = false;
	}

	if (flag)
		fout << 7 << endl;

	delete [] square;
	delete [] transform;
	delete [] reflection;
	
	return 0;
}

void copy(char **s, char **t, int n) {
	int i;
	for(i = 0; i < n; i++) {
		strcpy(t[i], s[i]);
	}
}

void rotate(char **s, int n) {
	char ** tmp;
	int i, j;
	tmp = new char*[n];
	for(i = 0; i < n; i++) {
		tmp[i] = new char[n];
	}
	copy(s, tmp, n);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			s[i][j] = tmp[n-j-1][i];
		}
	}
	
	delete [] tmp;
}

void reflect(char **s, int n) {
	int i, j;
	char tmp;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n/2; j++) {
			tmp = s[i][j];
			s[i][j] = s[i][n-1-j];
			s[i][n-1-j] = tmp;
		}
	}
}

bool compare(char **s, char **t, int n) {
	int i;
	for(i = 0; i < n; i++) {
		if(strcmp(s[i], t[i]) != 0) {
			return false;
		}
	}
		return true;
}
