 ///
 /// @file    Point.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-12 20:35:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	//友元的声明仅仅是对访问权限的声明，并非真正的声明，
	//（所以必须在类外再进行一次真正的声明）
	friend void addPoint(const Point & lhs, const Point & rhs);

public:
	//构造函数
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
	
	}
	
	//拷贝构造函数
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
			
	}

	//赋值运算符函数
	Point & operator=(const Point & rhs)
	{
		if(this != &rhs){
			this->_ix = rhs._ix;
			this->_ix = rhs._iy;
		}
		return *this;
	}

	//析构函数
	~Point()
	{
	
	}

	//打印输出
	//自增知识点2：当函数内部不会对数据成员进行修改时，尽量使用const修饰
	void print() const
	{
		cout << "( " << _ix
			 << ", " << _iy
			 << " )" << endl;
	}

private:
	int _ix;
	int _iy;
};//end of class Point


//自我补充知识点1：形参设定为const，禁止修改引用所指对象的值，即lhs、rhs的值
//（引用相当于变量的别名，引用本身则是一个指针常量，本身是不可修改的）
//
//友元：该方法放在类外，只是一个普通方法，而形参却要调用 私有的数据成员，
//		很明显这在类外是不被允许的，
//	有一种方法可以使得类外的函数可以使用该类的私有数据成员
//	那就是--->友元，（声明这个普通函数为该类的朋友）
void addPoint(const Point & lhs, const Point & rhs)
{
	cout << "( " << lhs._ix + rhs._ix
		 << " ," << lhs._iy + rhs._iy
		 << " )" << endl;
}





//=======================================
void test0()
{
	Point pt1(1, 2);
	pt1.print();

	Point pt2(3, 4);
	pt2.print();

	cout << "add pt1 and pt2 ---> " << endl;
	addPoint(pt1, pt2);
}
 
int main(void)
{
	test0(); 
}
