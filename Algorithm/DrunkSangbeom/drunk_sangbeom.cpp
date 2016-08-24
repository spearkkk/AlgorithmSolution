/**
* @file		drunk_sangbeom.cpp
* @date		2016.08.24.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/6359
*/

#include <iostream>

using namespace std;

int main() {
	int case_cnt;
	int* case_data;
	int* room;

	cin >> case_cnt;

	case_data = new int[case_cnt];

	for (int i = 0; i < case_cnt; ++i) {
		cin >> case_data[i];
	}


	for (int i = 0; i < case_cnt; ++i) {
		room = new int[case_data[i] + 1];
		for (int k = 1; k < case_data[i] + 1; ++k) {
			room[k] = 0;
		}

		for (int k = 1; k <= case_data[i]; ++k) {
			for (int j = 1; j <= case_data[i]; ++j) {
				if (j % k == 0) {
					room[j] = (++room[j]) % 2;
				}
			}
		}
		int cnt = 0;
		for (int k = 1; k < case_data[i] + 1; ++k) {
			if (room[k] == 1) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}