 ///
 /// @file    Singleton.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-11 19:06:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(nullptr ==  _pInstance){
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	//析构函数私有化，数据成员又是静态的，必须自定义一个静态方法用来释放空间
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
	//1.创建一个静态成员数据
	static Singleton * _pInstance;

};//end of class Singleton


//静态成员变量必须在类外进行初始化
Singleton * Singleton::_pInstance = nullptr;

int main(void)
{
	Singleton * ps1 = Singleton::getInstance();
	cout << "ps1 = " << ps1 << endl;

	Singleton * ps2 = Singleton::getInstance();
	cout << "ps2 = " << ps2 << endl;

	//之前开辟的对象空间，并没有被释放，必须手动调用destory方法来释放
	Singleton::destory();
}

