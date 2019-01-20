 ///
 /// @file    String.h
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-16 19:20:32
 ///
 
#ifndef __WD_STRING_H_
#define __WD_STRING_H_

#include <iostream>

namespace wdstring
{

class String
{
	//友元函数方式重载
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);

	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);

	//输入输出流运算符 <<  >> 必须用友元函数的方式进行重载
	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
	friend std::istream & operator>>(std::istream & is, String & rhs);

public:
	String();
	String(const char *);
	String(const String &);
	~String();

	//成员函数方式重载
	String & operator=(const String &);
	String & operator=(const char *);

	String & operator+=(const String &);
	String & operator+=(const char *);

	char & operator[](std::size_t index);
	const char & operator[](std::size_t index) const;
	
	//自定义方法
	std::size_t size() const;
	const char * c_str() const;

	void print();
	

private:
	char * _pstr;

};

std::ostream & operator<<(std::ostream & os, const String & rhs);
std::istream & operator>>(std::istream & is, String & rhs);


//普通函数方式重载
String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);

	bool operator==(const String &, const String &);
	bool operator!=(const String &, const String &);

	bool operator<(const String &, const String &);
	bool operator>(const String &, const String &);
	bool operator<=(const String &, const String &);
	bool operator>=(const String &, const String &);

//自定义方法：将两个C风格字符串拼接起来，返回一个String类型对象
String compose(const char * s1, const char * s2);

}//end of namespace




#endif

