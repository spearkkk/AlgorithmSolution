/**
* @file		coin1.cpp
* @date		2016.11.15.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/2293
*/
#include <iostream>
using namespace std;

int main() {
	int n, money, coin[101];
	int d[10001];

	for (int i = 0; i < 10001; ++i) {
		d[i] = 0;
	}

	cin >> n; cin >> money;
	for (int i = 0; i<n; i++)
		cin >> coin[i];

	d[0] = 1;

	for (int i = 0; i<n; i++) {
		for (int j = coin[i]; j <= money; j++)
			d[j] += d[j - coin[i]];
	}
	cout << d[money] << endl;
	return 0;
}