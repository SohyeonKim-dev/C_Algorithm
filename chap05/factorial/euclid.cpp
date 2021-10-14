#include <iostream>

int greatCommonDevisor(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return greatCommonDevisor(y, x % y);
	}
}

int main() {
	int firstNumber = 0;
	int secondNumber = 0;
	int greatComDevisor_number = 0;

	std::cout << "두 정수의 최대 공약수를 구합니다. " << std::endl;
	std::cout << "첫번째 정수를 입력하세요: " << std::endl;
	std::cin >> firstNumber;
	std::cout << "두번째 정수를 입력하세요: " << std::endl;
	std::cin >> secondNumber;

	greatComDevisor_number = greatCommonDevisor(firstNumber, secondNumber);
	
	std::cout << "최대 공약수는 " << greatComDevisor_number << " 입니다. :) " << std::endl;

}