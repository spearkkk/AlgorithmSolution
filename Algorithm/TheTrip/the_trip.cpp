/**
* @file		the_trip.cpp
* @date		2016.09.06.
* @author	spearkkk
* @brief	https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1078
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int cnt;

	while (scanf("%d", &cnt) != EOF) {
		fgetc(stdin);
		if (cnt == 0) {
			break;
		}

		unsigned long int total = 0L;
		unsigned long int quotient;
		unsigned long int remainder;
		unsigned long int *cost;
		unsigned long int *cost_f;

		cost = new unsigned long int[cnt];
		cost_f = new unsigned long int[cnt];

		for (int i = 0; i < cnt; ++i) {
			float tmp;
			scanf("%f", &tmp);
			fgetc(stdin);
			cost[i] = (unsigned long int)(tmp * 1000) / 10;
			total += cost[i];
		}
		quotient = total / cnt;
		remainder = total % cnt;

		for (int i = 0; i < cnt; ++i) {
			cost_f[i] = quotient;
			if (remainder != 0) {
				++cost_f[i];
				--remainder;
			}
		}

		sort(cost, cost + cnt, greater<unsigned long int>());
		sort(cost_f, cost_f + cnt, greater<unsigned long int>());

		unsigned long int rslt = 0L;
		for (int i = 0; i < cnt; ++i) {
			if (cost[i] > cost_f[i]) {
				rslt += cost[i] - cost_f[i];
			}
		}
		printf("$%d.%02d\n", rslt/100, rslt%100);
	}
	return 0;
}