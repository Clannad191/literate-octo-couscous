 ///
 /// @file    testString.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-11 09:14:30
 ///
 
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	string line;

	while(getline(cin, line))
	{
		cout << line << endl;
	}
	return 0;
}
