#include <stdio.h>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

struct po {
	int x;
	int y;
}typedef POINT;

struct da {
	int row;
	int cel;
}typedef DATA;

void func();

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {		
		func();
	}
	return 0;
}

void func() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);
	
	vector<DATA> data(cnt);

	for (int i = 0; i < cnt; ++i) {
		POINT p1;
		POINT p2;

		scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
		fgetc(stdin);
	}
}