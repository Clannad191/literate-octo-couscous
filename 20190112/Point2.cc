 ///
 /// @file    Point.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-12 20:35:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point;//类的前向声明

class Line
{
public:
	void addPoint(const Point & lhs, const Point & rhs);
};


class Point
{
	//友元的声明仅仅是对访问权限的声明，并非真正的声明，
	//（所以必须在类外再进行一次真正的声明）
	friend void Line::addPoint(const Point & lhs, const Point & rhs);

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




void Line::addPoint(const Point & lhs, const Point & rhs)
{
	cout << "( " << lhs._ix + rhs._ix
		 << " ," << lhs._iy + rhs._iy
		 << " )" << endl;
}
//友元之成员函数
//首先，如果class Line放在最下面，那么在class Point中声明友元成员函数时，
//		会出现"Line未声明"的error（即使把class Line拿上去也不行，这样又会出现"Point未声明"）
//所以：在Point之前，进行addPoint的声明，然后在后面进行addPoint的定义（顺道也做了Line类的声明）
//然而：这样，在Line的类的声明中，依然会出现"Point未声明"
//		现在再在Line的声明的前面，加上Point的前向声明，即只写"class Point;"，而不进行函数声明


//=======================================
void test0()
{
	Point pt1(1, 2);
	pt1.print();

	Point pt2(3, 4);
	pt2.print();

	//cout << "add pt1 and pt2 ---> " << endl;
	//addPoint(pt1, pt2);
	
	cout << "add pt1 and pt2 ---> " << endl;
	Line().addPoint(pt1, pt2); //直接调用构造函数，相当于得到一个匿名对象
}
 
int main(void)
{
	test0(); 
}
