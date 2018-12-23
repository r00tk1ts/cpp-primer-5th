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
    for(auto &c : str)
    {
        c = 'X';
    }
    cout << str << endl;
    return 0;
}