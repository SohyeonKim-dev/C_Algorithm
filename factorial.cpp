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
	std::cout << "정수를 입력하세요 : " << std::endl;
	std::cin >> number;
	fact_number = factorial(number);
	std::cout << number << "의 순차 곱셈은 " << fact_number << "입니다. :)" << std::endl;
}