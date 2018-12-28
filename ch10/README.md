## 10.1

> 头文件algorithm中定义了一个名为count的函数，它类似find，接受一对迭代器和一个值作为参数。count返回给定值在序列中出现的次数。编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值。

[ex10_1.cpp](ex10_1.cpp)

## 10.2

> 重做上一题，但读取string序列存入list中。

[ex10_2.cpp](ex10_2.cpp)

## 10.3

> 用accumulate求一个`vector<int>`中的元素之和。

```cpp
std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
std::cout << std::accumulate(v.begin(),v.end(),0) << std::endl;
```

## 10.4

> 假定v是一个`vector<double>`，那么调用`accumulate(v.cbegin(), v.cend(), 0)`有何错误（如果存在的话）？

计算的结果会不正确，应该传入0.0。

因为字面值0编译器会识别为int，而accumulate这个函数模板会根据第三个参数的类型进行推导，且函数会返回第三种参数类型，这里因为是int所以截断了。

## 10.5

> 在本节对名册（roster）调用equal的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？

此时比较的会是地址值，结果显然不符合预期。

## 10.6

> 编写程序，使用fill_n将一个序列中的int值都设置为0。

```cpp
std::vector<int> v(10,42);
std::fill_n(v.begin(),v.size(), 0);
```

## 10.7

> 下面程序是否有错误？如果有，请改正。
>
> (a)
>
> ```cpp
> vector<int> vec; list<int> lst; int i;
> while(cin >> i)
> 	lst.push_back(i);
> copy(lst.cbegin(), lst.cend(), vec.begin());
> ```
>
> (b)
>
> ```cpp
> vector<int> vec;
> vec.reserve(10); 
> fill_n(vec.begin(), 10, 0);
> ```

(a)有错误，vec为空，无法容纳lst中的元素。改用插入迭代器。

`copy(lst.cbegin(), lst.cend(), back_inserter(vec));`

(b)有错误，reserve只是改变capacity，而不是size，当前size还是0。可以有两种改法，一种用resize替换reserve，另一种对vec用插入迭代器。

`fill_n(back_inserter(vec), 10, 0);`

## 10.8

> 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？

看了一下，这里翻译的断言不是语义上的alert，是单纯的claim的直译。

插入迭代器`back_inserter`是`<iterator>`头文件的一部分，而非`<algorithm>`的一部分，它使用容器的`push_back`方法。

## 10.9

> 实现你自己的elimDups。测试你的程序，分别在读取输入后、调用unique后以及调用erase后打印vector的内容。

[ex10_9.cpp](ex10_9.cpp)

## 10.10

> 你认为算法不改变容器大小的原因是什么？

因为要做到泛用性，算法不直接作用于容器，而是作用于迭代器。如此，苏阿帆和容器就可以在层面上进行分离。

## 10.11

> 编写程序，使用stable_sort和isShorter将传递给你的elimDups版本的vector排序。打印vector的内容，验证你的程序的正确性。

[ex10_11.cpp](ex10_11.cpp)

## 10.12

> 编写名为compareIsbn的函数，比较两个Sales_data对象的isbn()成员。使用这个函数排序一个保存Sales_data对象的vector。

```cpp
bool compareIsbn(const Sales_data &d1, const Sales_data& d2)
{
    return d1.isbn().size() < d2.isbn().size(); 
}

Sales_data d1("aa"), d2("aaa"), d3("a");
vector<Sales_data> v{d1, d2, d3};
stable_sort(v.begin(), v.end(), compareIsbn);
```

## 10.13

> 标准库定义了名为partition的算法，它接受一个谓词，对容器内容进行划分，使得谓词为true的值会排在容器的前半部分，而使谓词为false的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为true的元素之后的位置。编写函数，接受一个string，返回一个bool值，指出string是否有5个或更多字符。使用此函数划分words。打印出长度大于等于5的元素。

```cpp
bool isEnoughLen(const std::string &s)
{
    return s.size() >= 5;
}
vector<string> v{"a", "aaa", "aaaaa", "aaaaaaaa"};
auto iter = partition(v.begin(), v.end(), isEnoughLen);
for(auto it = v.begin(); it != iter; ++it)
{
    cout << *it << " ";
}
cout << endl;
```

