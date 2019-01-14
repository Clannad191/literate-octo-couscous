 ///
 /// @file    Mylogger.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-13 18:45:34
 ///
 
#include "Mylogger.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using namespace wd;


int main(void)
{
	Mylogger * mylog = Mylogger::getInstance();
	mylog->warn("111");

	Mylogger::getInstance()->warn("this is a warn");
	Mylogger::getInstance()->error("this is an error");
	Mylogger::getInstance()->info("this is an info");
	Mylogger::getInstance()->debug("this is a debug");
	cout << "Priority::WARN = " << Mylogger::Priority::WARN << endl << endl;

	cout << "=====================================" << endl;

	Mylogger::getInstance()->setPriority(Mylogger::Priority::INFO);


	Mylogger::getInstance()->warn("this is a warn");
	Mylogger::getInstance()->error("this is an error");
	Mylogger::getInstance()->info("this is an info");
	Mylogger::getInstance()->debug("this is a debug");
	cout << "Priority::WARN = " << Mylogger::Priority::WARN << endl << endl;

	cout << "=====================================" << endl;

	//Mylogger::getInstance()->error(prefix("this is an error"));

	LogError("this is an error");
	LogWarn("this is an warn");
	LogInfo("this is an info");
	LogDebug("this is an debug");


	cout << "=====================================" << endl;

	Mylogger::destory();
}
