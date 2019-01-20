 ///
 /// @file    testString.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-17 19:42:55
 ///
 
#include "String.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace wdstring;
 
int main(void)
{
	String s1("hello, world"); 
	cout << s1.size() << endl;
	s1.print();
	
	String s2("nihao, wuhan");
	s2.print();

	String s3;
	s3 = s1 + s2;
	cout << s3.size() << endl;
	s3.print();
	
	String s4;
	s4 = s1 + "123";
	s4.print();
	
	String s5;
	s5 = "123" + s1;
	s5.print();

//	s5 + s1;
//	s5.print();
	
	s1 = "aaa";
	s2 = "bbb";
	s3 = "abc";
	s4 = "aaa";
	cout << "s1 > s2? " << (s1 > s2) << endl;
	cout << "s1 < s2? " << (s1 < s2) << endl;
	cout << "s1 == s4? " << (s1 == s4) << endl;

	cout << "----------------------------------" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "-------输入------" << endl;
	std::cin >> s2;
	cout << "s2 = " << s2 << endl;
	
	cout << "----------------------------------" << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2[0] = " << s2[0] << endl;
	cout << "s2[2] = " << s2[2] << endl;
}
