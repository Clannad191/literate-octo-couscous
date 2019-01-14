 ///
 /// @file    testVector.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-13 09:50:37
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void printVectorCapacity(const vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl
		 << "vec's capacity = " << vec.capacity() << endl;
}

void test0()
{
	vector<int> vec;
	vec.reserve(60);
	printVectorCapacity(vec);

	vec.push_back(1);
	printVectorCapacity(vec);

	vec.push_back(20);
	printVectorCapacity(vec);
	
}

int main(void)
{
	test0(); 
}
