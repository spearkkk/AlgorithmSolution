#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int cnt;
	vector<int> wines;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		int tmp;
		scanf("%d", &tmp);
		fgetc(stdin);
		wines.push_back(tmp);
	}

	return 0;
}