#include <iostream>
#include <string>
#include <map> 
#include <functional> 

using std::string; using std::map;
using std::function;

int add(int i, int j){ return i + j;}
struct Div{
    int operator()(int i, int j) const { return i / j;}
};
auto mod = [](int i, int j){return i % j;};
map<string, function<int (int, int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", [](int i, int j){ return i * j;}},
    {"/", Div()},
    {"%", mod}
};

map<string, function<int (int, int)>> binOps = {
    {"+", std::plus<int>()},
    {"-", std::minus<int>()},
    {"*", std::multiplies<int>()},
    {"/", std::divides<int>()},
    {"%", std::modulus<int>()}
};

int main()
{
    while(std::cout << "Pls enter as: num operator num:\n", true)
    {
        int lhs, rhs; std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << binops[op](lhs, rhs) << std::endl;
    }
    return 0;
}