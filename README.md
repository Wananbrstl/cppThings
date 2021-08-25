# cppThing说明
运行环境:   ubuntu20.4

采用编译器: gcc

编辑器:     vim
# cpp 如何打印彩色问题
通过使用如下代码:
```
std::cout << "\033[ ; m ";
printf("\033[ ; m ");
字背景颜色范围: 40--49 字颜色: 30--39
40: 黑 30: 黑
41: 红 31: 红
42: 绿 32: 绿
43: 黄 33: 黄
44: 蓝 34: 蓝
45: 紫 35: 紫
46: 深绿 36: 深绿
47: 白色 37: 白色
ANSI控制码:
QUOTE:
\033[0m 关闭所有属性
\033[1m 设置高亮度
\03[4m 下划线
\033[5m 闪烁
\033[7m 反显
\033[8m 消隐
\033[30m -- \033[37m 设置前景色
\033[40m -- \033[47m 设置背景色
\033[nA 光标上移n行
\03[nB 光标下移n行
\033[nC 光标右移n行
\033[nD 光标左移n行
\033[y;xH设置光标位置
\033[2J 清屏
\033[K 清除从光标到行尾的内容
\033[s 保存光标位置
\033[u 恢复光标位置
\033[?25l 隐藏光标
\33[?25h 显示光标
```
# 指针相关
## 关于const和指针
规则： 
- 先看左边， 如果左边有值， 则修饰的是左边
- 如果没有， 则是右边
**int const * p ** const修饰的是int，则p指向的地址上的数值无法改变
**int  *const p ** const修饰的是*，  则p指向的地址无法改变
## 内存管理
CPP存储区域划分：
- 栈区(First In Last Out)
- 队列(First in First out)
``` c++ 
int a = 0;
int* p1 = NULL;

```
- 分为 常量区 和 变量区
- 存储机制是栈的机制， 首先进栈，地址越高(stack)
- 程序员 管理的是堆区 堆区是队列的机制 先进队列 地址低(heap)
    - new 和 delete
- 函数外的变量是 全局变量(GVAR)
- 函数外 没有初始化 全局未初始化区域(bss)
- static 区域和 全局区域 比较雷同(GVAR)
- 不是 变量的 指令 代码区(TEXT)

堆HEAP(队列的机制)
- 动态分配内存
    - 存在不确定性： 耗时/分配失败/隐式分配
    - 自由的， 但是也有坏处(比如 内存泄漏)
- 三个操作
    - 分配内存快(c++)
    - 释放内存块(c++)
    - 垃圾收集机制


资源管理方案 - RAII

## 智能指针
危险的行为： 空指针 野指针 
两个解决方案: 
- 智能指针
    - auto_ptr(废弃) c++17废除
        - 与对象关联度比较高，所有权转移：很多个指针指向一个的时候， 原本的ptr就失效了, 交给新对象，然后将原对象指针为nullptr
        - 存在安全隐患
        - `auto_ptr<int> pl(new int(10))`
        - 尽量使用nullptr
    - unique_ptr 
        - 专属所有权， 所以unique_ptr管理内存，只能有一个对象持有。 不能复制和赋值
        - 移动语义，unique_ptr不能拷贝， 通过std::move()进行控制所有权的移动 
        - 范围 以 {} 确定
    - shared_ptr
        - 共享指针， 通过计数进行共享和释放，当有一个ptr指向一个对象，则+1，多一个+1
        - 解决了对象所有权的问题， 但作出了开销！！
        - 问题：  循环引用
            - 循环引用会导致heap空间中无法正常回收，造成内存泄漏， A 和 B 双向引用。
    - weak_ptr
        - 观察者工作模式，weak_ptr和shared_ptr共同工作   
        - A 要使用 B， A 有一个指针指向B， 两者不是对等的关系，A的行为可以通知B，B的作用强于A。
        - 不影响shared_ptr的计数!!!!!
    - move语法
        - ...
- 引用
是一种特殊的指针，不允许修改的指针

使用指针的坑：
- 空指针
- 野指针
- 不知不觉修改了指针的数值，却继续使用

使用引用：
- 没有空引用
- 必须初始化
- 一个引用永远指向它初始化的那个对象

有了指针WHY引用&
- 引用--运算符重载
有了引用WHY指针
- 兼容问题

效率问题
- 对于内置基础数据类型而言，在函数中传递中pass by value 更高效
- 对于OOP面向对象中自定义的类型而言，在函数中pass by reference to const 更高效



# GCC编译过程
1. 预处理
在该阶段进行文件的预先处理，包括头文件和宏等等

# CONST
const对象只能调用const函数
普通对象既可以调用const也可以调普通
