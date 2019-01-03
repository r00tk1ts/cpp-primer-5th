## 12.1

> 在此代码的结尾，b1和b2各包含多少个元素？
>
> ```cpp
> StrBlob b1;
> {
>     StrBlob b2 = {"a", "an", "the"};
>   	b1 = b2;
>   	b2.push_back("about");
> }
> ```

b1包含4个元素，因为合成的拷贝构造函数会执行`b1.data = b2.data`的操作，最终b1和b2的智能指针指向的是同一个容器。

b2没有意义，因为出了大括号，b2生命周期就消逝了。

## 12.2

> 编写你自己的StrBlob类，包含const版本的front和back。

[ex12_2.h](ex12_2.h)

## 12.3

>StrBlob需要const版本的push_back和pop_back吗？如果需要，添加进去。否则，解释为什么不需要。

不需要，因为StrBlob类不需要这种语义，尽管const版本可以通过编译（没有改变data，改变的是data指向的容器），但这种设计从逻辑上来看是冗余的。

## 12.4

> 在我们的check函数中，没有检查i是否大于0。为什么可以忽略这个检查？

因为`vector<string>::size_type`是unsigned。另一方面，check是private成员，只会被内部调用，内部调用可以保证传值i的正确性。

## 12.5

> 我们未编写接受一个initializer_list explicit参数的构造函数。讨论这个设计策略的优点和缺点。

explicit用于阻止initializer_list到StrBlob的隐式转换。

不使用explicit的优点在于编译器可以做自动的隐式转换，可以传递StrBlob时直接传`{"hello", "world"}`。缺点在于不易于调试和理解。

## 12.6

> 编写函数，返回一个动态分配的int的vector。将此vector传递给另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

[ex12_6.cpp](ex12_6.cpp)

## 12.7

> 重做上一题，这次使用shared_ptr而不是内置指针。

[ex12_7.cpp](ex12_7.cpp)

## 12.8

> 下面的函数是否有错误？如果有，解释错误原因。
>
> ```cpp
> bool b(){
>     int* p = new int;
>   	// ...
>   	return p;
> }
> ```

错了，返回类型不匹配，指针值被转成一个bool值，返回后指针丢失，内存泄露。

## 12.9

> 解释下面代码执行的结果：
>
> ```cpp
> int *q = new int(42), *r = new int(100);
> r = q;
> auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
> r2 = q2;
> ```

r指向q所指涉的对象，原本指涉的对象内存泄露。

r2指向q2所指涉的对象，该对象的引用计数变为2，r2原本指向的对象引用计数变为0，被自动释放。

## 12.10

> 下面的代码调用了第413页中定义的process函数，解释此调用是否正确。如果不正确，应如何修改？
>
> ```cpp
> shared_ptr<int> p(new int(42));
> process(shared_ptr<int>(p));
> ```

正确。

## 12.11

> 如果我们像下面这样调用process，会发生什么？
>
> `process(shared_ptr<int>(p.get()));`

运行时错误，double free。

因为传给process的是个临时智能指针对象，它指向的是p所指向的对象，但是通过p.get()的拷贝手法并没有增加p所指对象的引用计数。process返回后临时对象的析构会释放p所指的对象，而main返回后，又会析构p对象而再次释放所指对象，导致2free。

## 12.12

> p和q的定义如下，对于接下来的对process的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：
>
> ```cpp
> auto p = new int();
> auto sp = make_shared<int>();
> ```
>
> (a)`process(sp);`
>
> (b)`process(new int());`
>
> (c)`process(p)`;
>
> (d)`process(shared_ptr<int>(p));`

a合法，拷贝shared_ptr到process中。

b不合法，无法隐式转换到shared_ptr。

c不合法，无法隐式转换到shared_ptr。

d合法，但可能引起double free。因为p所指对象会随着process返回，临时shared_ptr对象的析构而释放，此后delete p就会导致double free。这个故事告诉我们，不要混用普通指针和智能指针。

## 12.13

> 如果执行下面的代码，会发生什么？
>
> ```cpp
> auto sp = make_shared<int>();
> auto p =sp.get();
> delete p;
> ```

引起double free，因为sp在生命周期结束之后，会因析构而释放所指的对象，但此时所指的对象已经通过p释放过了。

这个故事告诉我们，要慎用get方法。

## 12.14

> 编写你自己版本的用shared_ptr管理connection的函数。

[ex12_14.cpp](ex12_14.cpp)

## 12.15

> 重写第一题的程序，用lambda代替end_connection函数。

[ex12_15.cpp](ex12_15.cpp)

## 12.16

> 如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。

[ex12_16.cpp](ex12_16.cpp)

## 12.17

