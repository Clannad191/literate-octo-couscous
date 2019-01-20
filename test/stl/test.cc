 ///
 /// @file    list.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-19 21:59:40
 ///
 
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
			
	}


private:
	int _ix;
	int _iy;
};

void test0()
{
	vector<Point> vec(10);
	list<Point> ll(10);

	Point pt(1, 2);
	vec.push_back(pt);
	//push_back()不会根据形参自动生成对象，
	//必须人工创建新对象（相当于临时对象），然后将该对象作为形参传进去，
	//	然后容器自己深拷贝出一个对象，将该对象作为元素插入容器中
	//最终临时对象会被销毁
	vec.emplace_back(1, 2); //emplace_back()可以自动生成对象，并将该对象添加进容器中

	cout << endl;

}
 
int main(void)
{
 
}
