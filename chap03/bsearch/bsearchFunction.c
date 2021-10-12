#include <stdio.h>
#include <stdlib.h>

int int_compare(const int* a, const int* b) {
	if (*a < *b) {
		return 1;
	}
	else if (*a > *b) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	int i = 0;
	int numberOfX = 0;
	int key = 0;
	int* x;
	int* ptr;

	puts("bsearch 함수를 사용하여 검색");
	printf("요소의 개수 : ");
	scanf("%d", &numberOfX);
	x = calloc(numberOfX, sizeof(int));

	printf("내림차순으로 입력하세요.\n", numberOfX);
	printf("x[0] : ");
	scanf("%d", &x[0]);
	for (i = 1; i < numberOfX; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] > x[i - 1]);
	}

	printf("검색 값 : ");
	scanf("%d", &key);
	ptr = bsearch(&key,
		x,
		numberOfX,
		sizeof(int),
		(int(*)(const void*, const void*)) int_compare);

	if (ptr == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", key, (int)(ptr - x));

	free(x);

	return 0;
}
