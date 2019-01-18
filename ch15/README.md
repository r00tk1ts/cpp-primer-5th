## 15.1

> 什么是虚成员？

类中被声明为virtual的成员，基类希望这类成员在派生类中重定义。除了构造函数外，任意非static成员都可以成为虚成员。

## 15.2

> protected访问说明符与private有何区别？

private成员只能被友元和内部访问，protected权限的成员还可以被派生类成员访问。

## 15.3

> 定义你自己的Quote类和print_total函数。

[Quote.h](Quote.h)

```cpp
double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
  	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
  	return ret;
}
```

## 15.4

> 下面哪条声明语句是不正确的？请解释原因。
>
> `class Base {... };`
>
> (a)`class Derived : public Derived { ... };`
>
> (b)`class Derived : private Base { ... };`
>
> (c)`class Derived : public Base;`

(a)错误，不能自己继承自己。

(b)正确。

(c)错误，声明不可以包含派生列表。

## 15.5

> 定义你自己的Bulk_quote类。

[Bulk_quote.h](Bulk_quote.h)

## 15.6

> 将Quote和Bulk_quote的对象传给15.2.1节练习中的print_total函数，检查该函数是否正确。

[ex15_6.cpp](ex15_6.cpp)

## 15.7

> 定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣，如果购买量一旦超过了限量，则超出的部分将以原价销售。

[ex15_7.h](ex15_7.h)

## 15.8

> 给出静态类型和动态类型的定义。

静态类型是编译时确定的，它是变量声明时的类型或是表达式生成的类型。动态类型则是变量或表达式表示的内存中的对象的类型，动态类型直到运行时才能知道。动态类型是为了实现动态绑定语义。

## 15.9

> 在什么情况下表达式的静态类型可能与动态类型不同？请给出三个静态类型与动态类型不同的例子。

```cpp
Bulk_quote bulk;
Quote *p = &bulk;
Quote &r = bulk;
```

p和r在运行时会实施动态绑定。

## 15.10

> 回忆我们在8.1节进行的讨论，解释第284页中将ifstream传递给Sales_data的read函数的程序是如何工作的。

传递指向派生类的父类引用或指针可以进行动态绑定。

## 15.11

> 为你的Quote类体系添加一个名为debug的虚函数，令其分别显示每个类的数据成员。

见15.3/15.5/15.7

## 15.12

> 有必要将一个成员函数同时声明成override和final吗？为什么？

有必要。override用于说明派生类中的虚函数，如此可以更为清楚的告知编译器我们想要实施虚函数的覆盖操作。override的好处在于可以防止派生类将函数定义写错，如果和基类中的定义不一致，那么override的声明会报错。

而final则表示，不允许后续的派生类去覆盖这个函数，否则会报错。

二者没有什么冲突。

## 15.13

> 给定下面的类，解释每个print函数的机理：
>
> ```cpp
> class base{
> public:
>   	string name(){ return basename;}
>   	virtual void print(ostream &os){ os << basename; }
> private:
>   	string basename;
> };
> class derived : public base{
> public:
>   	void print(ostream &os){ print(os); os << " " << i;}
> private:
>   	int i;
> };
> ```
>
> 在上述代码中存在问题吗？如果有，你该如何修改它？

```cpp
class derived: public base{
public:
  	void print(ostream &os) override { base::print(os);os << " " << i;}
private:
  	int i;
};
```

## 15.14

> 给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数：
>
> ```cpp
> base bobj; base *bp1 = &bobj; base &br1 = bobj;
> derived dobj; base *bp2 = &dobj; base &br2 = dobj;
> ```
>
> (a)`bobj.print();`(b)`dobj.print();`(c)`bp1->name();`
>
> (d)`bp2->name();`(e)`br1.print();`(f)`br2.print();`

(a)基类print

(b)派生类print

(c)基类name

(d)基类name

(e)基类print

(f)派生类print

## 15.15