> 下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
>
> ```cpp
> int ix = 1024, *pi = &ix, *pi2 = new int(2048);
> typedef unique_ptr<int> IntP;
> ```
>
> (a) `IntP p0(ix);`
>
> (b)`IntP p1(pi);`
>
> (c)`IntP p2(pi2);`
>
> (d)`IntP p3(&ix);`
>
> (e)`IntP p4(new int(2048));`
>
> (f)`IntP p5(p2.get());`

(a)不合法，必须接受int*。

(b)合法，因为pi是int*，但这可能引起问题。一旦p1生命周期结束，就会尝试用默认的delete去释放pi所指的对象，但pi指向的对象并不是通过new出来的，所以就会导致运行时错误。

(c)合法，但是与b类似，p2的生命周期结束后，pi2指向的对象就会被delete，此时pi2称为悬垂指针。

(d)合法，与b相同。

(e)完全合法，正确的用法。

(f)合法，但会引起问题，这里例子给得不太好，因为p2本身就有问题。改成`IntP p5(p4.get());`说道说道。通过危险的get可以让p5和p2都指向相同的对象，但当二者生命周期都结束时，后一个就会因为2free而导致运行时错误。

## 12.18

> shared_ptr为什么没有release成员？

因为shared_ptr可能是共享的，存在其他的shared_ptr指向相同的对象，一人release，那么其他就要遭殃，从设计的角度来说是自相矛盾的。

## 12.19

> 定义你自己版本的StrBlobPtr，更新StrBlob类，加入恰当的friend声明及begin和end成员。

[ex12_19.h](ex12_19.h)

## 12.20

> 编写程序，逐行读入一个输入文件，将内容存入一个StrBlob中，用一个StrBlobPtr打印出StrBlob中的每个元素。

[ex12_20.cpp](ex12_20.cpp)

## 12.21

> 也可以这样编写StrBlobPtr的deref成员：
>
> ```cpp
> std::string& deref() const{
>     return (*check(curr, "dereference past end"))[curr];
> }
> ```
>
> 你认为哪个版本更好？为什么？

原始的版本好，这个版本可读性较差。

## 12.22

> 为了能让StrBlobPtr使用const StrBlob，你觉得应该如何修改？定义一个名为ConstStrBlobPtr的类，使其能够指向const StrBlob。

[ex12_22.h](ex12_22.h) | [ex12_22.cpp](ex12_22.cpp)

## 12.23

> 编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的char数组中。重写这个程序，连接两个标准库string对象。

[ex12_23.cpp](ex12_23.cpp)

## 12.24

> 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。

[ex12_24.cpp](ex12_24.cpp)

## 12.25

> 给定下面的new表达式，你应该如何释放pa？
>
> `int *pa = new int[10];`

`delete[] pa;`

## 12.26

> 用allocator重写第427页中的程序。

[ex12_26.cpp](ex12_26.cpp)

## 12.27

> TextQuery和QueryResult类只使用了我们已经介绍过的语言和标准库特性。不要提前看后续章节内容，只用已经学到的只是对这两个类编写你自己的版本。

[ex12_27.cpp](ex12_27.cpp) | [ex12_27.h](ex12_27.h)

## 12.28

> 编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个文件，并与用户交互来查询单词。使用vector、map和set容器来保存来自文件的数据并生成查询结果。

[ex12_28.cpp](ex12_28.cpp)

## 12.29

> 我们曾经用do while循环来编写管理用户交互的循环。用do while重写本节程序，解释你倾向于哪个版本，为什么。

```cpp
do{
    cout << "Enter word to look for, or q to quit: ";
    string s;
    if(!(cin >> s) || s == "q")
        break;
    print(cout, tq.query(s)) << endl;
}while(true);
```

do while更好一点，可读性高。

## 12.30

> 定义你自己版本的TextQuery和QueryResult类，并执行12.3.1节中的runQueries函数。

[ex12_30.cpp](ex12_30.cpp)

## 12.31

> 如果用vector代替set保存行号，会有什么差别？哪种方法更好？为什么？

vector无法保证每个元素的unique特性，因此set更好一些。

## 12.32

> 重写TextQuery和QueryResult类，用StrBlob代替`vector<string>`保存输入文件。

[ex12_32.h](ex12_32.h) | [ex12_32.cpp](ex12_32.cpp)

## 12.33

> 在第15章中我们将扩展查询系统，在QueryResult类中将会需要一些额外的成员。添加名为begin和end的成员，返回一个迭代器，指向一个给定查询返回的行号的set中的位置。再添加一个名为get_file的成员，返回一个shared_ptr，指向QueryResult对象中的文件。

[ex12_33.cpp](ex12_33.cpp)

三个成员已经在12.32中追加。