## 10.14

> 编写一个lambda，接受两个int，返回它们的和。

```cpp
auto sum = [](int a, int b){return a + b;}
```

## 10.15

> 编写一个lambda，捕获它所在函数的int， 并接受一个int参数。lambda应该返回捕获的int和int参数的和。

```cpp
void func()
{
    int a = 0;
  	auto sum = [a](int n){ return a + n; }
}
```

## 10.16

> 使用lambda编写你自己版本的biggies。

```cpp
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
  	stable_sort(words.begin(),words.end(),[](const string& lhs, const string& rhs){return lhs.size() < rhs.size();});
  	
  	auto wc = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() >= sz;});
  	
  	for_each(wc, words.end(), [](const string &s){ cout << s << " ";});
  	cout << endl;	
}
```

## 10.17

> 重写10.3.1练习10.12的程序，在对sort的调用中使用lambda来代替函数compareIsbn。

```cpp
Sales_data d1("aa"), d2("aaa"), d3("a");
vector<Sales_data> v{d1, d2, d3};
stable_sort(v.begin(), v.end(), [](const string& lhs, const string& rhs){ return lhs.isbn().size() < rhs.isbn().size();});
```

## 10.18

> 重写biggies，用partition代替find_if。我们在10.3.1节练习10.13中介绍了partition算法。

```cpp
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
  
  	auto wc = partition(words.begin(), words.end(), [sz](const string &a){return a.size() >= sz;});
  	
  	for_each(wc, words.end(), [](const string &s){ cout << s << " ";});
  	cout << endl;	
}
```

## 10.19

> 用stable_partition重写前一题的程序，与stable_sort类似，在划分后的序列中维持原有元素的顺序。

```cpp
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
  
  	auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a){return a.size() >= sz;});
  	
  	for_each(wc, words.end(), [](const string &s){ cout << s << " ";});
  	cout << endl;	
}
```

## 10.20

> 标准库定义了一个名为count_if的算法。类似find_if，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。count_if返回一个计数值，表示谓词有多少次为真。使用count_if重写我们程序中统计有多少单词长度超过6的部分。

```cpp
vector<string> v{"a", "aaa", "aaaaa", "aaaaaaaa"};
auto count = count_if(v.begin(), v.end(), [](string const &s){return s.size() > 6;});
cout << count << endl;
```

## 10.21

> 编写一个lambda，捕获一个局部int变量，并递减变量值，直至它变为0。一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指出捕获的变量是否为0。

[10_21.cpp](10_21.cpp)

## 10.22

> 重写统计长度小于等于6的单词数量的程序，使用函数代替lambda。

```cpp
bool isEnoughLess(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

count_if(v.cbegin(), v.cend(), bind(isEnoughLess, _1, 6));
```

## 10.23

> bind接受几个参数？

绑定的函数参数个数+1。1是绑定的函数本体。

## 10.24

> 给定一个string，使用bind和check_size在一个int的vector中查找第一个大于string长度的值。

[ex10_24.cpp](ex10_24.cpp)

## 10.25

> 在10.3.2节的练习中，编写了一个使用partition的biggies版本。使用check_size和bind重写此函数。

```cpp
bool isEnoughLen(const string& str, vector<string>::size_type sz)
{
    return str.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
  
  	auto wc = partition(words.begin(), words.end(), bind(isEnoughLen, _1, sz));
  	
  	for_each(wc, words.end(), [](const string &s){ cout << s << " ";});
  	cout << endl;	
}
```

## 10.26

> 解释三种插入迭代器的不同之处。

back_inserter使用push_back，front_inserter使用push_front，inserter使用insert。

## 10.27

> 除了unique之外，标准库还定义了名为unique_copy的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中。

[ex10_27.cpp](ex10_27.cpp)

## 10.28

> 一个vector中保存1到9，将其拷贝到三个其他容器中。分别使用inserter、back_inserter和front_inserter将元素添加到三个容器中。对每种inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。

inserter和front_inserter的输出应该是逆序的，back_inserter是顺序的。

[ex10_28.cpp](ex10_28.cpp)

