## 8.1

> 编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

```cpp
std::istream& func(std::istream &is)
{
    std::string str;
  	while(is >> str)
      	std::cout << str << std::endl;
  	is.clear();
  	return is;
}
```

## 8.2

> 测试函数，调用参数为cin。

[ex8_2.cpp](ex8_2.cpp)

## 8.3

> 什么情况下，下面的while循环会终止？
>
> `while(cin >> i)/* ... */`

cin变成错误状态时while会终止，比如因读入内容而导致的`eofbit`,`failbit`,`badbit`被置位。

## 8.4

> 编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。

```cpp
void read2vec(const string &filename, vector<string>& vec)
{
    ifstream ifs(filename);
  	if(ifs)
    {
        string buf;
      	while(std::getline(ifs, buf))
          	vec.push_back(buf);
    }
}
```

## 8.5

> 重写上面的程序，将每个单词作为一个独立的元素进行存储。

```cpp
void read2vec(const string &filename, vector<string>& vec)
{
    ifstream ifs(filename);
  	if(ifs)
    {
        string buf;
      	while(ifs >> buf)
          	vec.push_back(buf);
    }
}
```

## 8.6

> 重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给main。

[ex8_6.cpp](ex8_6.cpp)

## 8.7

> 修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。

[ex8_7.cpp](ex8_7.cpp)

## 8.8

> 修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。

[ex8_8.cpp](ex8_8.cpp)

## 8.9

> 使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。

[ex8_9.cpp](ex8_9.cpp)

## 8.10

编写程序，将来自一个文件中的行保存在一个`vector<string>`中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。

[ex8_10.cpp](ex8_10.cpp)

## 8.11

> 本节的程序在外层while循环中定义了istringstream对象。如果record对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将record的定义移到while循环之外，验证你设想的修改方法是否正确。

```cpp
struct PersonInfo{
    string name;
  	vector<string> phones;
};

string line, word;
vector<PersonInfo> people;
istringstream record;
while(getline(cin, line)){
    PersonInfo info;
  	record.clear();
  	record.str(line);
  	record >> info.name;
  	while(record >> word)
      	info.phones.push_back(word);
  	people.push_back(info);
}
```

## 8.12

> 我们为什么没有在PersonInfo中使用类内初始化？

因为PersonInfo被设计成聚合类，聚合类不能进行类内初始化。

## 8.13

> 重写本节的电话号码程序，从一个命名文件而非cin读取数据。

[ex8_13.cpp](ex8_13.cpp)

## 8.14

> 我们为什么将entry和nums定义为const auto&？

引用是因为auto推导会忽略引用，而对非内置类型来说，引用效率比值拷贝更高，所以要加&。const是因为我们不希望修改它们的值。