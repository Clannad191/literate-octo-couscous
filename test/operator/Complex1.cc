 ///
 /// @file    Complex.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-16 15:53:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Complex
{
	//以友元函数的方式实现运算符重载
	friend Complex operator+(const Complex & lhs, const Complex & rhs);
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double = 0, double = 0)" << endl;	
	}

	void print() const
	{
		cout << _dreal <<  " + " << _dimag << "i" << endl;	
	}


private:
	double _dreal; //实部
	double _dimag; //虚部

};

//被声明为友元函数之后，可以调用类的私有成员
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	cout << "Complex operator+(const Complex &, const Complex &)" << endl;
	return Complex(lhs._dreal + rhs._dreal,
					lhs._dimag + rhs._dimag);
}
 
int main(void)
{
	Complex c1(1, 2);
	c1.print();

	Complex c2(3, 4);
	c2.print();

	//在没重载 + 和 << 运算符之前，这两个操作都不能进行
	Complex c3;
	c3 = c1 + c2; //error
	c3.print();
	//cout << c1 << endl; //error
}
