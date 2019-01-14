#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

// C风格的字符串
void test0()
{
	char str1[] = "hello";
	char str2[] = "world";

	int len1 = sizeof(str1);
	int len2 = strlen(str2);

	str2[0] = 'W';

	cout << "str1's = " << len1 << endl;
	cout << "str2's = " << len2 << endl;

	char * pstr1 = (char *)malloc(len1 + len2 - 1);
	memset(pstr1, 0, len1 + len2 - 1);
	strcpy(pstr1, str1);
	strcat(pstr1, str2);
	printf("pstr1 = %s\n", pstr1);

	const char * pstr2 = "hello, world";// 默认都是常量指针，不加有warning
	// *pstr2 = 'H';//error

	free(pstr1);
}

// C++风格的字符串
void test1()
{
	std::string s1 = "hello";//相当于 C风格字符串 ---> C++风格字符串
	std::string s2 = "world";

	std::string s3 = s1 + s2;

	cout << "s1 = " << s1 << endl
		<< "s2 = " << s2 << endl
		<< "s1 + s2 = " << s3 << endl;

	std::string s4 = "helloworld";

	cout << "s3's address = " << &s3 << endl;
	cout << "s4's address = " << &s4 << endl;

	const char * s5 = s3.c_str();//C++风格字符串 ---> C风格字符串
	printf("s5 = %s\n", s5);
}

void test2()
{
	std::string s1 = "hello";
	std::string s2 = "world";

	std::string s3 = s1 + s2;

	// 求字符串长度
	size_t len1 = s1.size();
	size_t len2 = s2.length();
	cout << "s1's length = " << len1 << endl
		<< "s2's lenght = " << len2 << endl;

	// 遍历 std::string 中的元素
	for(size_t idx = 0; idx != s3.size(); ++idx)
	{
		cout << s3[idx] << endl;
	}

	// 追加内容
	std::string s4 = s1 + ",wuhan";
	std::string s5 = s2 + 'H';
	cout << "s4 = " << s4 << endl
		<< "s5 = " << s5 << endl;
	s5.append(",nihao,China");
	cout << "s4 = " << s4 << endl
		<< "s5 = " << s5 << endl;

	// 查看子串
	size_t pos = s4.find("wuhan");
	cout << "pos = " << pos << endl;

	// 截取子串
	std::string s6 = s5.substr(pos, 10);
	cout << "s6 = " << s6 << endl;
}

int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
