#include <iostream>

using std::cout;
using std::endl;

namespace wd
{
int number = 10;

namespace wyz
{
int number = 20;
void display()
{

}
}
}//end of namespace wd

int main(void)
{
	cout << "wd::wyz::number = " << wd::wyz::number << endl;	
	printf("C语言的 printf 函数");
}
