#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 

//매크로 선언을 이용한 swap 함수
#define swap(type, x,y) do {type t = x; x = y; y = t;} while (0)

void array_reverse(int a[], int n) {
	int i;
	for (i = 0; i < n / 2;i++) {
		swap(int, a[i], a[n - i - 1]);
	}
}

int main() {
	int i;
	int* x;
	int nx;

	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("%d개의 정수를 입력하세요.\n", nx);
	for (i = 0; i < nx;i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	array_reverse(x, nx);
	printf("배열의 요소를 역순으로 정렬했습니다. \n");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
	free(x);
	return 0;
}

/*
오류 원인이 뭘까.. 
#define _CRT_SECURE_NO_WARNINGS 얘는 왜 더이상 안되는 걸까..?
*/