> 定义你自己的Disc_quote和Bulk_quote。

[Disc_quote.h](Disc_quote.h)

## 15.16

>改写你在15.2.2节练习中编写的数量受限的折扣策略，令其继承Disc_quote。

```cpp
class Limit_quote : public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const std::string& b, double p, std::size_t max, double disc):
        Disc_quote(b, p, max, disc)  {   }

    double net_price(std::size_t n) const override
    { 
    	return n * price * (n < quantity ? 1 - discount : 1 ); 	}

    void debug() const override;
};
```

## 15.17

> 尝试定义一个Disc_quote的对象，看看编译器给出的错误信息是什么？

不能定义抽象基类对象。

## 15.18

> 假设给定了第543页和第544页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许：
>
> ```cpp
> Base *p = &d1;	//d1的类型是Pub_Derv
> p = &d2;		//d2的类型是Priv_Derv
> p = &d3;		//d3的类型是Prot_Derv
> p = &dd1;		//dd1的类型是Derived_from_Public
> p = &dd2;		//dd2的类型是Derived_from_Private
> p = &dd3;		//dd3的类型是Derived_from_Protected
> ```

只有公有继承才能进行派生类到子类的转换，所以只有d1和dd1合法。

## 15.19

> 假设543页和544页的每个类都有如下形式的成员函数：
>
> `void memfcn(Base &b){b = *this;}`
>
> 对于每个类，分别判断上面的函数是否合法。

Derived_from_Private不合法，其他都合法。

## 15.20

> 编写代码检验你对前面两题的回答是否正确。

[ex15_20.cpp](ex15_20.cpp)

## 15.21

> 从下面这些一般性抽象概念中任选一个（或者选一个你自己的），将其对应的一组类型组织成一个继承体系：
>
> (a)图像文件格式(如gif、tiff、jpeg、bmp)
>
> (b)几何图元(如矩形、圆、球形、锥形)
>
> (c)C++语言的类型(如类、函数、成员函数)

略

## 15.22

> 对于你在上一题中选择的类，为其添加合适的虚函数及其公有成员和受保护的成员。

略

## 15.23

> 假设第550页的D1类需要覆盖它继承而来的fcn函数，你应该如何对齐进行修改？如果你修改之后fcn匹配了Base中的定义，则该节的那些调用语句将如何解析？

D1类的fcn改为`int fcn()`。

## 15.24

> 哪种类需要虚析构函数？虚析构函数必须执行什么样的操作？

基类应该有虚析构函数，保证删除指向派生类的父类指针时，会递归调用到父类的析构函数以释放资源。

## 15.25

> 我们为什么为Disc_quote定义了一个默认构造函数？如果去掉该构造函数的话会对Bulk_quote的行为产生什么影响？

因为定义了Disc_quote的其他构造函数隐式的阻止了编译器合成默认构造函数，此时，继承Disc_quote的Bulk_quote的默认构造函数会递归调用到Disc_quote的默认构造函数，如此不在基类中提供就会导致编译时错误。

## 15.26

> 定义Quote和Bulk_quote的拷贝控制成员，令其与合成的版本行为一致。为这些成员以及其他构造函数添加打印状态的语句，使得我们能够知道正在运行哪个程序。使用这些类编写程序，预测程序将创建和销毁哪些对象。重复实验，不断比较你的预测和实际输出结果是否相同，直到预测完全准求再结束。

[ex15_26.h](ex15_26.h)

## 15.27

> 重新定义你的Bulk_quote类，令其继承构造函数。

见15.26

## 15.28

> 定义一个存放Quote对象的vector，将Bulk_quote对象传入其中。计算vector中所有元素总的net_price。

[ex15_28.cpp](ex15_28.cpp)

## 15.29

>再运行一次你的程序，这次传入Quote对象的shared_ptr。如果这次计算出的总额与之前的程序不一致，解释为什么；如果一致，也请说明原因。

[ex15_29.cpp](ex15_29.cpp)

