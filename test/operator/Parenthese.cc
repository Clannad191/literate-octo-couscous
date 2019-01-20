 ///
 /// @file    Parenthese.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-17 14:44:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class FuncObject
{
public:
	int operator()(int x, int y)
	{
		cout << "operator()(int, int)" << endl;
		return x + y;	
	}
	
	int operator()(int x, int y, int z)
	{
		cout << "operator()(int, int, int)" << endl;
		return x * y * z;	
	}
};
 
int main(void)
{
	FuncObject func;
	cout << "func(1, 2)" << func(1, 2) << endl;
	cout << "func(3, 4, 5)" << func(3, 4, 5) << endl;
}
