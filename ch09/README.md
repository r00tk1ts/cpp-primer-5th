## 9.1

> 对于下面的程序任务，vector、deque和list哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
>
> (a)读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
>
> (b)读取未知数量的单词，总是将新单词插入到末尾。删除操作在头部进行。
>
> (c)从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

(a)关联容器set更好，这里只能勉强用list。

(b)deque，因为是双端操作。

(c)vector，数量未知且无需中间插入删除操作，vector最好。

## 9.2

> 定义一个list对象，其元素类型是int的deque。

`std::list<std::deque<int>> ls;`

## 9.3

> 构成迭代器范围的迭代器有何限制？

对begin和end来说，它们需要指向同一个容器的元素。begin的自增操作可以最终到达end指涉的位置。

## 9.4

> 编写函数，接受一对指向`vector<int>`的迭代器和一个int值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

```cpp
bool func(std::vector<int>::const_iterator cbegin, std::vector<int>::const_iterator cend, int n)
{
    for(;cbegin != cend; ++cbegin)
    {
        if(*cbegin == n)
          	return true;
    }
  	return false;
}
```

## 9.5

> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

```cpp
std::vector<int>::iterator func(std::vector<int>::const_iterator cbegin, std::vector<int>::const_iterator cend, int n)
{
    for(;cbegin != cend; ++cbegin)
    {
        if(*cbegin == n)
          	return cbegin;
    }
  	return cend;
}
```

## 9.6

> 下面程序有何错误？你应该如何修改它？
>
> ```cpp
> list<int> lst1;
> list<int>::iterator iter1 = lst1.begin(),
> 	iter2 = lst1.end();
> while(iter1 < iter2)/* ... */
> ```

`std::list<T>::iterator`不支持`<`运算符（因为双向链表的元素地址不连续，地址并不一定是按逻辑顺序递增的），要使用`!=`。

改为：`while(iter1 != iter2)`。

## 9.7

> 为了索引int的vector中的元素，应该使用什么类型？

`std::vector<int>::size_type`

## 9.8

> 为了读取string的list中的元素，应该使用什么类型？如果写入list，又该使用什么类型？

`std::list<string>::const_iterator`

`std::list<string>::iterator`

## 9.9

> begin和cbegin两个函数有什么不同？

前者返回iterator类型，后者返回const_iterator类型。

## 9.10

> 下面4个对象分别是什么类型？
>
> ```cpp
> vector<int> v1;
> const vector<int> v2;
> auto it1 = v1.begin(), it2 = v2.begin();
> auto it3 = v1.cbegin(), it4 = v2.cbegin();
> ```

分别是`vector<int>::iterator`, `vector<int>::const_iterator`, `vector<int>::const_iterator`和`vector<int>::const_iterator`。

后三个一致，另外it1和it2不能使用一个auto来定义，二者类型不一致所以要拆开，这是实例代码的一个错误。

## 9.11

> 对6种创建和初始化vector对象的方法，每一种都给出一个实例。解释每个vector包含什么值。

```cpp
vector<int> v1;		//空的vector
vector<int> v2(v1);	//空的vector
vector<int> v3 = v1;	//空的vector
vector<int> v4{10, 3};	//2个元素，分别是10和3
vector<int> v5 = {10, 3};	//2个元素，分别是10和3
vector<int> v6(v5.begin(), v5.end());	//2个元素，分别是10和3

//顺序容器提供的额外两种构造器
vector<int> v7(10);		//10个值为0（值初始化）的vector
vector<int> v8(10, 3);	//10个值为3的vector
```

## 9.12

> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

前者必须保证容器类型和元素类型是一致的，才能够拷贝所有的元素到容器中。

后者不需要容器类型的一致，只需要元素类型是一致的即可，这一特性提供了从不同容器拷贝的可能性。

## 9.13

> 如何从一个`list<int>`初始化一个`vector<double>`？从一个`vector<int>`又该如何创建？编写代码验证你的答案。

```cpp
list<int> lst{1,3,5};
vector<double> dvec1(lst.begin(), lst.end());

vector<int> ivc{2,4,6};
vector<double> dvec2(ivc.begin(), ivc.end());
```

## 9.14

> 编写程序，将一个list中的char*指针（指向C风格字符串）元素赋值给一个vector中的string。

```cpp
vector<string> vec;
list<const char*> lst{"hello","world"};
vec.assign(lst.cbegin(), lst.cend());
```

assign允许拷贝类型不同但相容的容器元素。

## 9.15

> 编写程序，判定两个`vector<int>`是否相等。

```cpp
vector<int> v1{1,3,5}, v2{2,4,6};
cout << (v1 == v2 ? "true" : "false") << endl;
```

## 9.16

> 重写上一题的程序，比较一个`list<int>`中的元素和一个`vector<int>`中的元素。

```cpp
vector<int> v{1,3,5};
list<int> lst{1,3,5};
vector<int> temp(lst.begin(),lst.end());
cout << (v == temp ? "true" : "false") << endl;
```

