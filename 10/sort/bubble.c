#include "sort.h"

void bubble_sort(int* a, int N) {
	int i, j, t;
	for (i = 0; i < N - 1; i++) {
		for (j = 1; j < N - i; j++) {
			if (a[j - 1] > a[j]) {
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
	}
}
