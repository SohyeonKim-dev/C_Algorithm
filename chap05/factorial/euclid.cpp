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

	std::cout << "�� ������ �ִ� ������� ���մϴ�. " << std::endl;
	std::cout << "ù��° ������ �Է��ϼ���: " << std::endl;
	std::cin >> firstNumber;
	std::cout << "�ι�° ������ �Է��ϼ���: " << std::endl;
	std::cin >> secondNumber;

	greatComDevisor_number = greatCommonDevisor(firstNumber, secondNumber);
	
	std::cout << "�ִ� ������� " << greatComDevisor_number << " �Դϴ�. :) " << std::endl;

}