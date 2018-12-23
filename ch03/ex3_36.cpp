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
using std::begin;
using std::end;

bool compare(int *const pb1, int *const pe1, int *const pb2, int *const pe2)
{
    if((pe1-pb1) != (pe2-pb2))
        return false;
    for(int *p = pb1, *q = pb2; p != pe1 && q != pe2; ++p, ++q)
    {
        if(*p != *q)
            return false;
    }
    return true;
}
int main()
{
    int arr1[3] = {1,2,3};
    int arr2[3] = {1,2,3};

    if(compare(begin(arr1),end(arr1),begin(arr2),end(arr2)))
        cout << "Arr1 equals arr2." << endl;
    else
        cout << "Arr1 doesn't equals arr2." << endl;
    
    vector<int> v1(10,0);
    vector<int> v2(10,0);

    if(v1 == v2)
        cout << "V1 equals v2." << endl;
    else
        cout << "V1 doesn't equals arr2." << endl;
    return 0;
}
