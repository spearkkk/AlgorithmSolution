#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n;
int m;

bool BFS(vector<vector<int>> &mat, vector<int> &visited) {
	int start = 0;
	int end = n + m + 1;
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
			if (mat[here][i] == 1 && visited[i] == -1) {
				que.push(i);
				visited[i] = here;
			}
		}
	}

	if (flg) {
		for (int i = end; i != start; i = visited[i]) {
			mat[visited[i]][i] = -1;
			mat[i][visited[i]] = 1;
		}
		visited[start] = -1;
	}

	return flg;
}

int main() {
	scanf("%d %d", &n, &m);
	fgetc(stdin);

	vector<vector<int>> mat(n + m + 2, vector<int>(n + m + 2, -1));

	for (int i = 1; i <= n; ++i) {
		int cnt_work;
		scanf("%d", &cnt_work);
		fgetc(stdin);
		for (int j = 0; j < cnt_work; ++j) {
			int work;
			scanf("%d", &work);
			fgetc(stdin);

			mat[i][work + n] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		mat[0][i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		mat[n + i][n + m + 1] = 1;
	}

	int rslt = 0;

	while (true) {
		vector<int> visited(n + m + 2, -1);
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