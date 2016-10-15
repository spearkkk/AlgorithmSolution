#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int n;
int a;
int b;
int team[1000][3];

int main() {
	memset(team, 0, sizeof(team));

	scanf("%d %d %d", &n, &a, &b);
	fgetc(stdin);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &team[i][0], &team[i][1], &team[i][2]);
	}

	vector<pair<int, int*>> data;
	for (int i = 0; i < n; ++i) {
		int tmp = abs(team[i][1] - team[i][2]);

		data.push_back(make_pair(tmp, &team[i][0]));
	}

	sort(data.begin(), data.end(), greater<pair<int, int*>>());

	for (int i = 0; i < data.size(); ++i) {
		int tmp_a = 0;
		int tmp_b = 0;
		if (data.at(i).second[1] < data.at(i).second[2]) {
			if (a - data.at(i).second[0] >= 0) {
				a -= data.at(i).second[0];
				tmp_a += data.at(i).second[0];
			}
			else {
				a = 0;
				tmp_a += a;
				tmp_b += data.at(i).second[0] - a;
			}
		}
		else if (data.at(i).second[1] > data.at(i).second[2]) {

		}


		printf("%d %d %d\n", data.at(i).second[0], data.at(i).second[1], data.at(i).second[2]);
	}

	return 0;
}