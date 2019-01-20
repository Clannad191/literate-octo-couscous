 ///
 /// @file    testFilestream.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-15 19:24:46
 ///
 
#include <iostream>
#include <fstream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

void test0()
{
	ifstream ifs;
	ifs.open("The_Holy_Bible.txt");

	if(!ifs.good()){
		cout << "ifstream open error!" << endl;
		return;
	}

	ofstream ofs;
	ofs.open("test.txt");
	
	if(!ofs){
		cout << "ofstream open error!" << endl;
		ifs.close(); //执行到这里，说明ifs已经打开，而ofs故障无法继续，必须把ifs关掉
		return;
	}

	string line;
	while(std::getline(ifs, line)){
		cout << line << endl;
		ofs << line << '\n';	
	}
	

	ofs.close();
}

void test1()
{
	string file = "test2.txt";
	fstream fs(file);

	if(!fs){//判断流的状态
		cout << "fstream open file " << file << " error!" << endl;	
	}

	/*从控制台输入10个数到流中*/
	int number = 0;
	for(size_t idx = 0; idx != 10; ++idx)
	{
		cin >> number;
		fs << number << " ";//文件输入流的功能
	}

	
	fs.clear();
	for(size_t idx = 0; idx != 10; ++idx)
	{
		fs >> number;
		cout << number << " ";
	}

}
 
int main(void)
{
	//test0(); 
	test1();
}
