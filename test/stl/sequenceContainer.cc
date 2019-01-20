 ///
 /// @file    sequenceContainer.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-18 22:13:32
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;


template <class Container>
void display(const Container & c)
{
	//遍历方式之四：最简略写法
	for(auto & elem : c){
		cout << elem << " ";	
	}
	cout << endl;
}


void display(vector<int> & vec, deque<int> & deq, list<int> & ll)
{
	/*通过迭代器访问元素*/
	cout << "--------遍历vector---------" << endl;
	vector<int>::iterator vit = vec.begin();
	for(vit = vec.begin(); vit != vec.end(); ++vit){
		cout << *vit << " "; //迭代器其实就是一个遍历指针，*解引用获取数据	
	}
	cout << endl;

	cout << "--------遍历deque---------" << endl;
	deque<int>::iterator dit = deq.begin();
	for(dit = deq.begin(); dit != deq.end(); ++dit){
		cout << *dit << " ";	
	}	
	cout << endl;
	
	cout << "--------遍历list---------" << endl;
	list<int>::iterator lit = ll.begin();
	for(lit = ll.begin(); lit != ll.end(); ++lit){
		cout << *lit << " ";	
	}
	cout << endl;
}

//测试0
void test0()
{
	/****************************/
	/**** 创建容器的三种方式 ****/
	/****************************/
	vector<int> vec(10); //默认构造
	
	vector<int> vec1; //指定容量

	deque<int> deq(10, 3); //指定容量、每个元素的初始值

	int sz[5] = {1, 2, 3, 4, 5};
	list<int> ll(sz, sz + 5); //根据一对迭代器指针来创建容器

	vector<int> vec2(vec); //根据已有容器，创建新容器

	

	/**************************************************/
	/**** 通过下标访问运算符、at()方法随机访问元素 ****/
	/**************************************************/
	cout << "vec[2] = " << vec[2] << endl;
	cout << "deq[2] = " << deq[2] << endl;
	//cout << "ll[2] = " << ll[2] << endl; //error，list不支持下标访问运算符
	
	cout << "vec[2] = " << vec.at(2) << endl;
	cout << "deq[2] = " << deq.at(2) << endl;
	//cout << "ll[2] = " << ll.at(2) << endl; //error，list不支持at()方法随机访问
	





	/****************************/
	/**** 通过迭代器访问元素 ****/
	/****************************/
	cout << "--------遍历vector---------" << endl;
	vector<int>::iterator vit = vec.begin();
	for(vit = vec.begin(); vit != vec.end(); ++vit){
		cout << *vit << " "; //迭代器其实就是一个遍历指针，*解引用获取数据	
	}
	cout << endl;

	cout << "--------遍历deque---------" << endl;
	deque<int>::iterator dit = deq.begin();
	for(dit = deq.begin(); dit != deq.end(); ++dit){
		cout << *dit << " ";	
	}	
	cout << endl;
	
	cout << "--------遍历list---------" << endl;
	list<int>::iterator lit = ll.begin();
	for(lit = ll.begin(); lit != ll.end(); ++lit){
		cout << *lit << " ";	
	}
	cout << endl;




	/********************************************/
	/**** 遍历元素的第三种方式：auto自动推导 ****/
	/********************************************/
	cout << "--------auto遍历vector---------" << endl;
	auto it1 = vec.begin();
	for(; it1 != vec.end(); ++it1){
		cout << *it1 << " ";	
	}
	cout << endl;

	cout << "--------auto遍历deque---------" << endl;
	auto it2 = deq.begin();
	for(; it2 != deq.end(); ++it2){
		cout << *it2 << " ";	
	}
	cout << endl;

	cout << "--------auto遍历list---------" << endl;
	auto it3 = ll.begin();
	for(; it3 != ll.end(); ++it3){
		cout << *it3 << " ";	
	}
	cout << endl;

	/****************************/
	/****** 插入和删除元素 ******/
	/****************************/
	cout << "--------在尾部插入---------" << endl;
	vec.push_back(7);
	deq.push_back(10);
	ll.push_back(99);
	display(vec, deq, ll);
	cout << endl;

	cout << "--------在头部插入---------" << endl;
	//vec.push_front(6); //error，vector不支持在头部插入，因为底层是数组
	deq.push_front(6);
	ll.push_front(6);
	display(vec, deq, ll);
	cout << endl;
	
	cout << "--------获取头部、尾部元素---------" << endl;
	cout << "vec.front() = " << vec.front() << endl;
	cout << "vec.back() = " << vec.back() << endl;
	cout << "deq.front() = " << deq.front() << endl;
	cout << "deq.back() = " << deq.back() << endl;
	cout << "ll.front() = " << ll.front() << endl;
	cout << "ll.back() = " << ll.back() << endl;
	cout << endl;

	cout << "--------在中间插入---------" << endl;
	vector<int>::iterator vit1 = vec.begin() + 2;
	++vit1;	
	vec.insert(vit1, 15); //在迭代器指针 vit1 之前，插入元素 15
	vec.insert(vit1, 5, 100); //在迭代器指针 vit1 之前，插入5个 元素100
	vec.insert(vit1, vec2.begin(), vec2.end()); //在迭代器指针 vit1 之前，插入从 vec2.begin() 到 vec2.end() 的所有元素
	//后两个参数都是迭代器指针
	
	deque<int>::iterator dit1 = deq.begin() + 2;
	++dit1;
	deq.insert(dit1, 16);
	deq.insert(dit1, 5, 16);
	deq.insert(dit1, vec2.begin(), vec2.end());

	//list<int>::iterator lit1 = ll.begin() + 3; //error
	list<int>::iterator lit1 = ll.begin();
	++lit1; //list底层是链表，禁止随机访问，迭代器指针只能 ++ -- 一个一个偏移
	ll.insert(lit1, 17);
	ll.insert(lit1, 5, 17);
	ll.insert(lit1, vec2.begin(), vec2.end());

	display(vec, deq, ll);
	cout << endl;

	/***其中第三种操作有问题***/
	//在执行：vec.insert(vit1, vec2.begin(), vec2.end()) 的过程中，
	//		容量不够的情况下，会对 vec 进行扩容操作：新开辟两倍大小空间，然后把旧数据拷贝进来，然后释放旧空间
	//	---> 但是迭代器指针 vit1 没有变，仍然指向旧空间（已经释放的空间）
	//	---> 野指针
	//所以必须在插入完毕之后，重新定位迭代器的位置
	vit1 = vec.begin();



	/****************************/
	/****** 删除、清空操作 ******/
	/****************************/
	cout << "--------删除---------" << endl;
	auto vit2 = vec.begin();
	++vit2;
	vec.erase(vit2); //删除迭代器指针 vit2 所指向的元素	
	vec.erase(vit2, vit2 + 3); //删除两迭代器指针之间的元素（区间左闭右开，即含头不含尾）
	display(vec);

	cout << "--------清空---------" << endl;
	vec.clear(); //清空内容，但实际上对于vector、deque空间没有释放，而list释放了（因为list是节点型的，底层是链表）
	display(vec);	
	cout << endl;

}
 
int main(void)
{
	test0(); 
}
