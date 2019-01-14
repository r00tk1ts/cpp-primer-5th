## 14.1

> 在什么情况下重载的运算符与内置运算符有所区别？在什么情况下重载的运算符又与内置运算符一样？

不同：

重载运算符要么是类成员，要么至少有一个class或枚举类型的操作数。

重载操作符不会保证操作数的求值顺序，对&&和||的重载版本不再具有短路特性。

重载运算符可以直接被调用。

相同：

重载运算符具有与对应的内置操作符相同的优先级和结合性，操作数的数量也相同（class内部会隐藏第一个操作数，它是this）。

## 14.2

> 为Sales_data编写重载的输入、输出、加法和复合赋值运算符的声明。

[ex14_2.h](ex14_2.h)

## 14.3

> string和vector都定义了重载的==以比较各自的对象，假设svec1和svec2是存放string的vector，确定在下面的表达式中分别使用了哪个版本的==？
>
> (a)`"cobble" == "stone"`
>
> (b)`svec1[0] == svec2[0]`
>
> (c)`svec1 == svec2`
>
> (d)`svec1[0] == "stone"`

(a)都没用到，使用的是内置版本，被比较的是两个指针。

(b)string版本。

(c)vector版本。

(d)string版本，此时字符串常量隐式转换为string。

## 14.4

> 如何确定下列运算符是否应该是类的成员？
>
> (a)`%`
>
> (b)`%=`
>
> (c)`++`
>
> (d)`->`
>
> (e)`<<`
>
> (f)`&&`
>
> (g)`==`
>
> (h)`()`

(a)一般为了语义，`%`通常定义为非成员，左右操作数是对称的。

(b)一般为了语义，`%=`通常定义为成员，因为会改变左操作数。

(c)`++`通常定义为类成员，因为会改变对象状态。

(d)`->`必须定义为类成员

(e)`<<`通常定义为非成员

(f)`&&`通常定义为非成员

(g)`==`通常定义为非成员

(h)`()`必须定义为类成员。

## 14.5

> 在7.5.1节的练习7.40中，编写了下列类中某一个的框架，请问在这个类中应该定义重载的运算符吗？如果是，请写出来。
>
> (a)`Book`(b)`Date`(c)`Employee`(d)`Vehicle`(e)`Object`(f)`Tree`

以Book为例，应该重载`==`,`!=`,`<<`,`>>`。

[ex14_5.h](ex14_5.h) | [ex14_5.cpp](ex14_5.cpp)

## 14.6

> 为你的Sales_data类定义输出运算符。

[ex14_2.cpp](ex14_2.cpp)

## 14.7

> 你在13.5节的练习中曾经编写了一个String类，为它定义一个输出运算符。

[ex14_7.h](ex14_7.h) | [ex14_7.cpp](ex14_7.cpp)

## 14.8

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，为它定义一个输出运算符。

见14.5

## 14.9

> 为你的Sales_data类定义输入运算符。

[ex14_2.cpp](ex14_2.cpp)

## 14.10

> 对于Sales_data的输入运算符来说，如果给定了下面的输入将发生什么情况？
>
> (a)`0-201-99999-9 10 24.95`
>
> (b)`10 24.95 0-210-99999-9`

(a)输入格式正确，三个成员都被正确赋值。

(b)输入错误，此时BookNo是"10"，units_sold被截断是24，price是0.95，后面的被忽略。输出是`10 24 22.8 0.95`

[ex14_10.cpp](ex14_10.cpp)

## 14.11

> 下面的Sales_data输入运算符存在错误吗？如果有，请指出来。对于这个输入运算符如果仍然给定上个练习的输入将发生什么情况？
>
> ```cpp
> istream& operator>>(istream& in, Sales_data& s)
> {
>     double price;
>   	in >> s.bookNo >> s.units_sold >> price;
>   	s.revenue = s.units_sold * price;
>   	return in;
> }
> ```



没有检查输入是否合法，要判断in最后的状态。

上个例子不足以使in失效，所以不会发生什么，这个例子出得不好。

## 14.12

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，为它定义一个输入运算符并确保该运算符可以处理输入错误。

见14.5

## 14.13

> 你认为Sales_data类还应该支持哪些其他算术运算符？如果有的话，请给出它们的定义。

[ex14_13.h](ex14_13.h) | [ex14_13.cpp](ex14_13.cpp)

## 14.14

> 你觉得为什么调用operator+=来定义operator+比其他方法更有效？

可读性好，复用当然比重写一遍来得好。

## 14.15

> 你在7.5.1节的练习中曾经选择并编写了一个类，你认为它应该含有其他算术运算符吗？如果是，请实现它们；如果不是，解释原因。

