 ///
 /// @file    Mylogger.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-13 18:45:34
 ///
 
#include "Mylogger.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using namespace wd;


//警告
void Mylogger::warn(const char * msg)
{
	_myCat.warn(msg);
}

void Mylogger::error(const char * msg)
{
	_myCat.error(msg);
}

void Mylogger::debug(const char * msg)
{
	_myCat.debug(msg);
}

void Mylogger::info(const char * msg)
{
	_myCat.info(msg);
}


/*自定义设置权限函数*/
void Mylogger::setPriority(Priority p)
{
	switch(p){
		case WARN:
			_myCat.setPriority(log4cpp::Priority::WARN);
			break;
		case ERROR:
			_myCat.setPriority(log4cpp::Priority::ERROR);
			break;
		case INFO:
			_myCat.setPriority(log4cpp::Priority::INFO);
			break;
		case DEBUG:
			_myCat.setPriority(log4cpp::Priority::DEBUG);
			break;
	}
}

/*单例模式*/
Mylogger * Mylogger::getInstance()
{
	if(_pInstance == nullptr){
		_pInstance = new Mylogger();
	}
	return _pInstance;
}

/*释放内存*/
void Mylogger::destory()
{
	if(_pInstance){
		delete _pInstance;
	}
}

/*构造函数*/
Mylogger::Mylogger()
: _myCat(log4cpp::Category::getRoot().getInstance("myCat"))
{
	//只在该函数内使用命名空间，限定范围以防冲突
	using namespace log4cpp;

	PatternLayout * patternLayout1 = new PatternLayout();
	PatternLayout * patternLayout2 = new PatternLayout();

	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout);
	RollingFileAppender * rollingFileAppender = new RollingFileAppender(
			"rollingFileAppender",
			"log4cpp.log",
			5 * 1024,
			3);
	//patternLayout1->setConversionPattern("%d %c [%p] %m%n");	
	//patternLayout2->setConversionPattern("%d %c [%p] %m%n");	
	

	//控制日志输出格式
	patternLayout1->setConversionPattern("%d %c [%p] %m%n");	
	patternLayout2->setConversionPattern("%d %c [%p] %m%n");	

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

	//将输出格式绑定到输出器上
	ostreamAppender->setLayout(patternLayout1);
	rollingFileAppender->setLayout(patternLayout2);


	//将输出器绑定到日志记录器上，并设置日志权限
	_myCat.addAppender(ostreamAppender);
	_myCat.addAppender(rollingFileAppender);
	_myCat.setPriority(Priority::DEBUG);

	cout << "Mylogger()" << endl;
}

/*析构函数*/
Mylogger::~Mylogger()
{
	log4cpp::Category::shutdown();
	cout << "~Mylogger()" << endl;
}


//静态数据成员的定义，不能放在头文件里，否则会造成重复定义error
Mylogger * Mylogger::_pInstance = nullptr;


