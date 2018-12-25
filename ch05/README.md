## 5.1

> 什么是空语句？什么时候会用到空语句？

`;	//空语句`

循环体无内容时常用空语句。

## 5.2

> 什么是块？什么时候会用到块？

花括号包起来一条或多条语句视为一个块。

## 5.3

> 使用逗号运算符重写1.4.1节的while循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。

```cpp
while(val <= 10)
  	sum += val, ++val;
```

可读性降低了。

## 5.4

> 说明下列例子的含义，如果存在问题，试着修改它。
>
> (a)`while(string::iterator iter != s.end()){ /* ... */}`
>
> (b)
>
> ```cpp
> while(bool status = find(word)){/* ... */}
> 	if(!status) {/* ... */}
> ```



(a)迷之操作，改为:

```cpp
string::iterator iter = s.begin();
while(iter != s.end()){ /* ... */ }
```

(b)if中不认识status变量：

```cpp
while(bool status = find(word))
{
    if(!status)
    {
        /* ... */
    }
}
```

## 5.5

> 写一段自己的程序，使用if else语句实现把数字成绩转换成字母成绩的要求。

[ex5_5.cpp](ex5_5.cpp)

## 5.6

> 改写上一题的程序，使用条件运算符代替if else语句。

[ex5_6.cpp](ex5_6.cpp)

## 5.7

> 改正下列代码段中的错误。
>
> (a)
>
> ```cpp
> if(ival1 != ival2)
>   	ival1 = ival2
> else
> 	ival1 = ival2 = 0;
> ```
>
> (b)
>
> ```cpp
> if(ival < minval)
>   	minval = ival;
> 	occurs = 1;
> ```
>
> (c)
>
> ```cpp
> if(int ival = get_value())
>   	cout << "ival = " << ival << endl;
> if(!ival)
>   	cout << "ival = 0\n";
> ```
>
> (d)
>
> ```cpp
> if(ival = 0)
>   	ival = get_value();
> ```

(a)

```cpp
if(ival1 != ival2)
  	ival1 = ival2;
else
	ival1 = ival2 = 0;
```

(b)

```cpp
if(ival < minval)
{
  	minval = ival;
	occurs = 1;
}
```

(c)

```cpp
if(int ival = get_value())
  	cout << "ival = " << ival << endl;
else if(!ival)
  	cout << "ival = 0\n";
```

(d)

```cpp
if(ival == 0)
  	ival = get_value();
```

## 5.8

> 什么是“悬垂else”？C++语言是如何处理else子句的？

嵌套的if可能会导致if分支多于else分支，用于处理多个条件分支。C++的else总是匹配最近的那个if。

## 5.9

> 编写一段程序，使用一系列if语句统计从cin读入的文本有多少元音字母。

[ex5_9.cpp](ex5_9.cpp)

## 5.10

> 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以次类推。

[ex5_10.cpp](ex5_10.cpp)

## 5.11

> 修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。

[ex5_11.cpp](ex5_11.cpp)

## 5.12

> 修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff、fl和fi。

[ex5_12.cpp](ex5_12.cpp)

## 5.13

> 下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
>
> (a)
>
> ```cpp
> unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
> char ch = next_text();
> switch(ch){
>   case 'a': aCnt++;
>   case 'e': eCnt++;
>   default: iouCnt++;
> }
> ```
>
> (b)
>
> ```cpp
> unsigned index = some_value();
> switch(index){
>   case 1:
>     	int ix = get_value();
>     	ivec[ix] = index;
>     	break;
>   default:
>     	ix = ivec.size()-1;
>     	ivec[ix] = index;
> }
> ```
>
> (c)
>
> ```cpp
> unsigned evenCnt = 0, oddCnt = 0;
> int digit = get_num() % 10;
> switch(digit){
>   case 1,3,5,7,9:
>     	oddcnt++;
>     	break;
>   case 2,4,6,8,10:
>     	evenCnt++;
>     	break;
> }
> ```
>
> (d)
>
> ```cpp
> unsigned ival = 512, jval = 1024, kval = 4096;
> unsigned bufsize;
> unsigned swt = get_bufCnt();
> switch(swt){
>   case ival:
>     	bufsize = ival * sizeof(int);
>    		break;
>   case jval:
>     	bufsize = jval * sizeof(int);
>     	break;
>   case kval:
>     	bufsize = kval * sizeof(int);
>     	break;
> }
> ```

