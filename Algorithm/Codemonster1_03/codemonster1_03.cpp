#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int func();

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		printf("%d\n", func());
	}

	return 0;
}

int func() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	string origin;
	string trans;

	getline(cin, origin);
	getline(cin, trans);
	
	//printf("%s %s\n", origin.c_str(), trans.c_str());

	for (int i = 0; i < cnt - 1; ++i) {
		vector<int> idx;

		int tmp = 0;

		do {
			tmp = trans.find(origin);
			idx.push_back(tmp);
		} while (tmp != -1);

		for (int i = 0; i < idx.size(); ++i) {
			printf("%d ", idx[i]);
		}
	}


	return -1;
}