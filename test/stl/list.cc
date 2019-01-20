 ///
 /// @file    list.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-19 22:19:17
 ///
 
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;
 

template <class Container>
void display(const Container & c)
{
	for(auto & elem : c){
		cout << elem << " ";	
	}
	cout << endl;
}

void test0()
{
	list<int> ll(10);

	list<int>::iterator lit = ll.begin();
	ll.insert(lit, 5, 6);

	//遍历list
	for(lit = ll.begin(); lit != ll.end(); ++lit){
		cout << *lit << " ";	
	}
	cout << endl;

	cout << "---------reverse()方法---------" << endl;
	ll.reverse(); //逆置容器中的元素
	display(ll);

	cout << "---------unique()方法---------" << endl;
	ll.unique();
	display(ll);
	

	cout << "---------sort()方法---------" << endl;
	ll.push_back(10);
	ll.push_back(7);
	ll.push_back(12);
	ll.push_back(33);
	ll.sort();
	display(ll);

	std::less<int> lt; //默认就是升序的
	ll.sort(lt);
	display(ll);

	std::greater<int> gt; //想要采用降序方式，就要手动指定
	ll.sort(gt);
	display(ll);
}


int main(void)
{
	test0(); 
}
