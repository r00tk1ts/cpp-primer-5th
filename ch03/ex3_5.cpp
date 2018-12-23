#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
    string total1, total2, str;
    while(cin >> str)
    {
        total1 += str;
        if(total2.empty())
            total2 += str;
        else
            total2 += " " + str;
    }
    cout << total1 << endl;
    cout << total2 << endl;
    return 0;
}