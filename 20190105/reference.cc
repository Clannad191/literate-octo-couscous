#include <iostream>

using std::cout;
using std::endl;

// 引用就相当于是变量的别名
void test0()
{
	int number = 10;
	int & ref = number;// 相当于变量的别名

	cout << "number = " << number << endl;
	cout << "ref = " << ref << endl;
	cout << "&number = " << &number << endl;
	cout << "&ref = " << &ref << endl;
	
	ref = 1000;
	cout << endl << "修改之后：" << endl;
	cout << "number = " << number << endl;
	cout << "ref = " << ref << endl;
	cout << "&number = " << &number << endl;
	cout << "&ref = " << &ref << endl;
}

// 引用作为参数传递，实例：交换两个int的值
void swap1(int x, int y)
{
	int temp = x;
	x = y;
	y = x;
}

void swap2(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap3(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

void test1()
{
	int a = 3, b = 5;
	cout << "交换以前：" << endl;
	cout << "a = " << a << ", b = " << b << endl;

	swap1(a, b);
	cout << "交换以后：" << endl;
	cout << "a = " << a << ", b = " << b << endl;

	swap2(&a, &b);
	cout << "交换以后：" << endl;
	cout << "a = " << a << ", b = " << b << endl;

	swap3(a, b);
	cout << "交换以后：" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}

// 引用作为函数返回值
int array[10] = {1, 2, 3, 4, 5};

int & getByIndex(int idx)
{
	return array[idx];
}

// 典型错误1：返回局部变量的引用
//int & getNumber1()
//{
//	int number = 10;
//	return number;// 局部变量，函数执行完毕，空间就释放了，再操作无意义
//}

// 典型错误2：轻易返回堆空间的引用，容易造成内存泄露
int & getNumber2()
{
	int * number = new int(100); // 开辟一块堆空间
	return *number; // 因为引用要求返回变量本身，所以要解引用
}

void test2()
{
	cout << "array[0] = " << getByIndex(0) << endl;
	// cout << "number = " << getNumber1() << endl;
	cout << "number = " << getNumber2() << endl;
	// 在表达式中调用，只开辟，没办法释放，造成内存泄露

	int & ref = getNumber2();
	cout << "number = " << ref << endl;
	delete &ref; 
	// 这种用法是正确的，但是太诡异了，对引用取地址
	//（而且别人未必知道你的函数内部是怎么实现的，很容易忘记释放）
}


int main(void)
{
	//test0();
	//test1();
	test2();
}
