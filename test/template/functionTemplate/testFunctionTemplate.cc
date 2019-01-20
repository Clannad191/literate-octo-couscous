 ///
 /// @file    testFunctionTemplate.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-18 19:30:33
 ///
 
#include "functionTemplate.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	cout << "add(1, 2) = " << add(1, 2) << endl;	
	cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;
	cout << "add(3.3, 4.4) = " << add(3.3, 4.4) << endl;

	cout << endl;
	//可以在调用的时候显式实例化，也可以默认隐式实例化（编译器自己判断）
	cout << "add<double>(1.1, 2.2) = " << add<double>(1.1, 2.2) << endl;

	cout << endl;
	//cout << "add(1, 2.2) = " << add(1, 2.2) << endl;
	//error，模板十分严格，没有对应类型的模板，就不能进行实参替换，无法调用
	
	return 0;
}