## 10.29

> 编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里。

[ex10_29.cpp](ex10_29.cpp)

## 10.30

> 使用流迭代器、sort和copy从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。

[ex10_30.cpp](ex10_30.cpp)

## 10.31

> 修改前一题的程序，使其只打印不重复的元素。你的程序应使用unique_copy。

[ex10_31.cpp](ex10_31.cpp)

## 10.32

> 重写1.6节中的书店程序，使用一个vector保存交易记录，使用不同算法完成处理。使用sort和10.3.1节中的compareIsbn函数来排序交易记录，然后使用find和accumulate求和。

略

## 10.33

> 编写程序，接收三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用istream_iterator读取输入文件。使用ostream_iterator将奇数写入第一个输出文件，每个值之后都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。

[ex10_33.cpp](ex10_33.cpp)

## 10.34

> 使用reverse_iterator逆序打印一个vector。

```cpp
vector<int> v{1,2,3,4,5};
for(auto iter = v.crbegin(); iter != v.crend(); ++iter)
  	cout << *iter << " ";
cout << endl;
```

## 10.35

> 使用普通迭代器逆序打印一个vector。

```cpp
vector<int> v{1,2,3,4,5};
for(auto iter = prev(cve.cend());;--iter){
    cout << *iter << " ";
  	if(iter == v.cbegin())
      	break;
}
cout << endl;
```

## 10.36

> 使用find在一个int的list中查找最后一个值为0的元素。

```cpp
list<int> lst{1,2,3,4,5,6,7,8,9,0,1,2,3,4};
auto it = find(lst.crbegin(), lst.crend(), 0);
```

## 10.37

> 给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中。

```cpp
vector<int> v{1,2,3,4,5,6,7,8,9,10};
list<int> lst;
copy(v.rbegin()+3, v.rbegin()+8, back_inserter(lst));
```

## 10.38

> 列出5个迭代器类别，以及每类迭代器所支持的操作。

- 输入迭代器：
  - ==、!=
  - 前置和后置++
  - *，只出现在赋值运算符的右侧
  - ->
- 输出迭代器
  - 前置和后置++
  - *只出现在赋值运算符的左侧
- 前向迭代器
  - 可读写，只能在序列中沿一个方向移动。
  - 支持所有输入和输出迭代器的操作。
- 双向迭代器
  - 可正向/反向读写序列中的元素。
  - 支持前向迭代器所有操作。
  - 还支持前置和后置--
- 随机访问迭代器
  - 提供常量时间内访问序列中任意元素的能力。
  - 支持双向迭代器的所有操作。
  - <、<=、>和>=
  - +、+=、-和-=，只能用于整数值
  - 两个迭代器之间可以-
  - 支持下标访问[]

## 10.39

> list上的迭代器属于哪类？vector呢？

list是双向迭代器，因为是双链表，支持--。

vector是随机访问迭代器，因为连续存储，支持随机访问。

## 10.40

> 你认为copy要求哪类迭代器？reverse和unique呢？

copy的前两个要求输入迭代器，最后一个要求输出迭代器。

reverse要求双向迭代器。

unique要求前向迭代器。

## 10.41

> 仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：
>
> ```cpp
> replace(beg, end, old_val, new_val);
> replace_if(beg, end, pred, new_val);
> replace_copy(beg, end, dest, old_val, new_val);
> replace_copy_if(beg, end, dest, pred, new_val);
> ```

```cpp
//beg到end之间，把old_val值的元素替换为new_val
replace(beg, end, old_val, new_val);
//beg到end之间，如果应用pred返回true，则替换为new_val
replace_if(beg, end, pred, new_val);
//beg到end之间，把值为old_val的元素改为new_val，拷贝到dest开始的容器中，本体不受影响
replace_copy(beg, end, dest, old_val, new_val);
//beg到end之间，把应用dest返回true的元素替换为new_val拷贝到dest开始的容器中，本体不受影响
replace_copy_if(beg, end, dest, pred, new_val);
```

## 10.42

> 使用list代替vector重新实现10.2.3节中的去除重复单词的程序。

[ex10_42.cpp](ex10_42.cpp)