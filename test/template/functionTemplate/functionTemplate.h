 ///
 /// @file    functionTemplate.cc
 /// @author  Clannad191(508066373@qq.com)
 /// @date    2019-01-18 19:04:30
 ///
 
#ifndef __WD_FUNTEMP_H_
#define __WD_FUNTEMP_H_

/* 根据函数模板，通过参数推导，得到具体的模板函数的过程，称为："实例化" */
template <class T>
T add(T x, T y);

//函数模板和函数模板也可以重载
template <class T>
T add(T x, T y, T z);

#include "functionTemplate.tcc"
/*想要把带模板的c++文件分为---头文件 + 实现文件，就要在h文件里include实现文件*/
/*即：把模板的全部内容都加载到头文件中*/

#endif
