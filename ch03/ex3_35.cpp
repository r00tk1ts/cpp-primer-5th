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
    int arr[4] = {1,2,3,4};
    int *p = arr;
   
    for(int i=0;i<4;i++)
        *p++ = 0;

    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
