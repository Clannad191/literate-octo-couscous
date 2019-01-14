#include <iostream>

using std::cout;
using std::endl;

void test0()
{
	// C风格的强制类型转换
	int number1 = 10;
	double number2 = 11.11;

	//number1 = (int)number2;
	number1 = int(number2);
	cout << "number1 = " << number1 << endl;
}

void test1()
{
	int number1 = 20;
	double number2 = 22.22;

	number1 = static_cast<int>(number2);
	cout << "number1 = " << number1 << endl;

	int * pInt = static_cast<int *>(malloc(sizeof(int)));
	*pInt = 10;
	cout << "*pInt = " << *pInt << endl;
}

int main(void)
{
	//test0();
	test1();

	return 0;
}
