#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;


int main()
{
    int arr[10]{0,1,2,3,4,5,6,7,8,9};
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