## 9.17

> 假定c1和c2是两个容器，下面的比较操作有何限制（如果有的话）？
>
> `if(c1 < c2)`

这种比较必须基于c1和c2是同种型别的容器，另外，所持元素也必须支持`<`运算符。另外，无序关联容器是不能这样比较的（毕竟无序，怎么比。。。）。

## 9.18

> 编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。

```cpp
string str;
deque<string> deq;
while(cin >> str)
{
    deq.push_back(str);
}
for(deque<string>::const_iterator cbegin = deq.cbegin(), deque<string>::const_iterator cend = deq.cend();cbegin != cend; ++cbegin)
{
    cout << *cbegin << " ";
}
cout << endl;
```

## 9.19

> 重写上题的程序，用list替代deque。列出程序要做出哪些改变。

```cpp
string str;
list<string> lst;
while(cin >> str)
{
    lst.push_back(str);
}
for(auto cbegin = lst.cbegin(), lst = deq.cend(); cbegin != cend; ++cbegin)
{
    cout << *cbegin << " ";
}
cout << endl;
```

还能改变啥，改变容器型别。

## 9.20

> 编写程序，从一个`list<int>`拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。

```cpp
list<int> lst{1,2,3,4,5,6};
deque<int> odd, even;

for(auto cbegin = lst.cbegin(); cbegin != lst.cend(); ++cbegin)
{
    if(*cbegin % 2)
      	odd.push_back(*cbegin);
  	else
      	even.push_back(*cbegin);
}
```

## 9.21

> 如果我们将第308页中使用insert返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。

因为vector是连续存储的，每次插入都要把后面的元素全部向后移位一个单位（在未引起vector体积膨胀的情况下），没有list那么高效，但效果上是一致的。

## 9.22

> 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
>
> ```cpp
> vector<int>::iterator iter = iv.begin(), 
> 	mid = iv.begin() + iv.size()/2;
> while( iter != mid)
>   	if(*iter == some_val)
>       	iv.insert(iter, 2 * some_val);
> ```

循环永远不会终止，另外mid在insert之后会失效。

```cpp
for(auto begin = iv.begin(); begin != iv.begin()+iv.size()/2;++begin)
{
    if(*begin == some_val)
      	++(begin = v.insert(begin, 2 * some_val));
}
```

## 9.23

> 在本节第一个程序中，若c.size()为1，则val、val2、val3和val4的值会是什么？

四个值都是第一个元素的值。

## 9.24

> 编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。在一个空vector上测试你的程序。

[ex9_24.cpp](ex9_24.cpp)

## 9.25

> 对于第312页中删除一个范围内的元素的程序，如果elem1与elem2相等会发生什么？如果elem2是尾后迭代器，或者elem1和elem2皆为尾后迭代器，又会发生什么？

相等则什么都不会发生。如果elem2是尾后迭代器，会删除elem1到包括最后一个元素之间的所有元素，如果elem1和elem2都是尾后迭代器，也什么都不会发生。

## 9.26

> 使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。
>
> `int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};`

[ex9_26.cpp](ex9_26.cpp)

## 9.27

> 编写程序，查找并删除`forward_list<int>`中的奇数元素。

[ex9_27.cpp](ex9_27.cpp)

## 9.28

> 编写函数，接受一个`forward_list<string>`和两个string共三个参数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾。

```cpp
void func(forward_list<string> &flst, string &first, string &second)
{
  	auto prev = flst.before_begin();
    for(auto curr = flst.begin(); curr != flst.end(); prev = curr++)
    {
        if(*curr == first)
        {
            flst.insert_after(curr, second);
          	return ;
        }
    }
  	flst.insert_after(prev, second);
}
```

## 9.29

> 假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？

vec会增加75个元素，该75个元素被值初始化。接下来会丢弃后90个元素，仅保留前10个元素。

## 9.30

> 接受单个参数的resize版本对元素类型有什么限制（如果有的话）？

如果类型是类类型，则必须要有默认构造函数。

## 9.31

> 第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。为什么？修改程序，使之也能用于这些类型。

list的迭代器不支持+=操作符，它是一个forward型迭代器，而不是random access型，所以要小改一下：

```cpp
list<int> lst = {0,1,2,3,4,5,6,7,8,9};
auto iter = lst.begin();
while(iter != lst.end()){
    if(*iter % 2){
        iter = lst.insert(iter, *iter);
      	++iter;++iter;
    }else{
        iter = vi.erase(iter);
    }
}
```

而forward_list不支持insert和erase。

```cpp
forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
auto iter = flst.begin();
auto prev = flst.before_begin();
while(iter != flst.end()){
    if(*iter % 2){
        prev = flst.insert_after(iter, *iter);
      	fiter = prev;iter++;
    }else{
        iter = flst.erase_after(prev);
    }
}
```

## 9.32

> 在第316页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？
>
> `iter = vi.insert(iter, *iter++);`

