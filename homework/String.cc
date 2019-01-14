 ///
 /// @file    String.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-11 14:05:47
 /// 
 
#include <string.h>
#include <iostream>
//#include <string>
using std::cout;
using std::endl;
//using std::string;
 
class String
{
public:
	String()
	: _pstr(nullptr)
	{

	}

	//构造函数
	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
	}

	//复制构造函数
	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
	}

	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		//1.判断自复制
		if(this != &rhs){
			delete [] this->_pstr;	
			//2.释放左操作数堆空间
			
			this->_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(this->_pstr, rhs._pstr);
			//3.进行深拷贝（先开空间，再复制值）
		}
		
		//返回*this指针
		return *this;
	}
	
	//析构函数
	~String()
	{
		delete [] _pstr;//析构函数内，要释放掉数据成员开辟的空间	
	}

	void print()
	{
		if(_pstr != nullptr){
			cout << "_pstr = " << _pstr << endl;
		}else{
			cout << "_pstr == null!" << endl;
		}
	}

private:
	char * _pstr;
};//end of class String

int main(void)
{
	//测试默认无参构造函数
	String str1;
	str1.print();//出现bug，cout << _pstr ，如果是空指针，会崩溃

	//测试复制构造函数、带参构造函数
	String str2 = "Hello, World";
	String str3("wangdao");

	str2.print();
	str3.print();

	//测试复制构造函数
	String str4 = str3;
	str4.print();

	//测试赋值运算符函数
	str4 = str2;
	str4.print();

	return 0;
}