#include <iostream>
#include <string>
#include <cstring>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
    char s1[] = "hello";
    char s2[] = "world";
    if(!strcmp(s1, s2))
        cout << "s1 equals s2." << endl;
    else
        cout << "s1 doesn't equals s2." << endl;

    string str1("hello");
    string str2("world");
    if(str1 == str2)
        cout << "str1 equals str2." << endl;
    else
        cout << "str1 doesn't equals s2." << endl;
    return 0;
}
