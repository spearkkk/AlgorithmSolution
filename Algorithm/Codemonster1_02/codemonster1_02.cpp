#include <stdio.h>
#include <vector>

using namespace std;

int func();

void probe(int row, int col, int cnt, int dpth, vector<int> &val, vector<vector<int>> &mat);

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		printf("%d\n", func());
	}
	return 0;
}

int func() {
	int row;
	int col;
	int row_s;
	int col_s;

	scanf("%d %d", &row, &col);
	fgetc(stdin);

	vector<vector<int>> mat(row + 2, vector<int>(col + 2, 0));

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			char tmp;

			scanf("%c", &tmp);
			if (tmp == '.') {
				mat[i + 1][j + 1] = -2;
			}
			else if (tmp == 'E') {
				mat[i + 1][j + 1] = 10;
				row_s = i + 1;
				col_s = j + 1;

			}
			else if (tmp == '~') {

			}
			else {
				mat[i + 1][j + 1] = tmp - '0';
			}
		}
		fgetc(stdin);
	}

	//for (int i = 0; i < row + 2; ++i) {
	//	for (int j = 0; j < col + 2; ++j) {
	//		printf("%d ", mat[i][j]);
	//	}
	//	printf("\n");
	//}

	vector<int> val;

	if (mat[row_s + 1][col_s] != 0) {
		probe(row_s + 1, col_s, 1, row + col - 2, val, mat);
	}
	if (mat[row_s - 1][col_s] != 0) {
		probe(row_s - 1, col_s, 1, row + col - 2, val, mat);
	}
	if (mat[row_s][col_s + 1] != 0) {
		probe(row, col_s + 1, 1, row + col - 2, val, mat);
	}
	if (mat[row_s][col_s - 1] != 0) {
		probe(row, col_s - 1, 1, row + col - 2, val, mat);
	}


	for (int i = 0; i < val.size(); ++i) {
		printf("%d\n", val[i]);
	}

	return 0;
}

void probe(int row, int col, int cnt, int dpth, vector<int> &val, vector<vector<int>> &mat) {
	if (cnt > dpth) {
		return;
	}
	if (mat[row][col] != 10 && mat[row][col] != -2) {
		val.push_back(cnt * 2 * (-2) + mat[row][col]);
		return;
	}

	if (mat[row + 1][col] != 0) {
		probe(row + 1, col, cnt + 1, dpth, val, mat);
	}
	if (mat[row - 1][col] != 0) {
		probe(row - 1, col, cnt + 1, dpth, val, mat);
	}
	if (mat[row][col + 1] != 0) {
		probe(row, col + 1, cnt + 1, dpth, val, mat);
	}
	if (mat[row][col - 1] != 0) {
		probe(row + 1, col - 1, cnt + 1, dpth, val, mat);
	}

}