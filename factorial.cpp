#include <iostream>

int factorial(int n) {
	if (n > 0) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}

int main() {
	int number;
	int fact_number;
	std::cout << "������ �Է��ϼ��� : " << std::endl;
	std::cin >> number;
	fact_number = factorial(number);
	std::cout << number << "�� ���� ������ " << fact_number << "�Դϴ�. :)" << std::endl;
}