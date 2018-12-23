#include <iostream>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::begin;
using std::end;
int main()
{
    int arr[] = {1,2,3};
    vector<int> v(begin(arr), end(arr));
    return 0;
}
