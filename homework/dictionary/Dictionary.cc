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



class Dictionary
{
public:
	Dictionary(int i = 13000)
	{
		//预先开辟空间
		_words.reserve(i);		
		_times.reserve(i);
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
			cout << "fstream open file " << filename << " error!" << endl;	
			return;
		}

		string word;
		while(ifs >> word, !ifs.eof()){
			size_t idx;
			for(idx = 0; idx != _words.size(); ++idx)
			{
				if(_words[idx] == word){
					++_times[idx];
					break;
				}		
			}

			if(idx == _words.size()){ //说明没有相同的，是一个新单词
				_words.push_back(word);	
				_times.push_back(1);
			}
		}


		ifs.close();
	}

	/*
	 *将内存中的数据（存在对象的数据成员中），输出到指定文件中
	 */
	void store(const string & filename)
	{
		ofstream ofs(filename);	
		if(!ofs){
			cout << "fstream open file " << filename << " error!" << endl;	
			return;
		}

		//将vector容器中的数据一组一组输入到输出流中（输出流相当于外存的缓冲区）
		for(size_t idx = 0; idx != _words.size(); ++idx)
		{
			ofs << _words[idx] << " " << _times[idx] << endl;	
		}

		ofs.close();
	}
private:
	vector<string> _words;
	vector<int> _times;
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
