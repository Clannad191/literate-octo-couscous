 ///
 /// @file    QueueTemplate.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-20 10:11:33
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


template <class T, size_t kSize = 10>
class Queue
{
public:
	Queue()
	: _front(0)
	, _rear(0)
	, _size(kSize)
	, _data(new T[kSize]())
	{}

	~Queue();
	void push(const T & t);
	void pop();
	bool empty();
	bool full();
	T front();
	T rear();

private:
	int _front;
	int _rear;
	int _size;
	T * _data;
};


template <class T, size_t kSize>
Queue<T, kSize>::~Queue()
{
	if(!_data){
		delete [] _data;
	}
	cout << "~Queue()" << endl;
}

template <class T, size_t kSize>
void Queue<T, kSize>::push(const T & t)
{
	if(!full()){
		_data[_rear] = t;	
		_rear = (_rear + 1) % _size;
	}else{
		cout << "Queue is full, cannot push anymore!" << endl;	
	}
}

template <class T, size_t kSize>
void Queue<T, kSize>::pop()
{
	if(!empty()){
		_front = (_front + 1) % _size;
	}else{
		cout << "Queue is empty, cannot pop anymore!" << endl;	
	}
}

template <class T, size_t kSize>
bool Queue<T, kSize>::empty()
{
	if(_front == _rear){
		return true;	
	}else{
		return false;	
	}
}

template <class T, size_t kSize>
bool Queue<T, kSize>::full()
{
	if((_rear + 1) % _size == _front){
		return true;	
	}else{
		return false;	
	}
}

template <class T, size_t kSize>
T Queue<T, kSize>::front()
{
	return _data[_front];
}

template <class T, size_t kSize>
T Queue<T, kSize>::rear()
{
	return _data[(_rear - 1 + _size) % _size]; //别忘了加_size，然后取余 
}


 
int main(void)
{
	//创建队列
	Queue<string, 10> q;

	cout << "------------入队-------------" << endl;
	//入队，读队头、队尾元素
	q.push("abc");
	cout << "q's front = " << q.front() << endl;
	cout << "q's rear= " << q.rear() << endl;
	q.push("fff");
	cout << "q's front = " << q.front() << endl;
	cout << "q's rear= " << q.rear() << endl;
	q.push("hahahaha");
	cout << "q's front = " << q.front() << endl;
	cout << "q's rear= " << q.rear() << endl;


	cout << "------------出队-------------" << endl;
	//出队
	q.pop();
	cout << "q's front = " << q.front() << endl;
	cout << "q's rear= " << q.rear() << endl;
	q.pop();
	cout << "q's front = " << q.front() << endl;
	cout << "q's rear= " << q.rear() << endl;
	q.pop();
	cout << "q's front = " << q.front() << endl;
	cout << "q's rear= " << q.rear() << endl;


	cout << "------------for循环入队-------------" << endl;
	//判空，判满
	for(size_t idx = 0; idx != 10; ++idx){
		string str = std::to_string(idx) + "helloworld";
		q.push(str);
	}

	cout << "Queue is full?" << q.full() << endl << endl;

	//错误：这样会读取到专门留出来的空闲位
	//for(size_t idx = 0; idx != 10; ++idx){
	//	cout << "q's front = " << q.front() << endl;
	//	q.pop();
	//}
	cout << "------------while循环入队-------------" << endl;
	while(!q.empty()){
		cout << "q's front = " << q.front() << endl;
		q.pop();
	}

	cout << "Queue is empty?" << q.empty() << endl << endl;
 
}
