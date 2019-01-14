 ///
 /// @file    test0.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-12 18:54:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::string;


void test0()
{
	//引用测试
	int number = 10;
	
	int & ref = number; //引用
	cout << "before change ----> " << endl << "ref = " << ref << endl;

	ref = 20;
	cout << "after change ----> " << endl << "ref = " << ref << endl;
 
	//强制类型转换测试
	double num1 = 11.11;
	cout << "double num1 = " << num1 << endl;

	int a = static_cast<int>(num1);
	cout << "int a = " << a << endl;
}

void test1()
{
	std::string s1 = "Hello";
	std::string s2 = "World";
	cout << "s1 = " << s1 << endl
		 << "s2 = " << s2 << endl;
	
	std::string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;

	const char * s4 = s3.c_str();
	cout << "s4 = " << s4 << endl;

	size_t len = s1.size();
	cout << "len = " << len << endl;
	len = s2.length();
	cout << "len = " << len << endl;

	std::string s5 = s3.append("abc");
	s5 += 'A';
	cout << "s5 = " << s5 << endl;

	std::string s6 = s1.substr(2, 2);
	cout << "s6 = " << s6 << endl;

	size_t pos = s1.find("ll");
	cout << "find the 'll' in the 'Hello' : " << pos << endl;
}

int main(void)
{
	//test0();
	test1();
}

