 ///
 /// @file    Complex.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-16 15:53:30
 ///
 
#include <limits>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Complex
{

	//重载输入输出流，不能采用成员函数的形式！！但是在函数内部又要使用私有数据成员，
	//		所以必须使用友元函数形式进行重载
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);

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

	//以成员函数的形式进行运算符重载
	//	> 因为已经是类内部的成员函数了，所以左操作数就是对象本身this，只需传右操作数即可
	//	> 而且私有成员可以直接使用
	Complex operator+(const Complex & rhs)
	{
		cout << "Complex operator+(const Complex &, const Complex &)" << endl;
		return Complex(this->_dreal + rhs._dreal,
					this->_dimag + rhs._dimag);
	}

	// a++，a变了，表达式变了   ++a，a变了，表达式没变
	Complex & operator++()
	{
		this->_dreal++;
		this->_dimag++;
		return *this;
	}

	//很明显，后置++多了很多步骤：创建对象，最后还要调用拷贝构造函数，效率低
	Complex operator++(int)
	{
		Complex tmp(*this);
		++this->_dreal;
		++this->_dimag;
		return tmp;
	}


private:
	double _dreal; //实部
	double _dimag; //虚部

};



//输出流运算符 << 重载
std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	if(rhs._dreal == 0 && rhs._dimag == 0){ //_dreal == 0, _dimag == 0
		os << 0;	
	}else if(rhs._dreal == 0){ //_dreal == 0, _dimag != 0
		os << rhs._dimag << "i";	
	}else{ //_dreal != 0, _dimag 不一定
		os << rhs._dreal;
		if(rhs._dimag > 0)
			os << " + " << rhs._dimag << "i";
		else
			os << " - " << (-1) * rhs._dimag << "i";
	}

	return os; //这样才能链式编程
	//而且输入输出流的返回值只能是引用，不能是对象
	//	因为：如果是对象的话，返回的时候会调用拷贝构造函数，而流对象都是不可复制的
}

//输入流运算符 << 重载
std::istream & operator>>(std::istream & is, Complex & rhs){
	is >> rhs._dreal >> rhs._dimag;
	return is;
}

//自定义方法，用于健壮地输入数据
void readDouble(std::istream & is, double number)
{
	while(is >> number, !is.eof()){
		if(is.bad()){ //流已崩溃，不可修复错误
			cout << "istream has broken" << endl;
			return;	
		}else if(is.fail()){ //流故障，重置状态、清空缓存还可以用
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\0');
			cout << "please input a valid number:" << endl;
			continue;
		}	
		cout << "number = " << number << endl;
		break;
	}
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
	
	cout << "c1 = " << c1 << endl;

	cout << "输入：" << endl;
	std::cin >> c2;
	cout << "c2 = " << c2 << endl;
}
