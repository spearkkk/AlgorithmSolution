/**
* @file		q-index.cpp
* @date		2016.10.01.
* @author	spearkkk
* @brief	2016 ACM ICPC Regional DAEJOEN Problem I
*/
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	vector<int> val(cnt + 1, 0);

	for (int i = 0; i < cnt; ++i) {
		int tmp;

		scanf("%d", &tmp);
		fgetc(stdin);

		if (cnt < tmp) {
			for (int j = 0; j < cnt + 1; ++j) {
				++val[j];
			}
		}
		else {
			for (int j = 0; j <= tmp; ++j) {
				++val[j];
			}
		}
	}

	for (int i = cnt; i >= 0; --i) {
		if (val[i] >= i) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}