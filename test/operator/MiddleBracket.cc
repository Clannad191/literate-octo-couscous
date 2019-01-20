 ///
 /// @file    MiddleBracket.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-17 15:16:53
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
	CharArray(size_t size)
	: _data(new char[size]())
	{
		cout << "CharArray(size_t size)" << endl;	
	}


	char & operator[](size_t idx)
	{
		cout << "operator[](size_t idx)" << endl;
		if(idx < size()){
			return _data[idx];	
		}else{
			static char nullchar = '\0';
			return nullchar;
		}
	}

	size_t size() const
	{
		return strlen(_data);	
	}

private:
	char * _data;
};
 
int main(void)
{
	const char * str = "hello";
	CharArray cha(10);

	for(size_t idx = 0; idx < 5; ++idx){
		cha[idx] = str[idx];	
		cout << "cha[idx]" << cha[idx] << ", str[idx]" << str[idx] << endl;
	}

	for(size_t idx = 0; idx < 5; ++idx){
		cout << "cha[idx] = " << cha[idx] << endl;	
	}
}