(a)

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch(ch){
  case 'a': aCnt++;break;
  case 'e': eCnt++;break;
  default: iouCnt++;break;
}
```

(b)

```cpp
unsigned index = some_value();
int ix;
switch(index){
  case 1:
    	ix = get_value();
    	ivec[ix] = index;
    	break;
  default:
    	ix = ivec.size()-1;
    	ivec[ix] = index;
}
```

(c)

```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch(digit){
  case 1:
  case 3:
  case 5:
  case 7:
  case 9:
    	oddcnt++;
    	break;
  case 2:
  case 4:
  case 6:
  case 8:
  case 10:
    	evenCnt++;
    	break;
}
```

(d)

```cpp
const unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt){
  case ival:
    	bufsize = ival * sizeof(int);
   		break;
  case jval:
    	bufsize = jval * sizeof(int);
    	break;
  case kval:
    	bufsize = kval * sizeof(int);
    	break;
}
```

## 5.14

> 编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如，如果输入时
>
> ​	how now now now brown cow cow
>
> 那么输出应该标明单词now连续出现了3次。

[ex5.14.cpp](ex5_14.cpp)

## 5.15

> 说明下列循环的含义并改正其中的错误。
>
> (a)
>
> ```cpp
> for(int ix = 0; ix != sz; ++ix) { /* ... */ }
> if(ix != sz)
>   	// ...
> ```
>
> (b)
>
> ```cpp
> int ix;
> for(ix != sz; ++ix) { /* ... */ }
> ```
>
> (c)
>
> ```cpp
> for(int ix=0; ix!=sz; ++ix, ++sz) { /* ... */ }
> ```



(a)

```cpp
int ix;
for(ix = 0; ix != sz; ++ix) { /* ... */ }
if(ix != sz)
  	// ...
```

(b)

```cpp
int ix;
for(;ix != sz; ++ix) { /* ... */ }
```

(c)

```cpp
for(int ix=0; ix!=sz; ++ix) { /* ... */ }
```

## 5.16

> while循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for循环则更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯用法各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于使用哪种呢？为什么？

for一般是事先明确范围，while则对不清楚范围的情况非常契合。具体使用哪一个要取决于具体环境。

## 5.17

> 假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0、1、1、2和0、1、1、2、3、5、8，则程序的返回结果应该为真。

[ex5_17.cpp](ex5_17.cpp)

## 5.18

> 说明下列循环的含义并改正其中的错误。
>
> (a)
>
> ```cpp
> do
>   	int v1, v2;
> 	cout << "Please enter two numbers to sum:";
> 	if(cin >> v1 >> v2)
>       	cout << "Sum is: " << v1 + v2 << endl;
> while(cin);
> ```
>
> (b)
>
> ```cpp
> do{
>     // ...
> }while(int ival = get_response());
> ```
>
> (c)
>
> ```cpp
> do{
>     int ival = get_response();
> }while(ival);
> ```

(a)

```cpp
do{
  	int v1, v2;
	cout << "Please enter two numbers to sum:";
	if(cin >> v1 >> v2)
      	cout << "Sum is: " << v1 + v2 << endl;
}while(cin);
```

(b)

```cpp
int ival;
do{
    // ...
}while(ival = get_response());
```

(c)

```cpp
int ival;
do{
   ival = get_response();
}while(ival);
```

## 5.19

> 编写一段程序，使用do while循环重复地执行下述任务：首先提示用户输入两个string对象，然后挑出较短的那个并输出它。

[ex5_19.cpp](ex5_19.cpp)

## 5.20

> 编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。

[ex5_20.cpp](ex5_20.cpp)

## 5.21

> 修改5.5.1节练习题的程序，使其找到的重复单词必须以大写字母开头。

[ex5_21.cpp](ex5_21.cpp)

## 5.22

> 本节的最后一个例子跳回到begin，其实使用循环能更好地完成该任务。重写这段代码，注意不再使用goto语句。 

```cpp
int sz;
while((sz = get_size()) <= 0);
```

## 5.23

> 编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。

[ex5_23.cpp](ex5_23.cpp)

## 5.24

> 修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？

[ex5_24.cpp](ex5_24.cpp)

## 5.25

> 修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。

[ex5_25.cpp](ex5_25.cpp)

