#include <iostream>
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
	int i = 0;
	int nx = 0;
	int key = 0;
	int idx = 0;
	int* x = 0;
	int temp = 0;

	std::cout << "���� �˻�(���ʹ�)" << std::endl;
	std::cout << "����� ���� : " << std::endl;
	std::cin >> nx;

	for (i = 0; i < nx;i++) {
		std::cout << "x[" << i << "] : " << std::endl;
		std::cin >> x[i];
		// �޸� �Ҵ� need
	}

	std::cout << "�˻� �� : ";
	std::cin >> key;
	idx = search(x, nx, key);


	if (idx == -1)
		std::cout << "�˻��� �����߽��ϴ�." << std::endl;

	else
		std::cout << key << "�� " << x[idx] << "�� �ֽ��ϴ�. " << std::endl;

	free(x);

}