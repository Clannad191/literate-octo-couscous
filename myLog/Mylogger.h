 ///
 /// @file    Mylogger.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-13 18:45:34
 ///
 
#ifndef __WD_MYLOGGER_H
#define __WD_MYLOGGER_H
//头文件别忘了预编译

#include <log4cpp/Category.hh>
#include <string>
using std::string;

//自定义一个命名空间，把Mylogger类放在命名空间里
namespace wd
{

//自定义宏，实现日志信息的格式化（利用C语言已定义好的宏）
//		定义在头文件里，否则每次使用都要定义宏
//不能定义为函数，调用函数，宏获取的是执行被调函数时的文件名、函数名、行号
#define prefix(msg) string("[")\
					.append(__FILE__).append(":")\
					.append(__FUNCTION__).append(":")\
					.append(std::to_string(__LINE__)).append("]")\
					.append(msg).c_str()

//自定义宏，简化使用，不必再每次都 Mylogger::getInstance()->...
#define LogError(msg) Mylogger::getInstance()->error(prefix(msg))
#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg));
#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg));

/*
#define prefix(msg) "%d %c [%p] "\
					+ ", File:" + __FILE__\
					+ ", Function:" + __FUNCTION__\
					+ ", Line:" + std::to_string(__LINE__)\
					+ msg
*/

class Mylogger
{
public:
	enum Priority {
		ERROR = 300, //默认从0开始
		WARN,
		INFO,
		DEBUG
	};//枚举类

	void warn(const char * msg);
	void error(const char * msg);
	void debug(const char * msg);
	void info(const char * msg);

	/*自定义设置权限方法，这样不必在实现文件以外的地方再调用log4cpp的方法来设置权限，
	 * 因此不必引入log4cpp的头文件*/
	void setPriority(Priority p);

	/*单例模式*/
	static Mylogger * getInstance();

	/*释放空间*/
	static void destory();

private:
	/*构造函数*/
	Mylogger();

	/*析构函数*/
	~Mylogger();

private:
	log4cpp::Category & _myCat; //日志记录器	
	static Mylogger * _pInstance;

};//end of class Mylogger

}//end of namespace wd
#endif
