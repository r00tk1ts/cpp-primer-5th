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
    int arr[10]{0,1,2,3,4,5,6,7,8,9};
    int arr_cp[10];

    for(int i=0;i<10;i++)
        arr_cp[i] = arr[i];

    vector<int> v{0,1,2,3,4,5,6,7,8,9};
    vector<int> v_cp = v;
    return 0;
}
