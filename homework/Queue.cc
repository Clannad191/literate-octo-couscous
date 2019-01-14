 ///
 /// @file    Queue.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-11 20:16:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(int size = 10)
	: _size(size)
	, _front(0)
	, _rear(0)
	, _data(new int[_size]())
	{
	
	}

	~Queue()
	{
		if(_data){
			delete [] _data;
		}
	}

	//入队
	void enQueue(int value)
	{
		//1.先判队满
		if(!this->full()){
			//错误1：
			//【rear始终指向一个空位置(末尾元素的后一个位置)，front指向首个元素本体】
			//_rear = (_rear + 1) % _size;
			//_data[_rear] = value;
			_data[_rear] = value;
			_rear = (_rear + 1) % _size;
		}else{
			cout << "The Queue is full, cannot enQueue!" << endl;
		}
	}

	//出队
	void deQueue()
	{
		//1.先判队空
		if(!this->empty()){
			_front = (_front + 1) % _size;
		}else{
			cout << "The Queue is empty, cannot deQueue!" << endl;
		}
	}

	//读队头元素
	int front() const
	{
		return _data[_front];	
	}

	//读队尾元素
	int rear() const
	{
		//错误2：
		//return _data[_rear - 1];
		return _data[(_rear - 1 + _size) % _size];
	}

	//判队空
	bool empty() const
	{
		return _front == _rear;	
	}

	//判队满
	bool full() const
	{
		return _front == (_rear + 1) % _size;
	}

private:
	int _size; //队列总大小
	int _front; //队头
	int _rear; //队尾
	int * _data;
};//end of class Queue
 
int main(void)
{
	//创建队列
	Queue queue;

	//入队，读队头、队尾元素
	queue.enQueue(10);
	cout << "queue's front = " << queue.front() << endl;
	cout << "queue's rear= " << queue.rear() << endl;
	queue.enQueue(12);
	cout << "queue's front = " << queue.front() << endl;
	cout << "queue's rear= " << queue.rear() << endl;
	queue.enQueue(14);
	cout << "queue's front = " << queue.front() << endl;
	cout << "queue's rear= " << queue.rear() << endl;

	//出队
	queue.deQueue();
	cout << "queue's front = " << queue.front() << endl;
	cout << "queue's rear= " << queue.rear() << endl;
	queue.deQueue();
	cout << "queue's front = " << queue.front() << endl;
	cout << "queue's rear= " << queue.rear() << endl;
	queue.deQueue();
	cout << "queue's front = " << queue.front() << endl;
	cout << "queue's rear= " << queue.rear() << endl;

	//判空，判满
	for(size_t idx = 0; idx != 10; ++idx){
		queue.enQueue(idx);
	}

	cout << "Queue is full?" << queue.full() << endl << endl;

	//错误3：这样会读取到专门留出来的空闲位
	//for(size_t idx = 0; idx != 10; ++idx){
	//	cout << "queue's front = " << queue.front() << endl;
	//	queue.deQueue();
	//}
	while(!queue.empty()){
		cout << "queue's front = " << queue.front() << endl;
		queue.deQueue();
	}

	cout << "Queue is empty?" << queue.empty() << endl << endl;
}
