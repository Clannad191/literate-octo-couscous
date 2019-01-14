 ///
 /// @file    Computer.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-10 18:57:14
 ///
 
#include "Computer.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 

Computer::Computer(const char * brand, float price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
{
	strcpy(_brand, brand); //上面new只是开辟空间并初始化，此处才赋上真正的值
	cout << "Computer(const char * brand, float price)" << endl;
}

// 拷贝构造函数：深拷贝
Computer::Computer(const Computer & rhs)
: _brand(new char[strlen(rhs._brand) + 1]())
, _price(rhs._price)
{
	strcpy(_brand, rhs._brand);
	cout << "Computer(const Computer & rhs)" << endl;

}

// 系统提供的赋值表达式函数，只是复制地址，不足以满足需求
//Computer & Computer::operator=(const Computer & rhs)
//{
//	_brand = rhs._brand;
//	_price = rhs._price;
//
//	return *this;
//}

// 必须进行深拷贝，先开辟空间，然后把值复制过去，再释放原来空间，
// 最后改变指针指向，指往新空间
// 这段代码可以优化
Computer & Computer::operator=(const Computer & rhs)
{
	//char * pstr = new char[strlen(rhs._brand) + 1](); //开辟空间并初始化
	//strcpy(pstr, rhs._brand); //复制
	//delete [] _brand; //释放原有空间

	//_brand = pstr;//改变指针指向
	//_price = rhs._price;

	//return *this;
	
	if(&rhs != this){
		delete [] _brand; // 释放左操作数（反正也没用了，之后也是要释放的）
		
		this->_brand = new char[strlen(rhs._brand) + 1]();
		strcpy(this->_brand, rhs._brand);

		this->_price = rhs._price;
	}


	return *this;
}



Computer::~Computer()
{
	delete [] _brand;// _brand的空间是new出来的
	cout << "~Computer()" << endl;
}

//===========================================
void Computer::print()
{
	cout << "_brand = " << _brand << endl
		 << "_price = " << _price << endl;
}
