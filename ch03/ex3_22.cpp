#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

int main()
{
    vector<string> text;
    for(string str;getline(cin, str);text.push_back(str));

    for(auto &word : text)
    {
        for(auto &c : word)
        {
            if(isalpha(c))
                c = toupper(c);
        }
        cout << word << " ";
    }
    return 0;
}
