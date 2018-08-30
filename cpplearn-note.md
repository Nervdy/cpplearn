# 

## 定义引用

```cpp
int i;
int &x = i;
```

## 定义指针

```cpp
int i;
int *x = &i;
```

## & || * 多重含义

```cpp
int i = 42;
int &r = i;   // 引用
int *p;       // 指针
p = &i;       // 取地址
*p = i;       // 解引用
int &r2 = *p;
```
> 在声明语句中，&和*用于组成符合类型；在表达式中，它们的角色又转变成运算符。

## 空指针

```cpp
int *p1 = nullptr;    // 等价于 int *p1 = 0;
int *p2 = 0;          // 直接将p2初始化未字面常量0
// 需要首先#include cstdlib
int *p3 = NULL;       // 等价于 int *p3 = 0;
```

> **nullptr** : C++11引入的关键字，如果编译器没有支持c++11则编译时会报未声明错误，可通过添加 ```-std=c++0x``` 编译选项使编译器支持c++11  
> **NULL** : 预处理变量，定义于头文件 ```cstdlib``` 中，值为0。在新标准下，现在的c++程序最好使用 **nullptr** ，同时尽量避免使用 **NULL** 

```cpp
int zero = 0;
p1 = zero;      // 错误：不能把int变量直接赋值给指针
```
> 把 **int** 变量直接赋给指针是错误的操作，即使 **int** 变量的值恰好等于0也不行。

## 指针赋值
```cpp
int i = 42;
int *pi = 0;    // pi被初始化，但没有指向任何对象
int *pi2 = &i;  // pi2被初始化，存有i的地址
int *pi3;       // 如果pi3定义于块内，则pi3的值是无法确定的

pi3 = pi2;      // pi3和pi2指向同一个对象i
pi2 = 0;        // 现在pi2不指向任何对象了

// 区分指针赋值和指针所指对象赋值
pi = &ival;     // pi的值被改变，现在pi指向ival
*pi = 0;        // ival的值被改变，指针pi并没有改变
```

## 其他指针操作

```cpp
int ival = 1024;
int *pi = 0;       // pi合法，是一个空指针
int *pi2 = &ival;  // pi2是一个合法的指针，存放着ival的地址
if (pi)            // pi的值是0，因此条件的值是false
    // ...
if (pi2)           // pi2指向ival，因此它的值不是0，条件的值是true
    // ...
```
> 任何非0指针对应的条件值都是true。

## 指针和 const

```cpp
const double pi = 3.14;     // pi是个常量，它的值不能改变
double *ptr = &pi;          // 错误：ptr是一个普通指针
const double *cptr = &pi;   // 正确：cptr可以指向一个双精度常量
*cptr = 42;                 // 错误：不能给*cptr赋值
```

> 允许令一个指向常量的指针指向一个非常量对象

```cpp
double dval = 3.14;     // dval是一个双精度浮点数，它的值可以改变
cptr = &dval;           // 正确：但是不能通过 cptr 改变 dval 的值
```
- **const** 指针
```cpp
int errNumb = 0;
int *const curErr = &errNumb;   // curErr将一直指向 errNumb
const double pi = 3.14159;
const double *const pip = &pi;  // pip是一个指向常量对象的常量指针
```
> **curErr** 是一个常量指针，指向 **int** 型非常量对象  
> **pip** 是一个常量指针，指向 **double** 型常量对象  
> 指针本身是一个常量表示指针对象的地址值不能被改变，并不意味着不能通过指针修改其所指对象的值，能否这样做完全依赖于所指对象的类型  
> ```cpp
> *curErr = 2.72;   // success
> *pip = 2.72;      // error
> ```

## 顶层 const

```cpp
int i = 0;
int *const p1 = &i;       // 不能改变p1的值，top-level
const int ci = 42;        // 不能改变ci的值，top-level
const int *p2 = &ci;      // 允许改变p2的值，low-level
const int *const p3 = p2; // 靠右的const是top-level const，靠左的是low-level const
const int &r = ci;        // 用于声明引用的const都是low-level const
```

## constexpr 变量 - 59

```cpp
constexpr int mf = 20;        // 20是常量表达式
constexpr int limit = mf + 1; // mf+1是常量表达式
constexpr int sz = size();    // 只有当size是一个constexpr函数时才是一条正确的声明语句
```

> c++11新标准规定，允许将变量声明为 **constexpr** 类型以便由编译器来验证变量的值是否是一个常量表达式。声明为 **constexpr** 的变量一定是一个常量，而且必须用常量表达式初始化。
>
> 尽管不能使用普通函数作为 **constexpr** 变量的初始值，但是（cpp primer page-214）新标准允许定义一种特殊的 **constexpr** 函数。这种函数应该足够简单以使得编译时就可以计算其结果，这样就能用 **constexpr** 函数去初始化 **constexpr** 变量了。

```cpp
constexpr int *np = nullptr;  // np是一个指向整数的常量指针，其值为空
int j = 0;
constexpr int i = 42;          // i的类型是整型常量
// i和j都必须定义在函数体之外
constexpr const int *p = &i;  // p是常量指针，指向整型常量i
constexpr int *p1 = &j;       // p1是常量指针，指向整数j
```

## 类型别名 - 60

> 有两种方法可用于类型别名。传统的方法是使用关键字 **typedef**
```cpp
typedef double wages;   // wages是double的同义词
typedef wages base, *p; // base是double的同义词，p是double*的同义词

base i = 1.23;          // double i = 1.23
p j = &i;               // double *j = &i;
```

> 新标准规定了一种新的方法，使用 **别名声明**（alias declaration）来定义类型的别名

```cpp
using SI = Sales_item;    // SI是Sales_item的同义词
```