合法，此时`iter += 2`需要改为`iter++`。因为最后的++会在整条语句执行后生效，iter最终为vi.insert所返回+1的位置。

## 9.33

> 在本节最后一个例子中，如果不将insert的结果赋予begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

begin会失效。行为未定义。对vector来说是灾难，程序会崩溃，对list来说结果有问题。

这种用法是完全错误的，不能依赖于底层实现而滥用。

## 9.34

> 假定vi是一个保存int的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
>
> ```cpp
> iter = vi.begin();
> while(iter != vi.end())
>   	if(*iter % 2)
>       	iter = vi.insert(iter, *iter);
> 	++iter;
> ```

无限循环，因为++iter不在while循环内。。。

感觉这个题不是想考这个坑，加上大括号。

```cpp
iter = vi.begin();
while(iter != vi.end()){
  	if(*iter % 2)
      	iter = vi.insert(iter, *iter);
	++iter;
}
```

应该是每个奇数值前插入一个相同的数。

## 9.35

> 解释一个vector的capacity和size有何区别。

size是当前所持元素的个数，capacity是当前的最大容量上限，一旦超过了该值，则体积膨胀。

## 9.36

> 一个容器的capacity可能小于它的size吗？

不可能。

## 9.37

> 为什么list或array没有capacity成员函数？

list并不是连续存储元素的，无所谓capacity的概念，它是个双链表。

array有固定尺寸，size足矣，capacity没有必要。

## 9.38

> 编写程序，探究在你的标准库实现中，vector是如何增长的。

[ex9_38.cpp](ex9_38.cpp)

这个要看标准库的具体实现，比如先根据初始成员给出一个大小，超过capacity以后，按2倍体积扩充。

## 9.39

> 解释下面程序片段做了什么：
>
> ```cpp
> vector<string> svec;
> svec.reserve(1024);
> string word;
> while(cin >> word)
>   	svec.push_back(word);
> svec.resize(svec.size() + svec.size()/2);
> ```

先预留1024个元素的空间，然后从cin循环读入string置入svec，即使超过了1024个，svec也会自己膨胀。

resize与reserve不同，这里resize是增加了当前svec一半元素个数的值初始化string(空串)，如果超出了capacity，svec也会自动膨胀。

## 9.40

> 如果上一题中的程序读入了256个词，在resize之后容器的capacity可能是多少？如果读入512个、1000个或1048个词呢？

| read | size | capacity            |
| ---- | ---- | ------------------- |
| 256  | 384  | 1024                |
| 512  | 768  | 1024                |
| 1000 | 1500 | 2000(clang is 2048) |
| 1048 | 1572 | 2048                |

## 9.41

> 编写程序，从一个`vector<char>`初始化一个string。

```cpp
vector<char> v{'H','e','l','l','o'};
string str(v.cbegin(), v.cend());
```

## 9.42

> 假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？

使用`string str; str.reserve(100);`

## 9.43

> 编写一个函数，接受三个string参数s、oldVal和newVal。使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用它替换通用的间写形式，如，将"tho"替换为"though"，将"thru"替换为"through"。

[ex9_43.cpp](ex9_43.cpp)

## 9.44

> 重写上一题的函数，这次使用一个下标和replace。

[ex9_44.cpp](ex9_44.cpp)

## 9.45

> 编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如"Mr."或"Ms."）和后缀（如"Jr."或"III"）的字符串。使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。

```cpp
string func(string name, const string& pre, const string& suf)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
  	name.append(suf.cbegin(), suf.cend());
  	return name;
}
```

## 9.46

> 重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。

```cpp
string func(string name, const string& pre, const string& suf)
{
  	name.insert(0, pre);
  	name.insert(name.size(), suf);
  	return name;
}
```

## 9.47

> 编写程序，首先查找string "ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。

[ex9_47.cpp](ex9_47.cpp)

## 9.48

> 假定name和numbers的定义如325页所示，`numbers.find(name)`返回什么？

`string::npos`

## 9.49

> 如果一个字母延伸到中线之上，如d或f，则称其有上出头部分(ascender)。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分(descender)。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。

[ex9_49.cpp](ex9_49.cpp)

## 9.50

> 编写程序处理一个`vector<string>`，其元素都表示整型值。计算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和。

[ex9_50.cpp](ex9_50.cpp)

## 9.51

> 设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数。你的构造函数应该能处理不同数据格式，如January 1, 1900、1/1/1900、Jan 1 1900等。



[ex9_51.cpp](ex9_51.cpp)

## 9.52

> 使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的(子)表达式已经处理完毕，被其运算结果所替代。

这题中文简直翻译的乱七八糟。。。看英文吧：

>When you see an open parenthesis, note that it was seen. 
>When you see a close parenthesis after an open parenthesis, pop elements down to and including the open parenthesis off the stack. Push a value onto the stack to indicate that a parenthesized expression was replaced. 

这题描述也是诡异，不懂要干什么，随便写一写吧。

[ex9_52.cpp](ex9_52.cpp)

