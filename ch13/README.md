## 13.1

> 拷贝构造函数是什么？什么时候使用它？

拷贝构造函数是第一个参数为类类型引用（如果有其他参数，则它们必须有默认值）的构造函数。拷贝初始化时会使用拷贝构造函数（也可能会用移动构造函数）：

- 使用`=`初始化类对象
- 传递类类型参数或返回类类型对象（非指针或引用）
- 花括号列表初始化一个数组中的元素或一个聚合类中的成员

## 13.2

> 解释为什么下面的声明是非法的：
>
> `Sales_data::Sales_data(Sales_data rhs);`

这会导致递归调用的死循环。调用拷贝构造函数时因为rhs是非引用类型，所以为了调用拷贝构造函数，还需要对rhs调用拷贝构造函数来拷贝实参，然后就死循环了。

## 13.3

> 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？

编译器会合成拷贝构造函数，StrBlob会拷贝成员data，使用shared_ptr的拷贝构造函数来拷贝。StrBlobPtr会拷贝成员wptr，用weak_ptr的拷贝构造函数拷贝，然后拷贝内置类型curr，直接内存复制。

## 13.4

>假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
>
>```cpp
>Print global;
>Point foo_bar(Point arg)
>{
>    Point local = arg, *heap = new Point(global);
>  	*heap = local;
>  	Point pa[4] = {local, *heap};
>  	return *heap;
>}
>```

传参arg时会调用拷贝构造函数。

`Point local = arg`初始化local时会调用拷贝构造函数。

`*heap = new Point(global);`显式地调用了拷贝构造函数。

`pa[4]`列表初始化时对前两个成员调用了拷贝构造函数。

函数返回时调用了拷贝构造函数。

## 13.5

> 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，并将对象拷贝到ps指向的位置，而不是ps本身的位置。
>
> ```cpp
> class HasPtr{
> public:
>   	HasPtr(const std::string & = std::string()) : ps(new std::string(s)), i(0) { }
> private:
>   	std::string *ps;
>   	int i;
> };
> ```

```cpp
HasPtr(const HasPtr& rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) { }
```

## 13.6

> 拷贝赋值运算符是什么？什么时候使用它？合成拷贝赋值运算符完成什么工作？什么时候会生成合成拷贝赋值运算符？

是类对操作符`operator=`的重载，定义为类的成员函数，左侧运算对象隐式绑定到this参数，右侧运算对象作为一个类类型引用参数传入。函数返回指向左侧对象的引用。

对类对象进行赋值操作时会调用拷贝赋值运算符函数。

合成拷贝赋值运算符会对右侧对象的非static成员逐一赋值给左侧对象的对应成员，类类型成员会调用到其本身的拷贝赋值运算符。

类未定义时编译器会自动合成（但某些条件下不会合成）。

## 13.7

> 当我们将一个StrBlob赋值给另一个StrBlob时，会发生什么？赋值StrBlobPtr呢？

会调用合成的拷贝赋值运算符。StrBlob会对data成员进行赋值，使用shared_ptr的拷贝赋值运算符完成。StrBlobPtr会先赋值wptr，用weak_ptr的拷贝赋值运算符完成，然后赋值内置类型curr，对内置类型来说就是简单的内存复制。

## 13.8

> 为13.1.1节练习13.5中的HasPtr类编写赋值运算符。类似拷贝构造函数，你的赋值运算符应该将对象拷贝到ps指向的位置。

```cpp
HasPtr& operator=(const HasPtr& rhs){
    if(this != &rhs){
        std::string *temp = new std::string(*rhs.ps);
      	delete ps;
      	ps = temp;
      	i = rhs.i;
    }
  	return *this;
}
```

## 13.9

> 析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？

析构函数是类的特殊的成员函数，名字是`~`跟类名，也没有返回值，不接受任何参数。与构造函数功能相反，析构函数在类被销毁时被调用负责释放成员的非static对象。

合成的析构函数什么都不做。

未定义析构时编译器会默认合成。

## 13.10

> 当一个StrBlob对象销毁时会发生什么？一个StrBlobPtr对象销毁时呢？

会调用默认合成的析构函数，该析构函数函数体为空，执行完毕后会进入隐含的析构阶段，这一阶段会销毁非static成员data，这是通过调用shared_ptr的析构函数来完成的。shared_ptr的析构会销毁vector对象。

StrBlobPtr类似，通过weak_ptr的析构函数摧毁weak_ptr成员，curr是内置类型，销毁它不会有什么动作。

## 13.11

> 为前面练习中的HasPtr类添加一个析构函数。

