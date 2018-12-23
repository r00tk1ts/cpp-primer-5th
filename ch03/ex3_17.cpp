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
    vector<string> v;
    for(string temp; cin >> temp; v.push_back(temp));
    for(auto &str : v){
        for(auto &c : str)
            c = toupper(c);
        cout << str << endl;
    }

    return 0;
}