#include <stdio.h>
#include <stdlib.h>

void countingSort(int a[], int n, int max) {
	int i;
	int* counting = calloc(max + 1, sizeof(int));
	int* sub = calloc (n, sizeof(int));

	for(i = 0; i <= max; i++) {
		counting[i] = 0;
	}

	for (i = 0; i < n; i++) {
		counting[a[i]]++;
	}

	for (i = 1; i < max; i++) {
		counting[i] = counting[i] + counting[i - 1];
	}

	for (i = n - 1; i >= 0;i--) {
		sub[--counting[a[i]]] = a[i];
	}

	for (i = 0; i < n;i++) {
		a[i] = sub[i];
	}

	free(sub);
	free(counting);
}

int main() {
	int int_array[] = { 3,8,4,1,6,9,2 };
	countingSort(int_array, 7, 10);

	for (int i = 0; i < 7; i++) {
		printf("int_array[%d] = %d\n", i, int_array[i]);
	}
	return 0;
}

/*

[Output]

int_array[0] = 1
int_array[1] = 2
int_array[2] = 3
int_array[3] = 4
int_array[4] = 6
int_array[5] = 8
int_array[6] = 9


*/
