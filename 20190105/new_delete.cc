#include <malloc.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

// C开辟动态内存的方式
int test0(void)
{
	// 开辟一个变量
	int * pInt = (int*)malloc(sizeof(int));
	memset(pInt, 0, sizeof(int));

	*pInt = 10;
	cout << "pInt = " << pInt << endl;
	cout << "*pInt = " << *pInt << endl;
	cout << "&pInt = " << &pInt << endl;

	// 开辟数组空间
	int * pArray = (int*)malloc(sizeof(int) * 10);
	memset(pArray, 0, sizeof(int) * 10);
	pArray[0] = 1;
	cout << "pArray[0] = " << pArray[0] << endl;	


	free(pInt);
	free(pArray);
	return 0;
}

void test1()
{
	int * pInt = new int(10); // 开辟空间的同时，进行初始化
	cout << "*pInt = " << *pInt << endl;
	cout << "&pInt = " << &pInt << endl;
	cout << "pInt = " << pInt << endl;

	delete pInt;

	// 开辟数组空间
	int * pArray = new int[10]();
	pArray[0] = 3;
	cout << "pArray[0] = " << pArray[0] << endl;

	delete pArray;
}

int main(void)
{
	test0();
	test1();
}
