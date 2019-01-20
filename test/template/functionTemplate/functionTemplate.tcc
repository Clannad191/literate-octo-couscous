 ///
 /// @file    functionTemplate.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-18 19:04:30
 ///
 

#include <iostream>
using std::cout;
using std::endl;

/* 根据函数模板，通过参数推导，得到具体的模板函数的过程，称为："实例化" */
template <class T>
T add(T x, T y)
{
	cout << "T add(T x, T y)" << endl;
	return x + y;
}

//函数模板和函数模板也可以重载
template <class T>
T add(T x, T y, T z)
{
	cout << "T add(T x, T y, T z)" << endl;
	return x + y + z;
}

//函数模板和普通函数可以重载，而且优先调用普通函数
//int add(int x, int y)
//{
//	cout << "int add(int x, int y)" << endl;
//	return x + y;
//}

