#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using std::vector; 
int main()
{
    vector<int> vec = {1,2,3,4,5};
    int temp;
    std::cout << "Input a integer: " << std::endl;
    std::cin >> temp;
    bool bAll = std::all_of(vec.begin(), vec.end(), [temp](int elem){return 0 == temp % elem;});
    std::cout << (bAll ? "Yes" : "No") << std::endl;
    return 0;
}