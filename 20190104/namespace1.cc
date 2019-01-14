#include <iostream>

namespace wd
{
	int number = 10;

	void display()
	{
		std::cout << "wd::display()" << std::endl;
		std::cout << "number = " << number << std::endl;
	}
}//end of namespace wd

int cout()
{
	int a = 3;
	int b = 5;
	std::cout << "a + b =" << a+b << std::endl;
}

int main(void)
{
	wd::display();
	cout();
}
