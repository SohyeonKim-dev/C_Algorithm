#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int search(int a[], int n, int key) {
	int i = 0;
	a[n] = key;

	while (1) {
		if (a[i] == key) {
			break;
		}
		i++;
	}

	if (i == n) {
		return -1;
	}
	else {
		return i;
	}
}

int main() {
	int i, nx, key, idx;
	int* x;

	puts("���� �˻�(���ʹ�)");
	printf("����� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));

	for (i = 0; i < nx; i++) {		
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("�˻� �� : ");
	scanf("%d", &key);
	idx = search(x, nx, key);

	if (idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", key, idx);

	free(x);							

	return 0;

}

/*


*/