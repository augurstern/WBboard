#ifndef WBCFFADAPTOR_GLOBAL_H
#define WBCFFADAPTOR_GLOBAL_H       //防止头文件被重复包含，避免出现重复定义的错误。

#include <QtCore/qglobal.h>        //这里引入了 Qt 的全局定义文件，该文件里有像Q_DECL_EXPORT和
                                   // Q_DECL_IMPORT这样的重要宏定义。

#if defined(WBCFFADAPTOR_LIBRARY)
#  define WBCFFADAPTORSHARED_EXPORT Q_DECL_EXPORT //当我们在编译共享库项目时，需要定义WBCFFADAPTOR_LIBRARY这个宏。
// 此时，WBCFFADAPTORSHARED_EXPORT会被定义为Q_DECL_EXPORT，其作用是将类或者函数导出到共享库中。

#else
#  define WBCFFADAPTORSHARED_EXPORT Q_DECL_IMPORT//而在使用这个共享库的应用程序里，不会定义WBCFFADAPTOR_LIBRARY宏。
// 这样一来，WBCFFADAPTORSHARED_EXPORT就会被定义为Q_DECL_IMPORT，它的任务是从共享库中导入类或者函数。
#endif

#endif // WBCFFADAPTOR_GLOBAL_H

// //这段代码的作用是：

// 让库开发者可以用WBCFFADAPTORSHARED_EXPORT标记哪些类 / 函数可以被外部使用
// 自动处理库开发和使用时的符号导出 / 导入差异
// 确保跨平台兼容性（Windows/Linux/macOS）

// 这种模式在所有 Qt 共享库开发中都会用到，是一种标准做法