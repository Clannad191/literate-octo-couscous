#include <iostream>

using std::cout;
using std::endl;

int add(int x, int y, int z = 0) //默认参数
{
	return x + y + z;
}

int main(void)
{
	int a = 3, b = 5;
	cout << "cout输出流 ---> add(a, b) = " << add(3, 5) << endl; //缺省参数
	printf("printf函数 ---> add(a, b) = %d\n", add(3, 5));
	cout << "add(a, b, c) = " << add(3, 5, 7) << endl;

	return 0;
}
