 ///
 /// @file    log4cpp1.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-13 10:49:40
 ///
 
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;

void test0()
{
	//控制日志输出格式
	PatternLayout * patternLayout = new PatternLayout();
	patternLayout->setConversionPattern("%d %c [%p] %m%n");

	//制定日志输出地址
	//使用标准输出流，输出到终端
	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout);
	ostreamAppender->setLayout(patternLayout);


	//日志记录器
	Category & root = Category::getRoot();
	root.setAppender(ostreamAppender);
	root.setPriority(Priority::DEBUG);


	//执行记录日志的操作
	root.emerg("this is an emerg message");
	root.fatal("this is a fatal message");
	root.alert("this is an alert message");
	root.error("this is an info message");
	root.crit("this is a crit message");
	root.debug("this is a debug message");
	
	//回收内存
	Category::shutdown();
}

void test1()
{

	//控制日志输出格式
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2->setConversionPattern("%d %c [%p] %m%n");

	//设置日志输出目的地
	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout); 
	ostreamAppender->setLayout(patternLayout1);
	
	FileAppender * fileAppender = new FileAppender("fileAppender", "wd.log");
	fileAppender->setLayout(patternLayout2);
	
	//日志记录器
	Category & myCat = Category::getRoot().getInstance("myCat");
	myCat.addAppender(ostreamAppender);
	myCat.addAppender(fileAppender);
	myCat.setPriority(Priority::ERROR);

	myCat.emerg("this is an emerg message");
	myCat.fatal("this is a fatal message");
	myCat.alert("this is an alert message");
	myCat.error("this is an info message");
	myCat.crit("this is a crit message");
	myCat.debug("this is a debug message");
	myCat.notice("this is a notice message");
	myCat.warn("this is a warn message");

	//内存回收
	Category::shutdown();

}

void test2()
{

	//控制日志输出格式
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2->setConversionPattern("%d %c [%p] %m%n");

	//设置日志输出目的地
	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout);
	ostreamAppender->setLayout(patternLayout1);

	RollingFileAppender * rollingFileAppender = 
		new RollingFileAppender(
				"rollingFileAppender",
				"log4cpp1.log",
				5 * 1024,
				3
				);
	rollingFileAppender->setLayout(patternLayout2);

	//日志记录器
	Category & myCat = Category::getRoot().getInstance("myCat");
	myCat.addAppender(ostreamAppender);
	myCat.setAppender(rollingFileAppender);
	myCat.setPriority(Priority::DEBUG);

	//输出日志
	for(size_t idx = 0; idx != 100; ++idx){
		myCat.emerg("this is an emerg message");
		myCat.fatal("this is a fatal message");
		myCat.alert("this is an alert message");
		myCat.error("this is an info message");
		myCat.crit("this is a crit message");
		myCat.debug("this is a debug message");
		myCat.notice("this is a notice message");
		myCat.warn("this is a warn message");
	}
	
	//回收内存
	Category::shutdown();
}

int main(void)
{
	//test0(); 
	//test1();
	//test2();
	cout << __LINE__ << endl;
}
