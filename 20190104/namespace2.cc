#include <iostream>
//using std::cout;
//using std::endl;
using namespace std;
namespace wd
{
	int number = 10;

	void display()
	{
		cout << "wd::display()" << endl;
		cout << "number = " << number << endl;
	}
}//end of namespace wd

/*
如果直接使用 using 编译指令
当我们不熟悉 std 命名空间中的函数时，很可能会自定义一个重名的函数
这样就会报错，例如：函数 cout 具有二义性
*/
//int cout()
//{
//	return 10;
//}

int main(void)
{
	wd::display();
//	cout();
}
