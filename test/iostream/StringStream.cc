 ///
 /// @file    StringStream.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-16 09:05:34
 ///
 
#include <iostream>
#include <fstream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

/*输入输出：从内存输出到流中：<<，从流输入到内存中：>>，
 * 都是以内存为参考系（变量就是内存，流则是相当于外存缓冲区）*/
void test0()
{
	int number1 = 10;
	int number2 = 10;

	//stringstream ss;
	ostringstream oss;
	oss << "number1 = " << number1 << ", number2 = " << number2 << endl; //输出流功能
	string line = oss.str(); //将字符串流缓冲区中的数据转化为 字符串
	cout << line;
	
	string key;
	int value;
	//字符串输入流功能
	istringstream iss;
	while(iss >> key >> value, !iss.eof()){
		cout << key << " --- " << value << endl;
	}
}

/*利用字符串流，从配置文件中读取一行一行键值对，
 * 形参传配置文件名*/
void readConfig(const string & filename)
{
	fstream fs(filename); //此时充当输入流
	if(!fs){
		cout << "fs open file error!" << endl;	
		return;
	}

	string line;
	while(getline(fs, line)){
		string key, value;
		stringstream ss(line); //构造函数参数：要存入流的字符串
		ss >> key >> value; //输入流，把流中的数据输入到内存中的变量里
		cout << key << " --- " << value << endl;
	}

	fs.close();
}
 
int main(void)
{
	//test0(); 
	readConfig("my.conf");
}
