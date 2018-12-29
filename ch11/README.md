## 11.1

> 描述map和vector的不同。

map是关联容器，vector是顺序容器。map是键值对的集合，vector是单一类型元素的集合。

## 11.2

> 分别给出最适合使用list、vector、deque、map以及set的例子。

需要双链表就用list，需要动态数组就用vector，需要双端队列就用deque，需要字典就用map，需要有序集就用set。

## 11.3

> 编写你自己的单词计数程序。

[ex11_3.cpp](ex11_3.cpp)

## 11.4

> 扩展你的程序，忽略大小写和标点。例如，"example."

[ex11_4.cpp](ex11_4.cpp)

## 11.5

> 解释map和set的区别。你如何选择使用哪个？

map是字典，存储键值对，set是集合，只有一个维度。

[A nice answer on SO](http://stackoverflow.com/questions/16286714/advantages-of-stdset-vs-vectors-or-maps)

## 11.6

> 解释set和list的区别。你如何选择使用哪个？

set是字典序集合，list是双链表。

[list vs set](http://stackoverflow.com/questions/2302681/c-stl-list-vs-set)

## 11.7

> 定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子们的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

[ex11_7.cpp](ex11_7.cpp)

## 11.8

> 编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么？

[ex11_8.cpp](ex11_8.cpp)

set可以自己保证unique特性，且本身是字典序，执行效率高。

## 11.9

> 定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。

`map<string, list<size_t>> lineNo;`

## 11.10

> 可以定义一个`vector<int>::iterator`到int的map吗？`list<int>::iterator`到int的map呢？对于两种情况，如果不能，解释为什么。

`map<vector<int>::iterator, int> mv;`是可以的，因为`vector<int>::iterator`支持`<`运算符。

`map<list<int>::iterator, int> ml;`是不行的，因为`list<int>::iterator`不支持`<`运算符。

map的顺序依赖的就是键的`<`运算符，所以键类型必须支持`<`。

## 11.11

> 不使用decltype重新定义bookstore。

`multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);`

## 11.12

> 编写程序，读入string和int的序列，将每个string和int存入一个pair中，pair保存在一个vector中。

见下题。

## 11.13

> 在上一题的程序中，至少有三种创建pair的方法。编写此程序的三个版本，分别采用不同的方法创建pair。解释你认为哪种形式最易于编写和理解，为什么？

[ex11_13.cpp](ex11_13.cpp)

## 11.14

> 扩展你在11.2.1节练习中编写的孩子姓到名的map，添加一个pair的vector，保存孩子的名和生日。

[ex11_14.cpp](ex11_14.cpp)

## 11.15

> 对一个int到`vector<int>`的map，其`mapped_type`、`key_type`和`value_type`分别是什么？

`mapped_type`是`vector<int>`

`key_type`是`int`

`value_type`是`pair<const int, vector<int>>`

## 11.16

> 使用一个map迭代器编写一个表达式，将一个值赋予一个元素。

```cpp
map<string, int> m;
m["admin"] = 1;
map<string, int>::iterator it = m.begin();
m->second = 0;
```

## 11.17

> 假定c是一个string的multiset，v是一个string的vector，解释下面的调用。指出每个调用是否合法：
>
> ```cpp
> copy(v.begin(), v.end(), inserter(c, c.end()));
> copy(v.begin(), v.end(), back_inserter(c));
> copy(c.begin(), c.end(), inserter(v, v.end()));
> copy(c.begin(), c.end(), back_inserter(v));
> ```

第一个合法。

第二个不合法，map不支持push_back。

第三个合法。

第四个合法。

## 11.18

> 写出第382页循环中map_it的类型，不要使用auto或decltype。

`map<string, size_t>::const_iterator`

## 11.19

> 定义一个变量，通过对11.2.2节中的名为bookstore的multiset调用begin()来初始化这个变量。写出变量的类型，不要使用auto或decltype。

```cpp
using compareType = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
multiset<Sales_data, compareType> bookstore(compareIsbn);
multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
```

## 11.20

> 重写11.1节练习的单词计数程序，使用insert代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。

[ex11_20.cpp](ex11_20.cpp)

## 11.21

> 假定word_count是一个string到size_t的map，word是一个string，解释下面循环的作用：
>
> ```cpp
> while(cin >> word)
>   	++word_count.insert({word, 0}).first->second;
> ```

与11.20是一样的，这个写法很有灵性，把true和false的情景一起处理了。

## 11.22

> 给定一个`map<string, vector<int>>`，对此容器的插入一个元素的insert版本，写出其参数类型和返回类型。

参数类型：`pair<string, vector<int>>`

返回类型：`pair<map<string, vector<int>>::iterator, bool>`

## 11.23

> 11.2.1节练习中的map以孩子的姓为关键字，保存他们的名的vector，用multimap重写此map。

用`multimap<string, string>`就够了。

[ex11_23.cpp](ex11_23.cpp)

## 11.24

> 下面的程序完成什么功能？
>
> ```cpp
> map<int, int> m;
> m[0] = 1;
> ```

插入一个键为0,值为1的元素。

## 11.25

> 对比下面程序与上一题程序
>
> ```cpp
> vector<int> v;
> v[0] = 1;
> ```

UB，因为v是空的，索引操作可能抛出异常。

## 11.26

> 可以用什么类型来对一个map进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即，定义一个map，然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返回的类型。

下标运算符返回的类型是mapped_type。

```cpp
using KeyType = map<int, string>::key_type;
cout << "type to subscript: " << typeid(KeyType).name() << endl;
```

## 11.27

> 对于什么问题你会使用count来解决？什么时候你又会选择find呢？

multimap和multiset用count，map和set用find。

## 11.28

> 对一个string到int的vector的map，定义并初始化一个变量来保存在其上调用find所返回的结果。

`map<string, vector<int>>::iterator iter = m.find("admin");`

## 11.29

> 如果给定的关键字不在容器中，upper_bound、lower_bound和equal_range分别会返回什么？

upper_bound和lower_bound返回的是关键字的第一个安全插入点——不影响容器中元素顺序的插入位置。二者返回的是相同的迭代器。

equal_range返回的迭代器pair中first和second迭代器都指向关键字可以插入的位置。

## 11.30

> 对于本节最后一个程序中的输出表达式，解释运算对象pos.first->second的含义。

找到的第一个等于search_item键的元素的mapped_type。

## 11.31

> 编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。确保你的程序在元素不在map中时也能正常运行。

[ex11_31.cpp](ex11_31.cpp)

## 11.32

> 使用上一题定义的multimap编写一个程序，按字典序打印作者列表和它们的作品。

[ex11_32.cpp](ex11_32.cpp)

## 11.33

> 实现你自己版本的单词转换程序。

略

## 11.34

> 如果你将transform函数中的find替换为下标运算符，会发生什么情况？

编译会GG，因为const的m不能插入，m[s]在s不存在时会执行插入动作。

## 11.35

> 在buildMap中，如果进行如下改写，会有什么效果？
>
> `trans_map[key] = value.substr(1);`改为`trans_map.insert({key, value.substr(1)});`

当key已经存在时，insert不会进行插入动作。

## 11.36

> 我们的程序并没有检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包括一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。

会按空string处理，如果没有就加入{key, ""}，key如果存在就改写值为""。

## 11.37

> 一个无序容器与其有序容器版本相比有何优势？有序版本有何优势？

[A summary](http://www.cs.fsu.edu/~lacher/courses/COP4531/fall13/lectures/containers2/slide04.html)

## 11.38

> 用unordered_map重写单词计数程序和单词转换程序。

[ex11_38.cpp](ex11_38.cpp)