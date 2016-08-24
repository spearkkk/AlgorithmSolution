/**
* @file		fibonacci.cpp
* @date		2016.08.24.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1003
*/
#include <iostream>

using namespace std;

void find(int n, int* arr);

int main() {
	int case_cnt;
	int* case_data;
	int arr[2];

	cin >> case_cnt;
	case_data = new int[case_cnt];
	for (int i = 0; i < case_cnt; ++i) {
		cin >> case_data[i];
	}
	for (int i = 0; i < case_cnt; ++i) {
		arr[0] = 0;
		arr[1] = 0;
		find(case_data[i], arr);
		cout << arr[0] << " " << arr[1] << endl;
	}
}

void find(int n, int* arr) {
	if (n == 0) {
		++arr[0];
		return;
	}
	else if (n == 1) {
		++arr[1];
		return;
	}
	else {
		find(n - 1, arr);
		find(n - 2, arr);
	}
}