#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool pickup(vector<int> &data, int idx);

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);
	
	for (int i = 0; i < cnt; ++i) {
		char buf[26];
		vector<int> data;

		fgets(buf, 25, stdin);

		data.push_back(-1);
		int flg = 1;
		for (int j = 1; j < strlen(buf) - 1; ++j) {
			if (buf[j - 1] != buf[j]) {
				if (flg == 1 && data.size() > 1) {
					int cnt_data = data.size();

					if (data[cnt_data - 2] == 1 && data[cnt_data - 1] == 0) {
						data.pop_back();
						data.pop_back();
						flg = 0;
					}
				}
				data.push_back(flg);
				flg = 1;
			}
			else {
				flg = 0;
			}
		}
		data.push_back(flg);
		data.push_back(-1);

		for (int j = 0; j < data.size(); ++j) {
			printf("%d ", data[j]);
		}
		printf("\n");

		//printf("%s %d\n", buf, strlen(buf));
		//bool flg = false;
		//for (int i = 0; i < cnt; ++i) {
		//	if (flg = pickup(data, i)) {
		//		break;
		//	}
		//}
		//if (flg) {
		//	printf("%d\n", 1);
		//}
		//else {
		//	printf("%d\n", 1);
		//}
	}
	return 0;
}

bool pickup(vector<int> &data, int idx) {	
	vector<int> flg;

	for (int i = 1; i < data.size() - 1; ++i) {
		if (data[i] == 0) {
			flg.push_back(i);
		}
	}
	if (flg.empty()) {
		data.pop_back();
		data.pop_back();
		if (data.empty) {
			return true;
		}
		else return false;
	}

	while (!flg.empty()) {
		vector<int> data_cp(data);
		if (pickup(data_cp, flg.back())) {
			return true;
		}
		flg.pop_back();
	}
	return false;
}