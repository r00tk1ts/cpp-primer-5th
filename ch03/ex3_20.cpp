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
    vector<int> v;
    for(int temp; cin >> temp; v.push_back(temp));
    
    if(v.empty())
        return -1;
    if(v.size() == 1)
    {
        cout << v[0] << endl;
        return 0;
    }
    
    for(int i=0;i<v.size()-1;++i)
        cout << v[i] + v[i+1] << " ";
    cout << endl;

    auto size = (v.size() + 1) / 2;

    for(int i=0;i<size;++i)
    {
        if(i != v.size() - i - 1)
            cout << v[i] + v[v.size()-i-1] << " ";
        else
            cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
