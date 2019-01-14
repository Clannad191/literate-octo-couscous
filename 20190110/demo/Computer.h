 ///
 /// @file    Computer.h
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-10 02:50:07
 ///
 
#ifndef __COMPUTER_H_
#define __COMPUTER_H_

class Computer
{
public:
	Computer(const char * brand, float price);
	Computer(const Computer & rsh);

	Computer & operator=(const Computer & rsh);
	void print();

	~Computer();

private:
	char * _brand;
	float _price;
};

#endif