```cpp
~HasPtr(){delete this;}
```

## 13.12

> 在下面的代码片段中会发生几次析构函数调用？
>
> ```cpp
> bool fcn(const Sales_data *trans, Sales_data accum)
> {
>     Sales_data item1(*trans), item2(accum);
>   	return item1.isbn() != item2.isbn();
> }
> ```

fcn调用结束后，item1和item2都会析构，参数accum会析构。一共三次。

## 13.13

> 理解拷贝控制成员和构造函数的一个好办法是定义一个简单的类，为该类定义这些成员，每个成员都打印出自己的名字：
>
> ```cpp
> struct X{
>     X(){std::cout << "X()" << std::endl;}
>   	X(const X&){std::cout << "X(const X&)" << std::endl;}
> };
> ```
>
> 给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用X的对象：将它们作为非引用和引用参数传递；动态分配它们；将它们存放于容器中；诸如此类。观察程序的输出，直到你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。当你观察程序输出时，记住编译器可以略过对拷贝构造函数的调用。

```cpp
X& operator=(const X&){ std::cout << "operator=" << std::endl;}
~X(){std::cout << "~X()" << std::endl;}
```

## 13.14

> 假定numbered是一个类，它有一个默认拷贝构造函数，能为每个对象生成唯一的序号，保存在名为mysn的数据成员中。假定numbered使用合成的拷贝控制成员，并给定如下函数：
>
> `void f(numbered s){ cout << s.mysn << endl; }`
>
> 则下面代码输出什么内容？
>
> ```cpp
> numbered a, b = a, c = b;
> f(a); f(b); f(c);
> ```

如果使用合成的拷贝构造函数，那么三者的mysn将是相同的。

## 13.15

>假定numbered定义了一个拷贝构造函数，能生成一个新的序号。这回改变上一题中调用的输出结果吗？如果会改变，为什么？新的输出结果是什么？

会改变，三个的mysn各不相同，且输出的3个mysn和a、b、c的还不同。

假设a是0，b是1，c是2，那么输出的可能是3,4,5。

## 13.16

> 如果f中的参数是const numbered&，将会怎样？这会改变输出结果吗？如果会改变，为什么？新的输出结果是什么？

会改变，因为f不会对参数调用拷贝构造函数了，沿着上一题的改变，此时输出0,1,2。

## 13.17

> 分别编写前三题中所描述的numbered和f，验证你是否正确预测了输出结果。

略。

## 13.18

> 定义一个Employee类，它包含雇员的姓名和唯一的雇员证号。为这个类定义默认构造函数，以及接受一个表示雇员姓名的string的构造函数。每个构造函数应该通过递增一个static数据成员来生成一个唯一的证号。

[ex13_18.h](ex13_18.h)

## 13.19

> 你的Employee类需要定义它自己的拷贝控制成员吗？如果需要，为什么，如果不需要，为什么？实现你认为Employee需要的拷贝控制成员。

如果允许拷贝，那么需要自己定义而不能依赖于编译器合成的版本，因为要保证id的unique特性。不允许拷贝则应该禁止拷贝控制成员。

## 13.20

> 解释当我们拷贝、赋值或销毁TextQuery和QueryResult类对象时会发生什么。

类成员会被拷贝。对类类型成员会递归调用其类的拷贝构造或赋值运算符。

销毁时合成的析构函数在第二阶段会递归调用到对应的析构函数。

## 13.21

> 你认为TextQuery和QueryResult类需要定义它们自己版本的拷贝控制成员吗？如果需要，为什么？如果不需要，为什么？实现你认为这两个类需要的拷贝控制操作。

没必要自己定义，没什么额外的骚操作需要做。

## 13.22

> 假定我们希望HasPtr的行为像一个值。即，对于对象所指向的string成员，每个对象都有一份自己的拷贝。我们将在下一节介绍拷贝控制成员的定义。但是，你已经学习了定义这些成员所需的知识。在继续学习下一节之前，为HasPtr编写拷贝构造函数和拷贝赋值运算符。

这个实际上前面已经写过了。

[ex13_22.h](ex13_22.h)

## 13.23

> 比较上一节练习中你编写的拷贝控制成员和这一节的代码。确定你理解了你的代码和我们的代码之间的差异（如果有的话）。

略。

## 13.24

> 如果本节中的HasPtr版本未定义析构函数，将会发生什么？如果未定义拷贝构造函数，将会发生什么？

内存泄露，浅拷贝指针而非内存。

## 13.25

