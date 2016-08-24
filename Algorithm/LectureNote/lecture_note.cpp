#include <iostream>
#include <string>

using namespace std;

string sorting(string str);
void quickSort(string* arr, int start, int end);

int main() {
	int cnt;

	cin >> cnt;

	for (int i = 0; i < cnt; ++i) {
		string str;

		cin >> str;
		cout << sorting(str)<<endl;
	}
}

string sorting(string str) {
	int cnt = str.length() / 2;
	string* data = new string[cnt];
	string rslt;

	for (int i = 0; i < cnt; ++i) {
		data[i] = str.substr(i * 2, 2);
	}
	quickSort(data, 0, cnt - 1);
	for (int i = 0; i < cnt; ++i) {
		rslt += data[i];
	}

	return rslt;
}

void quickSort(string* arr, int start, int end) {
	int idxStart = start;
	int idxEnd = end;
	int idxPivot = (start + end) / 2;
	string tmp;

	while (idxStart <= idxEnd) {
		while (arr[idxStart].compare(arr[idxPivot]) < 0) {
			++idxStart;
		}
		while (arr[idxEnd].compare(arr[idxPivot]) > 0) {
			--idxEnd;
		}
		if (idxStart <= idxEnd) {
			tmp = arr[idxStart];
			arr[idxStart] = arr[idxEnd];
			arr[idxEnd] = tmp;
			++idxStart;
			--idxEnd;
		}

		if (start < idxEnd) {
			quickSort(arr, start, idxEnd);
		}
		if (idxStart < end) {
			quickSort(arr, idxStart, end);
		}

	}

}