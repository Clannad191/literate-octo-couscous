 ///
 /// @file    Vector.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-12 22:51:50
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
 

void printVectorCapacity(const vector<int> & vec)
{
	//size()：获取当前容器内的元素个数，
	//capacity()：获取容器的总容量
	cout << "vec's size = " << vec.size() << endl
		 << "vec's capacity = " << vec.capacity() << endl;

}

int main(void)
{
	//创建容器，<>内是容器所盛放的元素类型
	//reserve()：预先开辟指定元素数量的空间
	vector<int> numbers;
	numbers.reserve(60);
	printVectorCapacity(numbers);

	//push_back()：存入元素
	numbers.push_back(1);
	printVectorCapacity(numbers);

	numbers.push_back(30);
	printVectorCapacity(numbers);
 
}
