#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

int main()
{
    int arr[4];
    vector<int> v{1,2,3,4};
    for(int i=0;i<v.size();i++)
        arr[i] = v[i];
    
    return 0;
}
