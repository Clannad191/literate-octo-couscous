#include <iostream>

using std::cout;
using std::endl;

int add(int x, int y)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y;
}

int main(void)
{
	int a = 3, b = 5;
	cout << "add(a, b) = " << add(3, 5) << endl;

	return 0;
}
