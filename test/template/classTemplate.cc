 ///
 /// @file    classTemplate.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-18 19:45:49
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//模板类在实现上与普通类没有任何不同
template <class T, size_t kSize = 10>
class Stack
{
public:
	//1、成员函数模板
	//2、模板类里还可以嵌套模板函数、模板类
	template <class F = int>
	F print()
	{
		F f;
		return f;	
	}


	Stack()
	: _top(-1)
	, _data(new T[kSize]())
	{}

	~Stack();

	bool full() const;
	bool empty() const;
	void push(const T & t);
	void pop();
	T top();	
	
private:
	int _top;
	T * _data;
};

//在类外进行模板类中成员函数的定义，必须带上模板头
//	而且在指定作用域的时候，尖括号不能省！！！
template <class T, size_t kSize>
Stack<T, kSize>::~Stack()
{
	delete [] _data;
	cout << "~Stack()" << endl;
}
 
//判满
template <class T, size_t kSize>
bool Stack<T, kSize>::full() const
{
	return kSize - 1 == _top;
}

//判空
template <class T, size_t kSize>
bool Stack<T, kSize>::empty() const
{
	return _top == -1;
}

//入栈
template <class T, size_t kSize>
void Stack<T, kSize>::push(const T & t)
{
	if(!full()){
		_data[++_top] = t;	
	}else{
		cout << "Stack is full, cannot push anymore!" << endl;	
	}
}

//出栈
template <class T, size_t kSize>
void Stack<T, kSize>::pop()
{
	if(!empty()){
		--_top;	
	}else{
		cout << "Stack is empty!" << endl;	
	}
}

//返回栈顶元素
template <class T, size_t kSize>
T Stack<T, kSize>::top()
{
	return _data[_top];
}




int main(void)
{
	Stack<string, 5> s;	 
	cout << "判栈空：" << s.empty() << endl;

	s.push("hello, 0");
	cout << "判栈空：" << s.empty() << endl;
	
	for(size_t idx = 1; idx != 5; ++idx){
		s.push(string(2, 'A' + idx));
	}
	cout << "判栈满：" << s.full() << endl;

	cout << "出栈：" << endl;
	for(size_t idx = 0; idx != 5; ++idx){
		cout << s.top() << endl;
		s.pop();
	}

	cout << "栈顶元素：" << s.top() << endl;
}
