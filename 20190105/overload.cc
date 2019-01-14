#include <iostream>

using std::cout;
using std::endl;

// C++的方式调用：会进行名字改编
// C的方式调用：不进行名字改编

#ifdef __cplusplus
extern "C"
{
#endif

// 在 extern "C" 修饰内的函数，按C的方式调用，不进行名字改编
int add(int x, int y)
{
	return x + y;
}

#ifdef __cplusplus
}//end of extern "C"
#endif

int add(int x, int y, int z)
{
	return x + y;
}

int add(int x, double y)
{
	return x + y;
}

int add(double x, int y)
{
	return x + y;
}

int main(void)
{
	int a = 3, b = 5;
	cout << "cout输出流 ---> add(a, b) = " << add(3, 5) << endl;
	printf("printf函数 ---> add(a, b) = %d\n", add(3, 5));

	return 0;
}
