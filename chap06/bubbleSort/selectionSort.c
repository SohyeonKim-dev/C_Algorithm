#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void selection(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(int, a[i], a[min]);
	}
}

int main() {
	int a[] = { 1,4,3,6,7 };
	selection(a, 5);
	for (int i = 0; i < 5; i++)
		printf("x[%d] = %d\n", i, a[i]);
	return 0;
}

/*

[Output]

x[0] = 1
x[1] = 3
x[2] = 4
x[3] = 6
x[4] = 7

*/