> 假定希望定义StrBlob的类值版本，而且希望继续使用shared_ptr，这样我们的StrBlobPtr类就仍能使用指向vector的weak_ptr了。你修改后的类将需要一个拷贝构造函数和一个拷贝赋值运算符，但不需要析构函数。解释拷贝构造函数和拷贝赋值运算符必须做什么。解释为什么不需要析构函数。

拷贝控制成员应该透过shared_ptr拷贝容器，而不是拷贝shared_ptr去共享同一个容器。不需要析构是因为shared_ptr析构时会释放容器。

## 13.26

> 对上一题中描述的StrBlob类，编写你自己的版本。

[ex13_26.h](ex13_26.h) | [ex13_26.cpp](ex13_26.cpp)

## 13.27

> 定义你自己的使用引用计数版本的HasPtr。

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) { }
    HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
    HasPtr& operator=(const HasPtr &rhs) {
        ++*rhs.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    } 
private:
    std::string *ps;
    int i;
    size_t *use;
};
```

## 13.28

> 给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。
>
> (a)
>
> ```cpp
> class TreeNode{
> private:
>   	std::string value;
>   	int count;
>   	TreeNode *left;
>   	TreeNode *right;
> };
> ```
>
> (b)
>
> ```cpp
> class BinStrTree {
> private:
>   	TreeNode *root;
> };
> ```

```cpp
//a
class TreeNode{
public:
  	TreeNode():count(1), left(nullptr), right(nullptr){}
  	TreeNode(const TreeNode& rhs):value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {++count; }
  	TreeNode& operator=(const TreeNode &rhs){
        ++rhs.count;
      	if(--count == 0){
            delete left;
          	delete right;
        }
      	value = rhs.value;
      	left = rhs.left;
      	right = rhs.right;
      	count = rhs.count;
      	return *this;
    }
  	~TreeNode(){if(--count == 0){delete left; delete right;}}
private:
  	std::string value;
  	int count;
  	TreeNode *left;
  	TreeNode *right;
}

//b
class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) { }
    BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) { }
    BinStrTree& operator=(const BinStrTree &bst){
        TreeNode *temp = new TreeNode(*bst.root);
      	delete root;
      	root = temp;
      	return *this;
    }
    ~BinStrTree() { delete root; }

