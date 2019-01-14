#include <iostream>
using std::cout;
using std::endl;

// 带命名空间的函数声明
namespace ds
{
void display();
}//end of ds


namespace wd
{
void show()
{
	cout << "wd::show()" << endl;
	ds::display();// 此时程序还不知道 ds，必须要提前声明
}

void print()
{
	cout << "wd::print()" << endl;
}
}//end of namespace wd

namespace ds
{
void display()
{
	cout << "方法 ds::display()" << endl;
	wd::print();
}
}//end of namespace ds

int main(void)
{
	wd::show();
}
