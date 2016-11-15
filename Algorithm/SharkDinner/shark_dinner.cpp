/**
* @file		cattleshed_allocation.cpp
* @date		2016.11.14.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1671
*			keypoint는 두 상어의 능력치가 같을 때, 한 상어가 다른 상어만 잡을 수 있도록 예외처리 해야한다.
*/
#include <cstdio>
#include <vector>
#include <utility>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 987654321;

int n;
int vol[1001];
int vel[1001];
int sma[1001];

int mat[1002][1002];
int flow [1002][1002];

int networkflow(int source, int sink) {
	memset(flow, 0, sizeof(flow));
	int total_flow = 0;

	while (true) {
		vector<int> parent(1002, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty() && parent[sink] == -1) {
			int here = q.front();
			q.pop();
			for (int there = 1; there <= 1001; ++there) {
				if (mat[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
			}
		}

		if (parent[sink] == -1) {
			break;
		}

		int amount = INF;
		for (int p = sink; p != source; p = parent[p]) {
			amount = min(mat[parent[p]][p] - flow[parent[p]][p], amount);
		}
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		total_flow += amount;
	}
	return total_flow;
}

int main() {
	memset(vol, 0, sizeof(vol));
	memset(vel, 0, sizeof(vel));
	memset(sma, 0, sizeof(sma));

	scanf("%d", &n);
	fgetc(stdin);

	memset(mat, 0, sizeof(mat));

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &vol[i], &vel[i], &sma[i]);
		fgetc(stdin);

		for (int j = i - 1; j >= 1; --j) {
			if(vol[i] >= vol[j] && vel[i] >= vel[j] && sma[i] >= sma[j]) {
				mat[i][n + j] = 1;
			}
			if (vol[i] <= vol[j] && vel[i] <= vel[j] && sma[i] <= sma[j]) {
				mat[j][n + i] = 1;
			}
			if (vol[i] == vol[j] && vel[i] == vel[j] && sma[i] == sma[j]) {
				mat[i][n + j] = 0;
			}
		}
		mat[0][i] = 2;
		mat[n + i][1001] = 1;
	}

	//for (int i = 0; i <= n; ++i) {
	//	for (int j = 0; j <= n; ++j) {
	//		printf("%d ", mat[i][j]);
	//	}
	//	printf("\n");
	//}

	int rslt = networkflow(0, 1001);

	printf("%d\n", n - rslt);

	return 0;
}