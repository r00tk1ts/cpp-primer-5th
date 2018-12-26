## 6.1

> 实参和形参的区别是什么？

 形参在函数参数列表声明，它们由函数调用处传递的实参初始化。实参就是函数调用时传递过去的参数对象。

## 6.2

> 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
>
> (a)
>
> ```cpp
> int f(){
>     string s;
>   	// ...
>   	return s;
> }
> ```
>
> (b)`f2(int i){ /* ... */ }`
>
> (c)`int calc(int v1, int v1)/* ... */ }`
>
> (d)`double square(double x) return x * x;`

(a):

```cpp
int f(){
    int s;
  	// ...
  	return s;
}
```

(b):`void f2(int i){ /* ... */ }`

(c):`int calc(int v1, int v2){ /* ... */ }`

(d):`double square(double x){ return x * x; }`

## 6.3

编写你自己的fact函数，上机检查是否正确。

```cpp
#include <iostream>

int fact(int i)
{
    return i > 1 ? i * fact(i-1) : 1;
}
```

## 6.4

> 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

[ex6_4.cpp](ex6_4.cpp)

## 6.5

> 编写一个函数输出其实参的绝对值。

```cpp
void abs(int v)
{
    if(v < 0)
      	std::cout << -v << std::endl;
  	else
      	std::cout << v << std::endl;
}	
```

## 6.6

> 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。

形参是实参的拷贝，由传递的实参初始化，生命周期在整个函数体内。局部变量仅在函数体内维持生命周期，局部静态变量则是伪全局的，但仅可在函数体内访问。

```cpp
int func(int s)
{
    static int count = 0;
  	int m = 20;
  	count += s * m;
  	return count;
}
```

## 6.7

> 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

```cpp
int func()
{
    static int cnt = 0;
  	return cnt++;
}
```

## 6.8

> 编写一个名为Chapter6.h的头文件，令其包含6.1节练习中的函数声明。

[Chapter6.h](Chapter6.h)

## 6.9

> 编写你自己的fact.cc和factMain.cc，这两个文件都应该包含上一小节的练习中编写的Chapter6.h头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

[fact.cc](fact.cc)|[factMain.cc](factMain.cc)

## 6.10

> 编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。

[ex6_10.cpp](ex6_10.cpp)

## 6.11

> 编写并验证你自己的reset函数，使其作用于引用类型的参数。

[ex6_11.cpp](ex6_11.cpp)

## 6.12

> 改写6.2.1节中练习6.10的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？

[ex6_12.cpp](ex6_12.cpp)

传引用更易用，语法简洁，一目了然。

## 6.13

> 假设T是某种类型的名字，说明以下两个函数声明的区别：一个是`void f(T)`，另一个是`void f(T&)`。

前者是值传递，后者是引用传递（左值引用）。

## 6.14

> 举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

略。

## 6.15

> 说明find_char函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？

s是引用是因为值传递效率低、而之所以是常量引用是因为不允许find_char去改写s本体。occurs是普通引用是因为我们要在函数体内改写它的值。c是基础类型，值传递效率更高。s如果普通引用，则存在find_char会修改s的隐患，occurs是const引用则会导致编译报错，常量引用不允许被修改。

## 6.16

> 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
>
> `bool is_empty(string& s){ return s.empty(); }`

局限性在于不能传递const string，但这个函数本身却不依赖于参数s的非const性。

改为`bool is_empty(const string& s){ return s.empty(); }`

## 6.17

> 编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全都改成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

[ex6_17.cpp](ex6_17.cpp)

不同，前者是const string&，而后者是string&。

因为前者无需修改参数，后者却需要对参数进行修改，因而不能应用于const string。

## 6.18

> 为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
>
> (a)名为compare的函数，返回布尔值，两个参数都是matrix类的引用。
>
> (b)名为change_val的函数，返回`vector<int>`的迭代器，有两个参数：一个是int，另一个是`vector<int>`的迭代器。

```cpp
bool compare(matrix &m1, matrix &m2);
vector<int>::iterator change_val(int i, vector<int>::iterator iter);
```

## 6.19

> 假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
>
> ```cpp
> double calc(double);
> int count(const string &, char);
> int sum(vector<int>::iterator, vector<int>::iterator, int);
> vector<int> vec(10);
> ```
>
> (a)`calc(23.4, 55.1);`(b)`count("abcda", 'a');`
>
> (c)`calc(66);`(d)`sum(vec.begin(), vec.end(), 3.8);`

(a)不合法，参数数量不匹配。

(b)合法

(c)合法

(d)合法

## 6.20

> 引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

尽可能的使用const引用，如果在可以设为const引用时设定了非const引用，那么会导致函数的局限性，增加函数修改参数的隐患。

## 6.21

> 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

