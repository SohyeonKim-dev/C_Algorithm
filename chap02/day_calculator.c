#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int mdays[][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayOfYear(int y, int m, int d) {
	int i;
	int days = d;

	for (i = 1; i < m; i++) {
		days += mdays[isleap(y)][i - 1];
	}
	return days;
}

int main() {
	int year;
	int month;
	int day;

	int retry;

	do {
	printf("�� : "); 
	scanf("%d", &year);
	printf("�� : ");
	scanf("%d", &month);
	printf("�� : ");
	scanf("%d", &day);

	printf("%d���� %d��°�Դϴ�.\n", year, dayofyear(year, month, day));
	printf("�ٽ� �ұ��? (1 �� ��/0 �� �ƴϿ�) : ");
	scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}