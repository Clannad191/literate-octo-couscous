 ///
 /// @file    Singleton.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-13 09:40:33
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
		delete _pInstance;
	}

private:
	Singleton()
	{
		cout << "Singleton()" << endl;	
	}

	~Singleton()
	{
		cout << "~Singleton" << endl;	
	}

private:
	static Singleton * _pInstance;

};//end of class Singleton

Singleton * Singleton::_pInstance = nullptr;
 
int main(void)
{
	Singleton * s1 = Singleton::getInstance();
	cout << "s1 = " << s1 << endl;

	Singleton * s2 = Singleton::getInstance();
	cout << "s2 = " << s2 << endl;

	Singleton::destory();
}