```cpp
int compare(const int a, const int *p)
{
    return (a >= *p) ? a : *p;
}
```

## 6.22

> 编写一个函数，令其交换两个int指针

```cpp
void swap(int *&p1, int *&p2)
{
    int *p = p1;
  	p1 = p2;
  	p2 = p;
}
```

## 6.23

> 参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j：
>
> `int i = 0, j[2] = {0, 1};`

略

## 6.24

> 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
>
> ```cpp
> void print(const int ia[10])
> {
>     for(size_t i = 0; i != 10; ++i)
>       	cout << ia[i] << endl;
> }
> ```

打印const int[10]数组的每个成员。

但这个函数实际上这样写是有问题的，因为C++中数组类型的值传递会退化(decay)成指向首元素的元素类型指针类型，实际上传递的是const int*。因此，对print的传参，实际上传递`int ia[5]`, `int ia[255]`都是可以的，大于10还好说，只是不鞥呢完整遍历打印，如果维度参数小于10，那么就会导致函数内的数组越界。

可以通过传引用的方式解决，数组类型传引用，那么数组不会退化成指针。

```cpp
void print(const int (&ia)[10])
{
    for(size_t i = 0; i != 10; ++i)
      	cout << ia[i] << endl;
}
```

另一个有此退化机制的是函数对象。

## 6.25

> 编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。

```cpp
int main(int argc, char **argv)
{
    std::string str;
  	for(int i=0;i<argc;i++)
    {
        str += std::string(argv[i]) + " ";
    }
  	std::cout << str << std::endl;
  	return 0;
}
```

## 6.26

> 编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参的内容。

```cpp
int main(int argc, char **argv)
{
    std::string str;
  	for(int i=1;i<argc;i++)	//skip the name of program
    {
        str += std::string(argv[i]) + " ";
    }
  	std::cout << str << std::endl;
  	return 0;
}
```

## 6.27

> 编写一个函数，它的参数是`initializer_list<int>`类型的对象，函数的功能是计算列表中所有元素的和。

[ex6_27.cpp](ex6_27.cpp)

## 6.28

> 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？

const string&。

## 6.29

> 在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？

取决于initializer_list的元素类型。基础类型无需声明成引用类型，否则声明为引用类型更好。

## 6.30

> 编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。

略

## 6.31

> 什么情况下返回的引用无效？什么情况下返回常量的引用无效？

局部变量或常量的引用不能返回，因为离开了函数生命周期就终结了。

## 6.32

> 下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
>
> ```cpp
> int &get(int *array, int index){ return array[index]; }
> int main()
> {
>     int ia[10];
>   	for(int i=0;i!=10;++i)
>       	get(ia, i) = i;
> }
> ```

合法。对ia的每个成员赋值索引值。

## 6.33

> 编写一个递归函数，输出vector对象的内容。

略

## 6.34

> 如果factorial函数的停止条件如下所示，将发生什么情况？
>
> `if(val != 0)`

如果传递的参数是正数或0，函数可以正常工作。如果传递的是负数，循环直到栈溢出。

## 6.35

> 在调用factorial函数时，为什么我们传入的值是val-1而非val--

因为val--传递给形参的值依然是自减前的值，这会引起死循环。

## 6.36

> 编写一个函数的声明，使其返回数组的引用并且该数组包含10个string对象。不要使用尾置返回类型、decltype或者类型别名。

```cpp
string (&func())[10];
```

## 6.37

> 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？

```cpp
using strArr = string[10];
strArr& func1();

auto func2() -> string(&)[10]

string arrS[10];
decltype(arrS)& func3();
//decltype((arrS)) func3();
```

我觉着第一个最为精简。

## 6.38

> 修改arrPtr函数，使其返回数组的引用。

```cpp
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd)& arrPtr(int i)
{
    return (i % 2) ? odd ? even;
}
```

## 6.39

> 说明在下面的每组声明中第二条声明语句是何含义。如果有非法的声明，请指出来。
>
> (a)`int calc(int, int);int calc(const int, const int);`
>
> (b)`int get();double get();`
>
> (c)`int *reset(int *); double *reset(double *);`

a不合法，顶层const无法区分。

b不合法，参数相同返回值不同也无法区分。

c合法。

## 6.40

> 下面的哪个声明是错误的？为什么？
>
> (a)`int ff(int a, int b = 0, int c = 0);`
>
> (b)`char *init(int ht = 24, int wd, char bckgrnd);`

b错误，默认形参的必须放在最后。

## 6.41

> 下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
>
> `char *init(int ht, int wd = 80, char bckgrnd = ' ');`
>
> (a)`init();`(b)`init(24,10);`(c)`init(14,'*');`

a非法。

c虽然合法但与初衷不符，'*'给了wd参数而非bckgrnd。

## 6.42

