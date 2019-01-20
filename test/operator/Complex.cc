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

	double getReal() const
	{
		return _dreal;	
	}
	
	double getImage() const
	{
		return _dimag;	
	}


private:
	double _dreal; //实部
	double _dimag; //虚部

};

//以普通函数形式进行重载
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	cout << "Complex operator+(const Complex &, const Complex &)" << endl;
	return Complex(lhs.getReal() + rhs.getReal(),
					lhs.getImage() + rhs.getImage());	
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
