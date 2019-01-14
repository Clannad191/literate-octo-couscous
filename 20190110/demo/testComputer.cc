 ///
 /// @file    testComputer.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-10 20:05:53
 ///
 
#include "Computer.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Computer com1("lenove", 8888);
	com1.print();
	cout << "&com1 = " << &com1 << endl;

	Computer com2("Thinkpad", 5555);
	com2.print();
	cout << "&com2 = " << &com2 << endl;

	com2 = com1;
	com2.print();
	cout << "&com2 = " << &com2 << endl;
 
}
