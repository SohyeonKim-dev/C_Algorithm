#include <iostream>

void moveTower(int disk, int first, int last) {
	if (disk > 1) {
		moveTower(disk - 1, first, 6 - first - last);
	}
	std::cout << "����" << disk << "�� " << first << "��տ��� " << last << "�������!" << std::endl;
	if (disk > 1) {
		moveTower(disk - 1, 6 - first - last, last);
	}
}

int main() {
	int numberOfDisk;

	std::cout << "�ϳ����� ž ���� ���� : " << std::endl;
	std::cin >> numberOfDisk;
	moveTower(numberOfDisk, 1, 3);
}