#include <cstdio>
#include <vector>
#include <utility>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;

int n;
int vol[1001];
int vel[1001];
int sma[1001];

bool BFS(vector<vector<int>> &mat, vector<int> &visited) {
	int start = 0;
	int end = n + n + 1;
	bool flg = false;

	queue<int> que;

	que.push(start);
	visited[start] = start;

	while (!que.empty()) {
		int here = que.front();
		que.pop();

		if (here == end) {
			flg = true;
		}

		for (int i = start; i <= end; ++i) {
			if (mat[here][i] > 0 &&  visited[i] == -1) {
				que.push(i);
				visited[i] = here;
			}
		}
	}

	if(flg) {
		for (int i = end; i != start; i = visited[i]) {
			mat[visited[i]][i] -= 1;
			mat[i][visited[i]] += 1;
		}
		visited[start] = -1;
	}

	return flg;
}

int main() {
	memset(vol, 0, sizeof(vol));
	memset(vel, 0, sizeof(vel));
	memset(sma, 0, sizeof(sma));

	scanf("%d", &n);
	fgetc(stdin);

	vector<vector<int>> mat(n + n + 2, vector<int>(n + n + 2, 0));

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &vol[i], &vel[i], &sma[i]);
		fgetc(stdin);

		for (int j = i - 1; j >= 1; --j) {
			if (vol[i] == vol[j] && vel[i] == vel[j] && sma[i] == sma[j]) {
				mat[i][j + n] = 1;
				mat[j][i + n] = 1;
			}
			else if(vol[i] > vol[j] && vel[i] > vel[j] && sma[i] > sma[j]) {
				mat[i][j + n] = 1;
			}
			else if (vol[i] < vol[j] && vel[i] < vel[j] && sma[i] < sma[j]) {
				mat[j][i + n] = 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		mat[0][i] = 2;
		mat[i + n][n + n + 1] = 1;
	}
	int rslt = 0;
	while (true) {
		vector<int> visited(n + n + 2, -1);
		if (BFS(mat, visited)) {
			++rslt;
		}
		else {
			break;
		}
	}
	printf("%d\n", rslt);

	return 0;
}