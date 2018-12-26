## 7.1

> 使用2.6.1节练习定义的Sales_data类为1.6节的交易处理程序编写一个新版本。

[ex7_1.cpp](ex7_1.cpp)

## 7,2

> 曾在2.6.2节的联系中编写了一个Sales_data类，请向这个类添加combine和isbn成员。

```cpp
struct Sales_data {
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

## 7.3

> 修改7.1.1节的交易处理程序，令其使用这些成员。

[ex7_3.cpp](ex7_3.cpp)

## 7.4

> 编写一个名为Person的类，使其表示人员的姓名和住址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。

```cpp
struct Person{
    std::string name;
  	std::string address;
};
```

## 7.5

> 在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是const的呢？解释原因。

```cpp
class Person{
private:
    std::string name;
  	std::string address;
public:
  	const string& getName()const {return name;}
  	const string& getAddr()const {return address;}
};
```

函数应该是const的，因为不涉及对数据成员的修改。

返回类型设定为const string&可以提高效率，但必须得有const，如果没有const那么返回的就是对象的private成员，意味着可以肆意更改，破坏了设计上的封装。

返回string也合情合理。

## 7.6

> 对于函数add、read和print，定义你自己的版本。

```cpp
//Sales_data声明前两个为友元函数
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
```

## 7.7

> 使用这些新函数重写7.1.2节练习中的交易处理程序。

[ex7_7.cpp](ex7_7.cpp)

## 7.8

> 为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用？

因为read会修改参数对象，而print不会。

## 7.9

> 对于7.1.2节练习中的代码，添加读取和打印Person对象的操作。

```cpp
// read should be friend function
std::istream &read(std::istream &is, Person &person)
{
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    return os << person.getName() << " " << person.getAddr();
}
```

## 7.10

> 在下面这条if语句中，条件部分的作用是什么？
>
> `if(read(read(cin, data1), data2))`

连续读两个对象，data1和data2，read返回的是cin对象，所以可以连调。

## 7.11

> 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。

[ex7_11.cpp](ex7_11.cpp)

## 7.12

> 把只接受一个istream作为参数的构造函数定义移到类的内部。

```cpp
class Sales_data {
	...
public:
	...
    Sales_data(std::istream &is){read(is, *this);}
    ...
};
```

## 7.13

> 使用istream构造函数重写第229页的程序。

[ex7_13.cpp](ex7_13.cpp)

## 7.14

> 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

`Sales_data() : units_sold(0) , revenue(0){ }`

## 7.15

> 为你的Person类添加正确的构造函数。

```cpp
class Person{
private:
    std::string name;
  	std::string address;
public:
  	Person() = default;
  	Person(const std::string sname, const std::string saddr):name(sname), address(saddr) { }
  	const string& getName()const {return name;}
  	const string& getAddr()const {return address;}
};
```

## 7.16

> 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public说明符之后？什么样的成员应该定义在private说明符之后？

没有限定。可以被外部访问的成员放在public之后，尽可在类内部访问的放在private之后。

## 7.17

> 使用class和struct时有区别吗？如果有，是什么？

唯一的区别在于class默认权限是private，struct默认权限为public。

## 7.18

> 封装是何含义？它有什么用处？

封装是OOP三大特性的第一特性，用于分离数据和接口，隐藏具体类型的实现细节。

## 7.19

> 在你的Person类中，你将把哪些成员声明成public的？哪些声明成private的？解释你这样做的原因。

构造函数和两个get成员声明为public，因为它们需要被外部访问。数据成员应该隐藏，声明为private。

## 7.20

> 友元在什么时候有用？请分别列举出使用友元的利弊。

非类成员函数需要访问private成员时，需要把该函数声明为类的友元。使用友元可以打开访问private成员的渠道，但也一定程度的破坏了封装。

## 7.21

> 修改你的Sales_data类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其工作正常。

上面的已经是完全体了。略。

## 7.22

> 修改你的Person类使其隐藏实现的细节。

同上。

## 7.23

> 编写你自己的Screen类。

```cpp
class Screen {
    public:
        using pos = std::string::size_type;

