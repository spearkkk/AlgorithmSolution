#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int cnt_pass;
	int cnt_alph;
	vector<char> alph;

	scanf("%d %d\n", &cnt_pass, &cnt_alph);

	for (int i = 0; i < cnt_alph; ++i) {
		char tmp;
		scanf("%c", &tmp);
		fgetc(stdin);
		alph.push_back(tmp);
	}

	sort(alph.begin(), alph.end(), less<char>());

	for (int i = 0; i < cnt_alph; ++i) {
		printf("%c ", alph.at(i));
	}


	return 0;
}