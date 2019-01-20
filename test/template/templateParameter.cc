 ///
 /// @file    templateParameter.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-18 19:36:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数：
//	可以是类型参数
//	也可以是非类型参数，是个常量表达式（这种常量表达式更具有一般性）
//无论是类型参数、还是非类型参数，都可以设置默认值
//
//这种常量表达式，是可以根据 模板实例化 时给定的值进行修改的
//		而之前我们定义常量时所使用的：#define，const 都是一旦定义，不可修改
template <class T = int, short kMin = 10>
T multiply(T x, T y)
{
	cout << "T multiply(T x, T y)" << endl;
	return x * y * kMin;
}
 
int main(void)
{
	short sa = 2, sb = 3;
	cout << "multiply<short, 5>(sa, sb) = " << multiply(sa, sb) << endl;
	cout << "multiply(sa, sb) = " << multiply<short, 5>(sa, sb) << endl;
	return 0;
}
