 ///
 /// @file    Dictionary.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-16 11:22:02
 ///

#include <time.h>
 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //算法头文件
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;


/*自定义数据结构：词典中的一条记录*/
struct Record
{
	/*构造函数*/
	Record(const string & word, const size_t frequency)
	: _word(word)
	, _frequency(frequency)
	{}
	

	string _word; //单词
	size_t _frequency; //词频
};

/*重载 < 方法，否则sort()无法比较*/
bool operator<(const Record & lhs, const Record & rhs)
{
	return lhs._frequency < rhs._frequency;
}

class Dictionary
{
public:
	Dictionary(int i = 13000)
	{
		//预先开辟空间
		_dict.reserve(i);
	}

	/*
	 * 从文件中读取数据，并统计单词和词频
	 * 1. 单词是以空格分隔的
	 *
	 */
	void read(const string & filename)
	{
		ifstream ifs(filename);	
		if(!ifs){
			cout << "ifstream open file " << filename << " error!" << endl;	
			return;
		}

		string word;
		while(ifs >> word, !ifs.eof()){ //ifs默认以空格分隔
			size_t idx;
			for(idx = 0; idx != _dict.size(); ++idx)
			{
				if(_dict[idx]._word == word){
					++_dict[idx]._frequency;
					break;
				}		
			}

			if(idx == _dict.size()){ //说明没有相同的，是一个新单词
				Record record(word, 1);
				_dict.push_back(record);
			}
		}
		
		//1.补充操作：对容器内容进行排序
		std::sort(_dict.begin(), _dict.end());


		ifs.close();
	}

	/*
	 *将内存中的数据（存在对象的数据成员中），输出到指定文件中
	 */
	void store(const string & filename)
	{
		ofstream ofs(filename);	
		if(!ofs){
			cout << "fstream open error!" << endl;	
			return;
		}

		//将vector容器中的数据一组一组输入到输出流中（输出流相当于外存的缓冲区）
		for(size_t idx = 0; idx != _dict.size(); ++idx)
		{
			ofs << _dict[idx]._word << " " << _dict[idx]._frequency << endl;	
		}

		ofs.close();
	}
private:
	vector<Record> _dict;
};

int main(void)
{
	Dictionary dic; 

	time_t beg = ::time(NULL);
	dic.read("The_Holy_Bible.txt");	
	time_t end = ::time(NULL);
	cout << "----------> read time = " << end - beg << end;

	dic.store("dic.txt");
}