对14.5的Book来说，其他算术运算符没有合适的语义，不必重载。

## 14.16

> 为你的StrBlob类、StrBlobPtr类、StrVec类和String类分别定义相等运算符和不相等运算符。

[StrBlob.h](StrBlob.h) | [StrBlob.cpp](StrBlob.cpp)

[StrVec.h](StrVec.h) | [StrVec.cpp](StrVec.cpp)

[String.h](String.h) | [String.cpp](String.cpp)

## 14.17

>你在7.5.1节的练习中曾经选择并编写了一个类，你认为它应该含有相等运算符吗？如果是，请实现它；如果不是，解释原因。

见14.5

## 14.18

> 为你的StrBlob类、StrBlobPtr类、StrVec类和String类定义关系运算符。

见14.16

## 14.19

> 你在7.5.1节的练习中曾经选择并编写了一个类，你认为它应该含有关系运算符吗？如果是，请实现它；如果不是，解释原因。

不应该，Book的关系运算符无合适的语义，不予重载。

## 14.20

> 为你的Sales_data类定义加法和复合赋值运算符。

[ex14_2.cpp](ex14_2.cpp)

## 14.21

> 编写Sales_data类的+和+=运算符，使得+执行实际的加法操作而+=调用+。相比于14.3节和14.4节对这两个运算符的定义，本题的定义有何缺点？试讨论之。

```cpp
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}
```

都构造了临时对象，效率低。

## 14.22

> 定义赋值运算符的一个新版本，使得我们能把一个表示ISBN的string赋给一个Sales_data对象。

[ex14_22.cpp](ex14_22.cpp) | [ex14_2.h](ex14_2.h)

## 14.23

> 为你的StrVec类定义一个initializer_list赋值运算符。

见14.16

## 14.24

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有拷贝赋值和移动赋值运算符吗？如果是，请实现它们。

因为有string类型数据成员，所以应该有，拷贝和移动成员就不写了。

## 14.25

> 上题的这个类还需要定义其他赋值运算符吗？如果是，请实现它们；同时说明运算对象应该是什么类型并解释原因。

见14.5

## 14.26

> 为你的StrBlob类、StrBlobPtr类、StrVec类和String类定义下标运算符。

见14.16

## 14.27

> 为你的StrBlobPtr类添加递增和递减运算符。

见14.16

## 14.28

> 为你的StrBlobPtr类添加加法和减法运算符，使其可以实现指针的算术运算。

见14.16

## 14.29

> 为什么不定义const版本的递增和递减运算符？

因为递增和递减会修改类对象成员curr，当然不能const。

## 14.30

> 为你的StrBlobPtr类和在12.1.6节练习12.22中定义的ConstStrBlobPtr类分别添加解引用运算符和箭头运算符。注意：因为ConstStrBlobPtr的数据成员指向const vector，所以ConstStrBlobPtr中的运算符必须返回常量引用。

见14.16

## 14.31

> 我们的StrBlobPtr类没有定义拷贝构造函数、赋值运算符及析构函数，为什么？

因为它的数据成员一个是基础类型`size_t`，一个是`weak_ptr<vector<string>>`，都无需特别的处理，使用默认的拷贝语义就足够了。

## 14.32

> 定义一个类令其含有指向StrBlobPtr对象的指针，为这个类定义重载的箭头运算符。

```cpp
class A
{
public:
  	std::string *operator->() const { return ptr->operator->();}
private:
  	StrBlobPtr *ptr;
}
```

## 14.33

> 一个重载的函数调用运算符应该接受几个运算对象？

0到多个。

## 14.34

> 定义一个函数对象类，令其执行if-then-else操作：该类的调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二个形参的值，如果不成功返回第三个形参的值。

```cpp
struct IfThenElse
{
  	int operator()(bool b, int i1, int i2){
      return b ? i1 : i2;
    }
};
```

## 14.35

> 编写一个类似于PrintString的类，令其从istream中读取一行输入，然后返回一个表示我们所读内容的string。如果读取失败，返回空string。

```cpp
class GetInput{
public:
  	GetInput(std::istream &i = std::cin) : is(in) { }
  	std::string operator()() const {
        std::string str;
      	std::getline(is, str);
      	return is ? str : std::string();
    }
private:
  	std::istream &is;
};
```

## 14.36

> 使用前一个练习定义的类读取标准输入，将每一行保存为vector的一个元素。

[ex14_36.cpp](ex14_36.cpp)

## 14.37

> 编写一个类令其检查两个值是否相等。使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。

[ex14_37.cpp](ex14_37.cpp)

## 14.38

