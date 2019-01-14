#include <iostream>

using std::cout;
using std::endl;

void test1()
{
	int value = 100;
	int value2 = 2222;
	int * p1 = &value;

	cout << "*p1 = " << *p1 << endl;
	cout << "&p1 = " << &p1 << endl;

	int const * p2 = &value; // 常量指针
	p2 = &value2; // 首先，他是一个指针，没提常量，所以本身可修改
//	*p2 = 111; // 而他所指向的那个变量的值，不可修改
	cout << "*p2 = " << *p2 << endl;

	int * const p3 = &value2; // 指针常量
//	p3 = &value; // 首先，他是一个常量，提到常量，所以本身不可修改
	*p3 = 131312; // 而他所指向的那个变量的值，则可以修改
	cout << "*p3 = " << *p3 << endl;
}

int main(void)
{
	test1();
}
