 ///
 /// @file    String.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-16 19:28:22
 ///
 
#include "String.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace wdstring;


/******** 构造函数、析构函数 ********/
String::String()
: _pstr(nullptr)
{

}

String::String(const char * pstr)
: _pstr(new char[strlen(pstr) + 1]())
{
	strcpy(_pstr, pstr);
}

String::String(const String & rhs)
: _pstr(new char[strlen(rhs._pstr) + 1]())
{
	strcpy(_pstr, rhs._pstr);	
}

String::~String()
{
	if(_pstr){
		delete [] _pstr;	
	}
}

/******** 重载 = 赋值运算符 ********/
String & String::operator=(const String & rhs)
{
	cout << "String::operator=(const String & rhs)" << endl;
	//1.判断自复制
	//2.释放做操作数空间
	//3.进行深拷贝
	//4.返回this指针
	if(this != &rhs){
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr) + 1]();
		strcpy(_pstr, rhs._pstr);
	}
	return *this;
}

String & String::operator=(const char * pstr)
{
	cout << "String::operator=(const char * pstr)" << endl;
	delete [] _pstr;
	_pstr = new char[strlen(pstr) + 1]();
	strcpy(_pstr, pstr);
	return *this;
}




/******** 重载 += 赋值运算符 ********/
String & String::operator+=(const String & rhs)
{
	// a += b;   a = a + b;
	cout << "String::operator+=(const String & rhs)" << endl;
	String tmp = wdstring::compose(this->c_str(), rhs.c_str()); 

	this->_pstr = tmp._pstr;

	return *this; 
}

String & String::operator+=(const char * pstr)
{
	cout << "String::operator+=(const char * pstr)" << endl;
	String tmp = wdstring::compose(this->c_str(), pstr); 

	this->_pstr = tmp._pstr;

	return *this; 
}


/******** 重载 [] 下标访问运算符 ********/
char & String::operator[](std::size_t index)
{
	if(index < strlen(_pstr)){
		return _pstr[index];	
	}else{
		static char nullchar = '\0';
		return nullchar;
	}
}


const char & String::operator[](std::size_t index) const
{
	if(index < strlen(_pstr)){
		return _pstr[index];	
	}else{
		static char nullchar = '\0';
		return nullchar;
	}

}


	

/******** 获取长度  ********/
std::size_t String::size() const
{
	return strlen(_pstr);
	//size_t idx = 0;
	//while(_pstr[idx] != '\n'){
	//	++idx;	
	//}
	//return idx;
}

/******** String ---> char * ********/
const char * String::c_str() const
{
	cout << "--- const char * String::c_str() const ---" << endl;
	return _pstr;	
}




//打印输出字符串内容
void String::print()
{
	cout << "_pstr = " << _pstr << endl;
}




/*********************************************************/
/*************** 采用友元函数形式重载 ********************/
/*********************************************************/

bool wdstring::operator==(const String & lhs, const String & rhs)
{
	return !strcmp(lhs.c_str(), rhs.c_str());
}

bool wdstring::operator!=(const String & lhs, const String & rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str());
}

bool wdstring::operator<(const String & lhs, const String & rhs)
{
	int flag = strcmp(lhs.c_str(), rhs.c_str());
	if(flag < 0){
		return true;	
	}
	return false;
}

bool wdstring::operator>(const String & lhs, const String & rhs)
{
	int flag = strcmp(lhs.c_str(), rhs.c_str());
	if(flag > 0){
		return true;	
	}
	return false;
}

bool wdstring::operator<=(const String & lhs, const String & rhs)
{
	int flag = strcmp(lhs.c_str(), rhs.c_str());
	if(flag <= 0){
		return true;	
	}
	return false;
}

bool wdstring::operator>=(const String & lhs, const String & rhs)
{
	int flag = strcmp(lhs.c_str(), rhs.c_str());
	if(flag >= 0){
		return true;	
	}
	return false;
}




//输入输出流运算符 <<  >> 必须用友元函数的方式进行重载
std::ostream & wdstring::operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

std::istream & wdstring::operator>>(std::istream & is, String & rhs)
{
	is >> rhs._pstr; 
	return is;
}




/*********************************************************/
/*************** 采用普通函数形式重载 ********************/
/*********************************************************/


/******** 重载 + 加法运算符 ********/
String wdstring::operator+(const String & lhs, const String & rhs)
{
	cout << "wdstring::operator+(const String &, const Stirng &)" << endl;

	String tmp = wdstring::compose(lhs.c_str(), rhs.c_str());
	return tmp;
}

String wdstring::operator+(const String & lhs, const char * pstr)
{
	cout << "wdstring::operator+(const String &, const char *)" << endl;

	String tmp = wdstring::compose(lhs.c_str(), pstr);
	return tmp;
}

String wdstring::operator+(const char * pstr, const String & rhs)
{
	cout << "wdstring::operator+(const String &, const char *)" << endl;

	String tmp = wdstring::compose(pstr, rhs.c_str());
	return tmp;
}







//自定义方法：将两个C风格字符串拼接起来，返回一个String类型对象
//野指针了？？
String wdstring::compose(const char * s1, const char * s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	char * str = new char[len1 + len2 - 1]();
	
	size_t idx = 0;
	for(idx = 0; idx != len1; ++idx){
		str[idx] = s1[idx];
	}

	for(idx = 0; idx != len2; ++idx){
		str[len1 + idx] = s2[idx];
	}

	return String(str);
}


//int main(void)
//{
//	String s1("hello, world"); 
//	cout << s1.size() << endl;
//	s1.print();
//	
//	String s2("nihao, wuhan");
//	s2.print();
//
//	String s3;
//	s3 = s1 + s2;
//	cout << s3.size() << endl;
//	s3.print();
//	
//	String s4;
//	s4 = s1 + "123";
//	s4.print();
//	
//	String s5;
//	s5 = "123" + s1;
//	s5.print();
//
////	s5 + s1;
////	s5.print();
//	
//	s1 = "aaa";
//	s2 = "bbb";
//	s3 = "abc";
//	s4 = "aaa";
//	cout << "s1 > s2? " << (s1 > s2) << endl;
//	cout << "s1 < s2? " << (s1 < s2) << endl;
//	cout << "s1 == s4? " << (s1 == s4) << endl;
//
//	cout << "----------------------------------" << endl;
//	cout << "s1 = " << s1 << endl;
//	cout << "-------输入------" << endl;
//	std::cin >> s2;
//	cout << "s2 = " << s2 << endl;
//	
//	cout << "----------------------------------" << endl;
//	cout << "s2 = " << s2 << endl;
//	cout << "s2[0] = " << s2[0] << endl;
//	cout << "s2[2] = " << s2[2] << endl;
//}
