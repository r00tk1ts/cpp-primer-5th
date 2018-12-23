#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
    string str{"Hello, world"};
    decltype(str.size()) i = 0;

    for(i=0;i<str.size();++i)
    {
        str[i] = 'X';
    }
    cout << str << endl;
    i = 0;
    while(i<str.size())
    {
        str[i++] = 'x';
    }
    cout << str << endl;
    return 0;
}