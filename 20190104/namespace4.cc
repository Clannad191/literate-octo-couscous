#include <iostream>

using std::cout;
using std::endl;

int number = 1; // 全局变量

namespace wd
{
int number = 10; // wd::number

void display(int number)// 形参 number
{
	cout << "形参 number = " << number << endl;
	cout << "命名空间wd的 number = " << wd::number << endl;
	cout << "全局 ::number = " << ::number << endl;// 匿名命名空间 ::
}
}//end of namespace wd

int main(void)
{
	wd::display(100);
}
