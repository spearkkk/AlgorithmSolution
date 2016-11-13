#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <iterator>
#include <queue>

using namespace std;

int n;
int m;

bool BFS(vector<vector<int>> &mat, vector<int> &visited, int s, int e) {
	queue<int> que;
	bool flg = false;

	que.push(s);
	visited[s] = s;
	
	while (!que.empty()) {
		int here = que.front();
		que.pop();

		if (here == e) {
			flg = true;
		}

		for (int i = 0; i < n + m + 2; ++i) {
			if (mat[here][i] == 1 && visited[i] == -1) {
				que.push(i);
				visited[i] = here;
			}
		}
	}

	if (flg) {
		for (int i = n + m + 1; i != 0; i = visited[i]) {
			mat[visited[i]][i] = -1;
			mat[i][visited[i]] = 1;
		}
		visited[s] = -1;
	}

	return flg;
}

int main() {
	scanf("%d %d", &n, &m);
	fgetc(stdin);

	vector<vector<int>> mat(n + m + 2, vector<int>(n + m + 2, -1));

	for (int i = 0; i < m; ++i) {
		int s;
		int d;

		scanf("%d %d", &s, &d);
		fgetc(stdin);

		mat[s][n + d] = 1;
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
		if (BFS(mat, visited, 0, n + m + 1)) {
			++rslt;
		}
		else {
			break;
		}		
	}

	printf("%d\n", rslt);

	return 0;
}