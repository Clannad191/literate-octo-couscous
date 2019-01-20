 ///
 /// @file    FileStream.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-15 23:17:33
 ///
 
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;


void test0()
{
	ifstream ifs("FileStream.cc");

	if(!ifs){ //判断流的状态
		cout << "ifstream open file error!" << endl;	
		return;
	}

	ofstream ofs("test.txt");

	if(!ofs){ //判断输出流的状态
		cout << "ofstream open error!" << endl;	
		ifs.close(); //ofs打开失败，但ifs已经打开，要记得关闭
		return;
	}

	string line;
	while(std::getline(ifs, line)){
		cout << line << endl;	
		ofs << line << '\n';
	}

	ofs.close();
}

/*从控制台读入10个数字，存入文件中，然后再从文件中读取，输出到控制台*/
void test1()
{
	fstream fs("test.txt");
	
	if(!fs){ //判断流的状态
		cout << "fstream open file error!" << endl;	
		return;
	}
	
	int number = 0;
	for(size_t idx = 0; idx != 10; ++idx)
	{
		cin >> number;
		fs << number << " "; //充当输出流，把数字输出到文件中
	}

	size_t pos = fs.tellg();
	cout << "当前文件指针位置：" << pos << endl;

	//循环结束后，文件指针已经指向文末，要想从头读取文件，必须进行指针偏移
	fs.seekg(0);

	for(size_t idx = 0; idx != 10; ++idx)
	{
		fs >> number; //充当输入流，把存入文件的数组读入流中（内存中）
		cout << number << " ";
	}
	cout << endl;

	fs.close();

}

 
int main(void)
{
	//test0(); 
	test1();
}
