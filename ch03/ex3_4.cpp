#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
    string str1, str2;

    cin >> str1 >> str2;
    if(str1 == str2)
    {
        cout << "str1 equals str2. str: " << str1 << endl;
    }
    else if(str1 < str2)
    {
        cout << "str1 is less than str2. str2 is " << str2 << endl; 
    }
    else
    {
        cout << "str2 is less than str1. str1 is " << str1 << endl;
    }

    if(str1.size() == str2.size())
    {
        cout << "str1's length equals str2's." << endl;
    }
    else if(str1.size() < str2.size())
    {
        cout << "str1 is shorter than str2, str2: " << str2 << endl;
    }
    else 
    {
        cout << "str2 is shorter than str1, str1: " << str1 << endl;
    }

}