private:
    TreeNode *root;
};
```

## 13.29

> 解释swap(HasPtr&, HasPtr&)中对swap的调用不会导致递归循环。

因为内部的swap调用的不是本体，何来的递归？

## 13.30

> 为你的类值版本的HasPtr编写swap函数，并测试它。为你的swap函数添加一个打印语句，指出函数什么时候执行。

[ex13_30.h](ex13_30.h)

## 13.31

> 为你的HasPtr类定义一个<运算符，并定义一个HasPtr的vector。为这个vector添加一些元素，并对它执行sort。注意何时会调用swap。

[ex13_31.cpp](ex13_31.cpp)

## 13.32

> 类指针的HasPtr版本会从swap函数受益吗？如果会，得到了什么益处？如果不是，为什么？

swap的本质在于不希望额外的内存分配。对该例来说，指针ps和整型i的swap都没什么意义，所以HasPtr版本的swap比较鸡肋。

## 13.33

> 为什么Message的成员save和remove的参数是一个Folder&？为什么我们不将参数定义为Folder或是const Folder&？

因为save和remove会修改传入的Folder对象，因此要传引用不能传值，也不能指定const。

## 13.34

> 编写本节所描述的Message。

[ex13_34.h](ex13_34.h) | [ex13_34.cpp](ex13_34.cpp)

## 13.35

> 如果Message使用合成的拷贝控制成员，将会发生什么？

Folder会与Message不同步。

## 13.36

> 设计并实现对应的Folder类。此类应该保存一个指向Folder中包含Message的set。

见13.34

## 13.37

> 为Message类添加成员，实现向folders添加或删除一个给定的Folder*。这两个成员类似Folder类的addMsg和remMsg操作。

见13.34

## 13.38

> 我们并未使用拷贝和交换方式来设计Message的赋值运算符。你认为其原因是什么？

拷贝和交换是处理动态分配内存的，Message类中无需动态分配内存，所以不需要二者。这里如果使用二者，反而冗余。

## 13.39

> 编写你自己版本的StrVec，包括自己版本的reserve、capacity和resize。

[ex13_39.h](ex13_39.h) | [ex13_39.cpp](ex13_39.cpp)

## 13.40

> 为你的StrVec类添加一个构造函数，它接受一个`initializer_list<string>`参数。

见13.39

## 13.41

> 在push_back中，我们为什么在construct调用中使用后置递增运算？如果使用前置递增运算的话，会发生什么？

first_free的位置会有问题。

## 13.42

> 在你的TextQuery和QueryResult类中用你的StrVec类代替`vector<string>`，以此来测试你的StrVec类。

略。

## 13.43

> 重写free成员，用for_each和lambda来代替for循环destroy元素。你更倾向于哪种实现，为什么？

```cpp
for_each(elements, first_free, [this](std::string &rhs){alloc.destroy(&rhs);});
```

我个人认为前一种更好，可读性高。

## 13.44

> 编写标准库string类的简化版本，命名为String。你的类应该至少有一个默认构造函数和一个接受C风格字符串指针参数的构造函数。使用allocator为你的String类分配所需内存。

[ex13_44.h](ex13_44.h) | [ex13_44.cpp](ex13_44.cpp)

## 13.45

> 解释右值引用和左值引用的区别。

左值引用是绑定到左值的引用，右值引用绑定到右值对象，生命周期是短暂的，即将被销毁。

## 13.46

> 什么类型的引用可以绑定到下面的初始化器上？
>
> ```cpp
> int f();
> vector<int> vi(100);
> int? r1 = f();
> int? r2 = vi[0];
> int? r3 = r1;
> int? r4 = vi[0] * f();
> ```

```cpp
int &&r1 = f();
int &r2 = vi[0];
int &r3 = r1;
int &&r4 = vi[0] * f();
```

## 13.47

> 对你在练习13.44中定义的String类，为它的拷贝构造函数和拷贝赋值运算符添加一条语句，在每次函数执行时打印一条消息。

见13.44

## 13.48

> 定义一个`vector<String>`并在其上多次调用push_back。运行你的程序，并观察String被拷贝了多少次。

[ex13_48.cpp](ex13_48.cpp)

## 13.49

> 为你的StrVec、String和Message类添加一个移动构造函数和一个移动赋值运算符。

[StrVec.h](StrVec.h) | [StrVec.cpp](StrVec.cpp)

[String.h](String.h) | [String.cpp](String.cpp)

[Message.h](Message.h) | [Message.cpp](Message.cpp)

## 13.50

> 在你的String类的移动操作中添加打印语句，并重新运行13.6.1节的练习13.48中的程序，它使用了一个`vector<String>`，观察什么时候会避免拷贝。

略

## 13.51

> 虽然unique_ptr不能拷贝，但我们在12.1.5节中编写了一个clone函数，它以值方式返回一个unique_ptr。解释为什么函数是合法的，以及为什么它能正确工作。

因为这里优先匹配了移动语义，unique_ptr具有移动成员，所以可以正确工作。

## 13.52

> 详细解释478页中的HasPtr对象的赋值发生了什么？特别是，一步一步描述hp、hp2以及HasPtr的赋值运算符中的参数rhs的值发生了什么变化。

`hp = hp2;`

hp2是左值，因此调用拷贝成员。

`hp = std::move(hp2);`

此时`std::move`取到右值，调用移动成员。

## 13.53

> 从底层效率的角度看，HasPtr的赋值运算符并不理想，解释为什么。为HasPtr实现一个拷贝赋值运算符和一个移动赋值运算符，并比较你的新的移动赋值运算符中执行的操作和拷贝并交换版本中执行的操作。

[this question && answer](http://stackoverflow.com/questions/21010371/why-is-it-not-efficient-to-use-a-single-assignment-operator-handling-both-copy-a).

[ex13_53.h](ex13_53.h) | [ex13_53.cpp](ex13_53.cpp)

## 13.54

> 如果我们为HasPtr定义了移动赋值运算符，但未改变拷贝并交换运算符，会发生什么？编写代码验证你的答案。

因二义性而报错。

## 13.55

> 为你的StrBlob添加一个右值引用版本的push_back。

```cpp
void push_back(string &&t){
    data->push_back(std::move(t));
}
```

## 13.56

> 如果sorted定义如下，会发生什么：
>
> ```cpp
> Foo Foo::sorted() const &{
>     Foo ret(*this);
>     return ret.sorted();
> }
> ```

无限递归，栈溢出。

## 13.57

> 如果sorted定义如下，会发生什么：
>
> ```cpp
> Foo Foo::sorted() const & {return Foo(*this).sorted();}
> ```

没问题，会调用移动版本。

## 13.58

> 编写新版本的Foo类，其sorted函数有打印语句，测试这个类，来验证你对前两题的答案是否正确。

[ex13_58.cpp](ex13_58.cpp)