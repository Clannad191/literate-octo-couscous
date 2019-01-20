 ///
 /// @file    VariadicTemplates.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-18 14:10:46
 ///
 
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
 


//可变模板参数
template <typename ... Args> //Args模板参数包
void print(Args ... args) //args函数参数包
{
// sizeof...也可以查看：实例化后参数包中实际参数的个数
// 必须带上 ... ，即"sizeof..."是一个整体
	cout << "sizeof...(Args)" << sizeof...(Args) << endl;
	cout << "sizeof...(args)" << sizeof...(args) << endl;

	//cout << (args...) << endl; //error
	// 虽然 函数参数包args的使用方式确实是：args...（即，展开函数包）
	// 但直接使用却不能输出
}




//递归出口
void display()
{
	cout << endl;
}

template <class T, typename ... Args>
void display(T t, Args ... args) //...在函数参数包args左边时，是声明函数参数包
{
	cout << t << " ";
	display(args...); //...在函数参数包args右边时，表示展开函数参数包
	//递归获取 函数参数包args 的第一个（给了 T t），输出
	//递归出口见上面
}


//递归出口
template <class T>
T sum(T t)
{
	return t;
}

template <class T, typename ... Args>
T sum(T t, Args ... args)
{
	return t + sum(args...);
}



//测试0
void test0()
{
	print(1, 2, 3); 
	print(1, 'a', "haha", 11.11);
}

//测试1
void test1()
{
	display(1, "abc", 'A');	
}


//测试2
void test2()
{
	cout << "sum(3, 5, 7) = " << sum(3, 5, 7) << endl;
	cout << "sum(3.3, 5.5, 7.7) = " << sum(3.3, 5.5, 7.7) << endl;
}

int main(void)
{
	//test0();
	//test1();
	test2();

	return 0;
}
