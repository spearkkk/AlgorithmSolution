/**
* @file		pinary_numver.cpp
* @date		2016.08.29.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/2193 #dynamic programming, #fibonacci
*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string sum(string left, string right);

int main() {
	int n;
	string *arr;

	scanf("%d", &n);
	fgetc(stdin);
	arr = new string[n];

	if (n == 1 || n == 2) {
		printf("%d\n", 1);
	}
	else {
		arr[0] = "1";
		arr[1] = "1";

		for (int i = 2; i < n; ++i) {
			arr[i] = sum(arr[i - 1], arr[i - 2]);
		}
		reverse(arr[n - 1].begin(), arr[n - 1].end());
		cout << arr[n - 1] << endl;
	}

	return 0;
}

string sum(string left, string right) {
	int idx;
	string rslt = left;

	for (idx = 0; idx < right.length(); ++idx) {
		int tmp = (int)(rslt[idx] - 48) + (int)(right[idx] - 48);
		int val = tmp % 10;
		int over = tmp / 10;

		rslt[idx] = (char)(val + 48);

		if (over > 0) {
			if (idx < right.length() - 1 || rslt.length() > right.length()) {
				over = (int)(rslt[idx + 1] - 48) + over;
			}
			else {
				rslt.resize(rslt.length() + 1);
			}
			rslt[idx + 1] = (char)(over + 48);
		}
	}

	return rslt;
}