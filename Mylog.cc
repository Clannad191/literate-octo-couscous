 ///
 /// @file    Mylogger.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-13 18:45:34
 ///
 
#include "Mylog.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using namespace log4cpp;


class Mylog
{
public:
	//警告
	void warn(const char * msg)
	{
		_myCat.warn(msg);
	}

	//void error(const char * msg);
	//void debug(const char * msg);
	//void info(const char * msg);

	//单例模式
	static Mylog * getInstance()
	{
		if(_log == nullptr){
			_log = new Mylog();
		}
		return _log;
	}

private:
	/*构造函数*/
	Mylog()
	: _myCat(Category::getRoot().getInstance("myCat"))
	, _patternLayout1(new PatternLayout())
	, _patternLayout2(new PatternLayout())
	, _ostreamAppender(new OstreamAppender("console", &cout))
	, _rollingFileAppender(new RollingFileAppender(
				"rollingFileAppender",
				"log4cpp.log",
				5 * 1024,
				3))
	{
		//控制日志输出格式
		std::string format = "%d %c [%p] %m";
		std::string line;
		_patternLayout1->setConversionPattern(format
						+ " File:" + __FILE__
						+ ", Function:" + __FUNCTION__
						+ ", Line:"  
						+ "%n");	

		//_patternLayout1->setConversionPattern("%d %c [%p] %m"
		//				+ " File:" + __FILE__
		//				+ ", Function" + __FUNCTION__
		//				+ ", Line:" + __LINE__ 
		//				+ "%n");	
		
		//_patternLayout1->setConversionPattern("%d %c [%p] %m"
		//				.append(" File:")
		//				.append(__FILE__)
		//				.append(", Function").append(__FUNCTION__)
		//				.append(", Line:").append(__LINE__) 
		//				.append("%n"));	
		_patternLayout2->setConversionPattern("%d %c [%p] %m%n");	

		//将输出格式绑定到输出器上
		_ostreamAppender->setLayout(_patternLayout1);
		_rollingFileAppender->setLayout(_patternLayout2);

		//将输出器绑定到日志记录器上，并设置日志权限
		_myCat.addAppender(_ostreamAppender);
		_myCat.addAppender(_rollingFileAppender);
		_myCat.setPriority(Priority::DEBUG);
	}

	/*析构函数*/
	~Mylog()
	{
		Category::shutdown();
	}

private:
	Category & _myCat; //日志记录器	
	PatternLayout * _patternLayout1; //日志输出格式
	PatternLayout * _patternLayout2;
	OstreamAppender * _ostreamAppender; //日志输出目的地
	RollingFileAppender * _rollingFileAppender;
	static Mylog * _log;

};//end of class Mylogger
 

//静态数据成员的定义：
Mylog * Mylog::_log = nullptr;


//int main(void)
//{
//	Mylog * mylog = Mylog::getInstance();
//	mylog->warn("111");
//}
