#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

class Example{
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);

int main()
{
    
    return 0;
}