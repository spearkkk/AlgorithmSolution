#include <stdio.h>

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);
	int rslt = 0;
	for (int i = 0; i < cnt; ++i) {
		int number;
		scanf("%d", &number);
		fgetc(stdin);
		++rslt;
		if (number == 1) {
			--rslt;
			continue;
		}
		for (int j = 2; j < number; ++j) {
			if (number % j == 0) {
				--rslt;
				break;
			}
		}
	}
	printf("%d\n", rslt);
}