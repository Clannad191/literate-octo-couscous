#include <iostream>

#define Max 1024
#define multi(x,y) x*y

int const kMax = 1024;
const int kMin = 1;

using std::cout;
using std::endl;

int multiply(int x)
{
	return x * Max;
}

int test()
{
	int const number = 10;
	//number = 5;
	return kMax + kMin;
}
int main(void)
{
	multiply(10);
	cout << multi(1+2, 3+4) << endl;
	cout << test() << endl;
}
