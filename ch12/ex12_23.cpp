#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using std::cout; using std::endl;
using std::string;

int main()
{
    char str1[] = "hello ";
    char str2[] = "world";
    char *pstr = new char[strlen(str1)+strlen(str2)+1];
    strcpy(pstr, str1);
    strcat(pstr, str2);

    string s1 = "hello ";
    string s2 = "world";
    string s = s1 + s2;
    cout << pstr << endl;
    cout << s << endl;
    return 0;
}