        Screen() = default;
  		Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' '){}
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};
```

## 7.24

> 给你的Screen类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。

同上。

## 7.25

> Screen能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？

可以依赖，这个原因一言难尽。

- 其一，编译器可以为该类合成默认的拷贝和赋值成员
- 其二，该类无需深拷贝

## 7.26

> 将`Sales_data::avg_price`定义成内联函数。

```cpp
class Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
public:
	Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s) { read(is, *this); }
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data(std::istream &is){}
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
  
  	inline double avg_price() const;      
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}
```

## 7.27

> 给你自己的Screen类添加move、set和display函数，通过执行下面的代码检验你的类是否正确。
>
> ```cpp
> Screen myScreen(5, 5, 'X');
> myScreen.move(4,0).set('#').display(cout);
> cout << "\n";
> myScreen.display(cout);
> cout << "\n";
> ```

[ex7_27.cpp](ex7_27.cpp)

## 7.28

> 如果move、set和display函数的返回类型不是Screen&而是Screen，则在上一个练习中将会发生什么情况？

那么每次返回的都是个临时拷贝对象，而不是myScreen对象，这会导致`.set('#')`修改的是个临时对象，而不是myScreen。

## 7.29

> 修改你的Screen类。令move、set和display函数返回Screen并检查程序运行结果，在上一个练习中你的推测正确吗？

[ex7_29.cpp](ex7_29.cpp)

## 7.30

> 通过this指针使用成员的做法虽然合法，但是有些多余。讨论显式地使用指针访问成员的优缺点。

优点在于更容易区分是否是类成员，且当参数名与成员名相同时可以借此区分。

缺点在于写起来更啰嗦，大部分情况下是冗余的。

## 7.31

> 定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。

```cpp
class X;
class Y{
    X x;
};
class X{
    Y *py = nullptr;
};
```

## 7.32

> 定义你自己的Screen和Windows_mgr，其中clear是Windows_mgr的成员，是Screen的友元。

```cpp
class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
  		friend void Window_mgr::clear(ScreenIndex);
    public:
        using pos = std::string::size_type;

        Screen() = default;
  		Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' '){}
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }
		Screen move(pos r, pow c) { cursor = r * width + c; return *this; }
		Screen set(char c) { contents[cursor] = c; return *this; }
		Screen set(pos r, pos c, char ch) { contents[r*width+c] = ch; return *this; }
		const Screen display(std::ostream os) const { os << contents; return *this; }
		
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

