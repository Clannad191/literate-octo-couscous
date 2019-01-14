 ///
 /// @file    Singleton.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-09 22:13:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance){
			_pInstance = new Singleton();
		}
		return _pInstance;
	}
	
	

	static void destory()
	{
		if(_pInstance){
			delete _pInstance;
		}
	}

private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}

private:
	static Singleton * _pInstance;
};//end of class Singleton

Singleton * Singleton::_pInstance = nullptr;
 
int main(void)
{
	Singleton * ps1 = Singleton::getInstance();
	Singleton * ps2 = Singleton::getInstance();
	cout << "ps1 = " << ps1 << endl
		 << "ps2 = " << ps2 << endl;

	Singleton::destory();

	return 0;
}
