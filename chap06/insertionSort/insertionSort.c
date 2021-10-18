#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[], int n) {
	int i = 1;
	int j = 1;

	for (i = 1; i < n; i++) {
		int temp = a[i];
		for (j = i; j > 0 && a[j - 1] > temp; j--) {
			a[j] = a[j - 1]; // ÇÑÄ­¾¿ ¿À¸¥ÂÊÀ¸·Î ÀÌµ¿
		}
		a[j] = temp;
	}
}

int main() {
	int int_array[] = { 3,6,4,8,5 };
	insertionSort(int_array, 5);

	for (int i = 0; i < 5; i++) {
		printf("x[%d] = %d\n", i, int_array[i]);
	}
	return 0;
}

/*

[Output]

x[0] = 3
x[1] = 4
x[2] = 5
x[3] = 6
x[4] = 8

*/