inline void Window_mgr::clear(ScreenIndex i)
{ 
    if (i >= screens.size()) 
      	return;    
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
```

## 7.33

> 如果我们给Screen添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。
>
> ```cpp
> pos Screen::size() const
> {
>     return height * width;
> }
> ```

pos是Screen内部的类型别名，外部使用需要增加作用域前缀：`Screen::pos`。

## 7.34

> 如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？

会报错，类型别名必须声明在使用前。

## 7.35

> 解释下面代码的含义，说明其中的Type的initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
>
> ```cpp
> typedef string Type;
> Type initVal();
> class Exercise{
> public:
>   	typedef double Type;
>   	Type setVal(Type);
>   	Type initVal();
> private:
>   	int val;
> };
>
> Type Exercise::setVal(Type parm){
>     val = parm + initVal();
>   	return val;
> }
> ```

initVal使用的Type是string类型。

Exercise类内部，initVal使用的Type是double类型。

setVal存在错误，类内声明的返回类型和类外定义的类型不一致:

```cpp
Exercise::Type Exercise::setVal(Type parm){
    val = parm + initVal();
  	return val;
}
```

参数无需作用域即可识别。

## 7.36

> 下面的初始值是错误的，请找出问题所在并尝试修改它。
>
> ````cpp
> struct X{
>     X (int i, int j): base(i), rem(base % j) { }
>   	int rem, base;
> };
> ````

成员初始化顺序严格按照定义的顺序，base在rem之后定义，所以rem的初始化值是未定义的。改为：

```cpp
struct X{
    X (int i, int j): base(i), rem(base % j) { }
  	int base, rem;
};
```

## 7.37

> 使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有数据成员的值。
>
> ```cpp
> Sales_data first_item(cin);
> int main(){
>     Sales_data next;
>   	Sales_data last("9-999-99999-9");
> }
> ```

first_item使用了`Sales_data(std::istream &is);`，初始为0,0.0和""。

next使用了默认构造函数，初始为0,0.0和""。

last使用了`Sales_data(const std::string &s)`，初始为0,0.0和"9-999-99999-9"。

## 7.38

> 有些情况下我们希望提供cin作为接受istream&参数的构造函数的默认实参，请声明这样的构造函数。

`Sales_data(std::istream &is = std::cin);`

## 7.39

> 如果接受string的构造函数和接受istream&的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

不合法，因为这会导致Sales_data()的二义性。

## 7.40

> 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
>
> (a)Book	(b)Date	(c)Employee
>
> (d)Vehicle	(e)Object	(f)Tree

略。。。

## 7.41

> 使用委托构造函数重新编写你的Sales_data类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别参加Sales_Data对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

[ex7_41.cpp](ex7_41.cpp)

## 7.42

> 对于你在联系7.40中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

同略

## 7.43

> 假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。定义类C，C有一个NoDefault类型的成员，定义C的默认构造函数。

```cpp
class C{
public:
  	C() : ndft(0) { }
private:
  	DoDefault ndft;
}
```

## 7.44

> 下面这条声明合法吗？如果不，为什么？
>
> `vector<NoDefault> vec(10);`

不合法，因为NoDefault没有默认构造函数。

## 7.45

> 如果在上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？

合法，因为C有默认构造函数。

## 7.46

> 下面哪些论断是不正确的？为什么？
>
> (a)一个类必须至少提供一个构造函数。
>
> (b)默认构造函数是参数列表为空的构造函数。
>
> (c)如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
>
> (d)如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。

(a)正确，程序员不提供则编译器会合成默认构造器。

(b)不正确，所有参数都提供默认参数的构造器也是默认构造函数。

(c)不正确，理应提供。

(d)不正确，编译器合成默认构造器是有条件的，不展开了。

## 7.47

> 说明接受一个string参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。

不应该定义为explicit的，因为我们希望从string到Sales_data的隐式转换。

## 7.48

> 假定Sales_data的构造函数不是explicit的，则下述定义将执行什么样的操作？
>
> ```cpp
> string null_isbn("9-999-99999-9");
> Sales_data item1(null_isbn);
> Sales_data item2("9-999-99999-9");
> ```
>
> 如果Sales_data的构造函数是explicit的，又会发生什么呢？

不管是不是explicit，都没问题，因为都是直接初始化。explicit会阻止拷贝初始化。

[ex7_48.cpp](ex7_48.cpp)

## 7.49

> 对于combine函数的三种不同声明，当我们调用i.combine(s)时分别发生什么情况？其中i是一个Sales_data，而s是一个string对象。
>
> (a)`Sales_data &combine(Sales_data);`
>
> (b)`Sales_data &combine(Sales_data&);`
>
> (c)`Sales_data &combine(const Sales_data&) const;`

(a)

s通过接受const string&参数的构造函数构造Sales_data对象，传递给combine。

(b)

错误，因为找不到需要匹配的`Sales_data::combine(std::string&)`

(c)

错误，尾const是有问题的，就算没有这个const，也是错误的，原理与b相同。

## 7.50

> 确定在你的Person类中是否有一些构造函数应该是explicit的。

接受单个istream&参数的构造函数应该是explicit的，因为不希望从istream对象到Person的隐式转换。

## 7.51

> vector将其单参数的构造函数定义成explicit的，而string则不是，你觉得原因何在？

因为string要适配C风格字符串，往往需要最常见的C风格字符串——字符串常量来隐式转换成string。

而vector则不然，当需要传递`vector<T>&`时，如果传递了一个T，那么应该要报错才对，而不是希望编译器从T到`vector<T>`的一个隐式转换。

## 7.52

> 使用2.6.1节的Sales_data类，解释下面的初始化过程。如果存在问题，尝试修改它。
>
> `Sales_data item = {"978-0590353403", 25, 15.99};`

本身没问题。这题所用的Sales_data类是个雏形，当时还是个聚合类，初始化顺序没问题，所以是正确的。

对后期完全体Sales_data来说，因为定义了`Sales_data(const std::string &s, unsigned n, double p)`，所以也没问题，但这又是另一回事了。

## 7.53

> 定义你自己的Debug。

略

## 7.54

> Debug中以set_开头的成员应该被声明成constexpr吗？如果不，为什么？

set_开头的函数会修改数据成员，显然不能声明成constexpr。

## 7.55

> 7.5.5节的Data类是字面值常量类吗？请解释原因。

非也。std::string不是字面值类型。

## 7.56

> 什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？

类的静态成员与整个类关联，而不是和某个类对象关联，类静态成员是单例。

类静态成员可以作为单例存储类对象共享的通用数据，一个对象修改了数据，也会反射到其他对象上。

## 7.57

> 编写你自己的Account类。

[ex7_57.cpp](ex7_57.cpp)

## 7.58

> 下面的静态数据成员的声明和定义有错误吗？请解释原因。
>
> ```cpp
> // example.h
> class Example{
> public:
>     static double rate = 6.5;
>     static const int vecSize = 20;
>     static vector<double> vec(vecSize);
> };
> // example.c
> #include "example.h"
> double Example::rate;
> vector<double> Example::vec;
> ```

静态成员rate不是常量，不能在类内设置初始值。静态的vec不能在类内初始化。

修正：

```cpp
// example.h
class Example{
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};
// example.c
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```