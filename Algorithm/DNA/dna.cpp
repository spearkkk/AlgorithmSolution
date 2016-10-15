#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int m;
string dna[1000];

int main() {
	scanf("%d %d", &n, &m);
	fgetc(stdin);

	for (int i = 0; i < n; ++i) {
		cin >> dna[i];
	}

	//for (int i = 0; i < n; ++i) {
	//	cout<<dna[i]<<endl;
	//}

	int ATGC[4];
	string str = "";
	int sum = 0;
	for (int i = 0; i < m; ++i) {
		memset(ATGC, 0, sizeof(ATGC));

		for (int j = 0; j < n; ++j) {
			switch(dna[j].at(i)) {
			case 'A':
				++ATGC[0];
				break;
			case 'C':
				++ATGC[1];
				break;
			case 'G':
				++ATGC[2];
				break;
			case 'T':
				++ATGC[3];
				break;
			}
		}

		int pos = max_element(ATGC, ATGC + 4) - ATGC;
		for (int j = 0; j < 4; ++j) {
			if (pos != j) {
				sum += ATGC[j];
			}
		}
		switch (pos) {
		case 0:
			str += "A";
			break;
		case 1:
			str += "C";
			break;
		case 2:
			str += "G";
			break;
		case 3:
			str += "T";
			break;
		}
	}
	cout << str << endl<<sum<<endl;
	return 0;
}