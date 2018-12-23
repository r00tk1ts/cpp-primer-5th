#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
    string str;
    string output;

    getline(cin, str);
    for(auto c : str)
    {
        if(!ispunct(c))
            output += c;
    }

    cout << output << endl;
    return 0;
}