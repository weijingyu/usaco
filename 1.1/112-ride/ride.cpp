/*
ID: wadewei1
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream fin("ride.in");
	ofstream fout("ride.out");

	int a = 1,  b = 1;
	string comet, group;

	fin >> comet >> group;
	for(int i = 0; i < comet.length(); i++) {
		a *= comet[i] - 'A' + 1;
		fout << comet[i] << endl;
	}
	for(int i = 0; i < group.length(); i++) {
		a *= group[i] - 'A' + 1;
		fout << group[i] << endl;
	}

	fout << ((a % 47 == b % 47) ? "GO" : "STAY") << endl;

	return 0;
}
