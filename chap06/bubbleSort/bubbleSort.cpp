#include <iostream>

void swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;	
}

void bubble(int a[], int n) {
	int k = 0;
	while (k < n - 1) {
		int j;
		int last = n - 1;
		for (j = n - 1;j > k;j--) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
				last = j;
			}
		}
		k = last;
	}
}

int main() {
	int arr[]= { 1, 3, 7, 5, 9 };
	bubble(arr, 5);
	for (int i = 0;i < 5;i++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}

/*

[Output]

1
3
7
5
9

//Á¤·ÄÀÌ ¾ÈµÇ´Âµ¥,,?

*/
