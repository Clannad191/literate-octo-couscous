 ///
 /// @file    Stack.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-11 19:28:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	//补充1：缺省参数
	Stack(int size = 10)
	: _size(size)
	, _top(-1)
	, _data(new int[size]())
	{
		cout << "Stack()" << endl;
	}

	~Stack()
	{
		if(_data){//补充2：加一层判断
			//得释放数据成员开辟的空间
			delete [] _data;
		}
		cout << "~Stack()" << endl;
	}

	//入栈
	void push(int data)
	{
		//1.先判栈满
		if(!this->full()){
			//_top++;
			//_data[_top] = data;
			_data[++_top] = data;
		}else{
			cout << "The Stack is full, cannot push!" << endl;
		}
	}

	//出栈
	void pop()
	{
		//1.先判栈空
		if(!this->empty()){
			--_top;	
		}else{
			cout << "The Stack is empty, cannot pop!" << endl;
		}
	}

	//读出栈顶元素
	int top() const //补充优化3：函数内不改变数据成员时，都加上 const 修饰
	{
		return _data[_top];	
	}

	//判栈空
	bool empty() const
	{
		//if(_top == -1){
		//	return true;
		//}else{
		//	return false;
		//}
		
		return _top == -1; //补充优化4：精简表达式
	}

	//判栈满
	bool full()
	{
		//if(_top == 9){
		//	return true;
		//}else{
		//	return false;
		//}
		
		return _top == (_size - 1); //补充优化5：精简表达式
	}

private:
	int _size; //补充0：增设数据成员---栈的总大小
	int _top;
	int * _data;
};//end of class Stack

//测试 
int main(void)
{
	//创建栈
	Stack stack;

	//入栈，读栈顶元素
	stack.push(10);
	cout << "stack's top = " << stack.top() << endl;
	stack.push(12);
	cout << "stack's top = " << stack.top() << endl;
	stack.push(14);
	cout << "stack's top = " << stack.top() << endl << endl;

	//出栈
	stack.pop();
	cout << "stack's top = " << stack.top() << endl;
	stack.pop();
	cout << "stack's top = " << stack.top() << endl;
	stack.pop();
	cout << "stack's top = " << stack.top() << endl << endl;

	//判空，判满
	for(size_t idx = 0; idx != 10; ++idx){
		stack.push(idx);
	}

	cout << "Stack is full?" << stack.full() << endl << endl;

	for(size_t idx = 0; idx != 10; ++idx){
		cout << "stack's top = " << stack.top() << endl;
		stack.pop();
	}

	cout << "Stack is empty?" << stack.empty() << endl << endl;
}
