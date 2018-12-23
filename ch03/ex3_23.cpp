#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator iter;
    for(iter=v.begin(); iter!=v.end(); ++iter)
    {
        *iter += *iter;
    }
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
