#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
    int size;
    cout << "Input the size of string ahead:" << endl;
    cin >> size;

    char *pstr = new char[size+1]();
    cout << "Input the string:" << endl;
    cin >> pstr;
    cout << pstr << endl;
    delete[] pstr;
    return 0;
}