> 给make_plural函数的第二个形参赋予默认实参's'，利用新版本的函数输出单词success和failure的单数和复数形式。

```cpp
using std::string;
using std::cout;
using std::endl;

string make_plural(size_t ctr, const string& word, const string& ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    cout << "singual: " << make_plural(1, "success", "es") << " "
         << make_plural(1, "failure") << endl;
    cout << "plural : " << make_plural(2, "success", "es") << " "
         << make_plural(2, "failure") << endl;

    return 0;
}
```

## 6.43

> 你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
>
> (a)`inline bool eq(const BigInt&, const BigInt&) {...}`
>
> (b)`void putValues(int *arr, int size);`

a和b都在头文件，因为a是内联函数，b是函数声明。

## 6.44

> 将6.2.2节的isShorter函数改写成内联函数。

```cpp
inline bool is_shorter(const std::string &lft, const std::string &rht)
{
    return lft.size() < rht.size();
}
```

## 6.45

> 回顾在前面的练习中你编写的那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因。

略

## 6.46

> 能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constexpr函数；如果不能，说明原因。

不能，因为`std::string::size()`不是constexpr函数。

## 6.47

> 改写6.3.2节练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个重新。

略

## 6.48

> 说明下面这个循环的含义，它对assert的使用合理吗？
>
> ```cpp
> string s;
> while(cin >> s && s != sought) {}
> assert(cin);
> ```

输入字符串，直到与sought相同。

assert的用法不合理，因为这里无论如何assert都是true，毫无意义。

## 6.49

> 什么是候选函数？什么是可行函数？

candidate function:

> Set of functions that are considered when resolving a function call. (all the functions
> with the name used in the call for which a declaration is in scope at the time of the call.)

viable function:

> Subset of the candidate functions that could match a given call.
> It have the same number of parameters as arguments to the call,
> and each argument type can be converted to the corresponding parameter type.

简单来说，候选函数就是调用时可找到的所有名称一致的函数，可行函数则是候选函数的子集，是挑出来的那些可以完成参数匹配的候选函数。

## 6.50

> 已知有第217页对函数f的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
>
> (a)`f(2.56, 42)`(b)`f(42)`(c)`f(42, 0)`(d)`f(2.56, 3.14)`

a不合法，`f(int, int)`和`f(double, double=3.14)`匹配度相同，无法裁决。

b合法，匹配`void f(int);`

c合法，匹配`void f(int, int);`

d合法，匹配`void f(double, double=3.14);`

## 6.51

> 编写函数f的4个版本，令其各输出一条可以区分的消息。验证上一个练习的答案，如果你回答错了，反复研究本节的内容直到你弄清自己错在何处。

[ex6_51.cpp](ex6_51.cpp)

Clang:

```
ex6_51.cpp:27:5: error: call to 'f' is ambiguous
    f(2.56, 42);
    ^
ex6_51.cpp:15:6: note: candidate function
void f(int, int)
     ^
ex6_51.cpp:20:6: note: candidate function
void f(double, double)
     ^
1 error generated.
```

## 6.52

> 已知有如下声明，
>
> `void manip(int, int);`
>
> `double dobj;`
>
> 请指出下列调用中每个类型转换的等级。
>
> (a)`manip('a','z');`(b)`manip(55.4, dobj);`

a转换是等级3类型提升，从char到int。

b转换是等级4算术类型转换，从double到int。

## 6.53

> 说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。
>
> (a)`int calc(int&, int&); int calc(const int&, const int&);`
>
> (b)`int calc(char*, char*); int calc(const char*, const char*);`
>
> (c)`int calc(char*, char*);int calc(char* const, char* const);`

a和b都合法，都是底层const，第二条语句提供了const引用或指向const类型的指针的调用支持。

c是不合法的，因为顶层const无法区分。

## 6.54

> 编写函数的声明，令其接受两个int形参并且返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。

```cpp
int func(int a, int b);
vector<int(*)(int, int)> v;

// 花式炫技
using pFunc1 = decltype(func)*;
vector<pFunc1> v1;

typedef decltype(func) *pFunc2;
vector<pFunc2> v2;

using pFunc3 = int(*)(int, int);
vector<pFunc3> v3;

using pFunc4 = int(int , int);
vector<pFunc4*> v4;

typedef int(*pFunc5)(int, int);
vector<pFunc5> v5;

using pFunc6 = decltype(func);
vector<pFunc6*> v6;
```

## 6.55

> 编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。

```cpp
int add(int a, int b){return a + b;}
int sub(int a, int b){return a - b;}
int mul(int a, int b){return a * b;}
int div(int a, int b){return b != 0 ? a / b : 0;}
```

## 6.56

> 调用上述vector对象中的每个元素并输出其结果。

[ex6_56.cpp](ex6_56.cpp)