> 编写一个类令其检查某个给定的string对象的长度是否与一个阈值相等。使用该对象编写程序，统计并报告在输入的文件中长度为1的单词有多少个、长度为2的单词有多少个、……、长度为10的单词又有多少个。

[ex14_38.cpp](ex14_38.cpp)

## 14.39

> 修改上一题的程序令其报告长度在1至9之间的单词有多少个、长度在10以上的单词又有多少个。

见14.38

## 14.40

>重新编写10.3.2节的biggies函数，使用函数对象类替换其中的lambda表达式。

略

## 14.41

> 你认为C++11新标准为什么要增加lambda？对于你自己来说，什么情况下会使用lambda，什么情况下会使用类？

函数不复杂且使用不频繁时会用lambda，反之则用函数对象。

## 14.42

> 使用标准库函数对象及适配器定义一条表达式，令其
>
> (a)统计大于1024的值有多少个。
>
> (b)找到第一个不等于pooh的字符串。
>
> (c)将所有的值乘以2。

(a)`std::count_if(vec.begin(), vec.end(), std::bind(std::greater<int>(),_1, 1024));`

(b)`std::find_if(vec.begin(), vec.end(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));`

(c)`std::transform(vec.begin(), vec.end(), vec.begin(), std::bind(std::multiplies<int>(), _1, 2));`

## 14.43

> 使用标准库函数对象判断一个给定的int值是否能被int容器中的所有元素整除。

[ex14_43.cpp](ex14_43.cpp)

## 14.44

> 编写一个简单的桌面计数器使其能处理二元运算。

[ex14_44.cpp](ex14_44.cpp)

## 14.45

> 编写类型转换运算符将一个Sales_data对象分别转换成string和double，你认为这些运算符的返回值应该是什么？

转string应该返回bookNo，转double应该返回avg_price()计算的值。

```cpp
class Sales_data{
    ...
public:
    explicit operator std::string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }
    ...
};
```

## 14.46

> 你认为应该为Sales_data类定义上面两种类型转换运算符吗？应该把它们声明成explicit的吗？为什么？

不应该，语义上非常差，这种类型转换具有误导作用。如果定义了，那么需要explicit，这是为了防止隐式类型转换。

## 14.47

> 说明下面这两个类型转换运算符的区别。
>
> ```cpp
> struct Integral{
>     operator const int();
>     operator int() const;
> };
> ```

前者转为const int，后者是转成int，const表示该函数本身不会修改类数据成员，传递const this指针。

## 14.48

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有向bool的类型转换运算符吗？如果是，解释原因并说明该运算符是否应该是explicit的；如果不是，也请解释原因。

Book类不需要这样的语义，无需定义。

## 14.49

> 为上一题提到的类定义一个转换目标是bool的类型转换运算符，先不用在意这么做是否应该。

见14.5

## 14.50

> 在初始化ex1和ex2的过程中，可能用到哪些类类型的转换序列呢？说明初始化是否正确并解释原因。
>
> ```cpp
> struct LongDouble{
>     LongDouble(double = 0.0);
>     operator double();
>     operator float();
> };
> LongDouble ldObj;
> int ex1 = ldObj;
> float ex2 = ldObj;
> ```

ex1会产生二义性错误，因为转成double或float匹配度相同。

ex2会转成float。

## 14.51

> 在调用calc的过程中，可能用到哪些类型转换序列呢？说明最佳可行函数是如何被选出来的。
>
> ```cpp
> void calc(int);
> void calc(LongDouble);
> double dval;
> calc(dval);	//哪个calc？
> ```

会调用`void calc(int);`。

因为自定义类型转换优先级低于内置类型转换。

优先级：

1. 严格匹配
2. const转换
3. 向上转型
4. 算术或指针类型转换
5. 类类型转换

## 14.52

> 在下面的加法表达式中分别选用了哪个operator+？列出候选函数、可行函数及为每个可行函数的实参执行的类型转换：
>
> ```cpp
> struct LongDouble{
>     ...
>     LongDouble operator+(const SmallInt&);
>     ...
> };
> 
> LongDouble operator+(LongDouble & double);
> SmallInt si;
> LongDouble ld;
> ld = si + ld;
> ld = ld + si;
> ```

对前者，存在二义性，对后者，精准匹配。

## 14.53

> 假设我们已经定义了如第522页所示的SmallInt，判断下面的加法表达式是否合法。如果合法，使用了哪个加法运算符？如果不合法，应该怎样修改代码才能使其合法？
>
> ```cpp
> SmallInt si;
> double d = si + 3.14;
> ```

不合法，产生二义性。

```cpp
SmallInt si;
double d = si + SmallInt(3.14);
```





