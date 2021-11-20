#include "sort.h"

void insert_sort(int* a, int N) {
	int i, j, t;
	for (i = 1; i < N; i++) {
		t = a[i];
		j = i;
		while (j > 0 && a[j - 1] > t) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
}
