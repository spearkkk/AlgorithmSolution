/**
* @file		endians.cpp
* @date		2016.08.23.
* @author	spearkkk
* @brief	https://algospot.com/judge/problem/read/ENDIANS
*/
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int cnt;

	cin >> cnt;

	for (int i = 0; i < cnt; ++i) {
		unsigned int tmp;
		short bytes[32] = { 0, };

		cin >> tmp;
		for (int j = 31; j >= 0; --j) {
			if (tmp / (unsigned)pow(2, j) != 0) {
				bytes[j] = 1;
				tmp -= pow(2, j);
			}
		}

		unsigned int rslt = 0;

		for (int j = 0; j < 32; ++j) {
			rslt += bytes[32 + (j % 8) - (8 * (j / 8 + 1))] * (unsigned)pow(2, j);
		}

		cout << rslt << endl;
	}
}