不一致，因为借shared_ptr实现了动态绑定，调用的net_price不同。

## 15.30

> 编写你自己的Basket类，用它计算上一个练习中交易记录的总价格。

[ex15_30.h](ex15_30.h)

## 15.31

> 已知s1、s2、s3和s4都是string，判断下面的表达式分别创建了什么样的对象：
>
> (a)`Query(s1) | Query(s2) & ~Query(s3);`
>
> (b)`Query(s1) | (Query(s2) & ~Query(s3));`
>
> (c)`(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));`

(a)WordQuery, NotQuery, AndQuery, OrQuery

(b)同a

(c)WordQuery，AndQuery，OrQuery

## 15.32

> 当一个Query类型的对象被拷贝、移动、赋值或销毁时，将分别发生什么？

拷贝：拷贝数据成员shared_ptr，调用shared_ptr的拷贝成员。此时指向的对象引用计数加1。

移动：移动数据成员shared_ptr，调用shared_ptr的移动成员。此时引用计数不变，原始的对象的shared_ptr变为nullptr。

销毁：shared_ptr的析构函数会被调用，会递减指向对象的引用计数，如果为0，对象会被销毁。

## 15.33

> 当一个Query_base类型的对象被拷贝、移动、赋值或销毁时，将分别发生什么？

Query_base是虚基类，实际上对象都是它的派生类对象。会执行默认的控制成员，对Query_base来说，什么也不做。

## 15.34

> 针对图15.3构建的表达式。
>
> (a)列举出在处理表达式的过程中执行的所有构造函数。
>
> (b)列举出cout << q所调用的rep。
>
> (c)列举出q.eval()所调用的eval。

麻烦死了，略。

## 15.35

> 实现Query类和Query_base类，其中需要定义rep而无须定义eval。

学习书中定义即可。

## 15.36

> 在构造函数和rep成员中添加打印语句，运行你的代码以检验你对本节第一个练习中(a)、(b)两小题的回答是否正确。

略

## 15.37

> 如果你在派生类中含有`shared_ptr<Query_base>`类型的成员而非Query类型的成员，则你的类需要做出怎样的改变？

很麻烦，涉及Query类型的地方都要改成Query_base指针。重载的运算符需要重写，改为针对Query_base指针，此时复杂的查询请求将无法写成当前简单的级联形式，需要逐个完成运算。

## 15.38

> 下面的声明合法吗？如果不合法，请解释原因；如果合法，请指出该声明的含义。
>
> `BinaryQuery a = Query("fiery") & Query("bird");`
>
> `AndQuery b = Query("fiery") & Query("bird");`
>
> `OrQuery c = Query("fiery") & Query("bird");`

a不合法，因为BinaryQuery是抽象基类。

b不合法，因为operator&返回的是Query，无法转为AndQuery。

c不合法，与b原因相似，无法从Query转为OrQuery。

## 15.39

>实现Query类和Query_base类，求图15.3中表达式的值并打印相关信息，验证你的程序是否正确。

学习书中程序即可。

## 15.40

> 在OrQuery的eval函数中，如果rhs成员返回的是空集将发生什么？如果lhs是空集呢？如果lhs和rhs都是空集又将发生什么？

无所谓，set的构造和插入操作可以正确处理空范围。

## 15.41

> 重新实现你的类，这次使用指向Query_base的内置指针而非shared_ptr。请注意，做出上述改动后你的类将不能再使用合成的拷贝控制成员。

略。需要自己写拷贝控制成员来控制动态内存的分配与释放。

## 15.42

>从下面的几种改进中选择一种，设计并实现它：
>
>(a)按句子查询并打印单词，而不再是按行打印。
>
>(b)引入一个历史系统，用户可以按编号查询之前的某个查询，并可以在其中增加内容或者将其与其他查询组合。
>
>(c)允许用户对结果做出限制，比如从给定范围的行中挑出匹配的进行显示。

略。

