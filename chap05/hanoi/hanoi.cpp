#include <iostream>

void moveTower(int disk, int first, int last) {
	if (disk > 1) {
		moveTower(disk - 1, first, 6 - first - last);
	}
	std::cout << "원반" << disk << "를 " << first << "기둥에서 " << last << "기둥으로!" << std::endl;
	if (disk > 1) {
		moveTower(disk - 1, 6 - first - last, last);
	}
}

int main() {
	int numberOfDisk;

	std::cout << "하노이의 탑 원반 개수 : " << std::endl;
	std::cin >> numberOfDisk;
	moveTower(numberOfDisk, 1, 3);
}
