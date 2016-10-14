#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int box[1001];
int num[1001];

int main() {
	scanf("%d", &n);
	fgetc(stdin);

	memset(box, 0, sizeof(box));
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &box[i]);
		fgetc(stdin);

		int max_num = 0;

		for (int j = i - 1; j > 0; --j) {
			if (box[i] > box[j]) {
				max_num = max(max_num, num[j]);
				num[i] = max_num + 1;
			}
		}
	}

	int *rslt = max_element(&num[1], &num[n + 1]);
	printf("%d\n", *rslt + 1);
	return 0;
}