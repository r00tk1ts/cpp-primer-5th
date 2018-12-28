#include <iterator>
#include <iostream>
#include <string>
#include <vector>

using std::cout; 
using std::endl; 
using std::string;
using std::vector;

int sum_for_int(std::vector<std::string> const& v)
{
    int sum = 0;
    for (auto const& s : v)
        sum += std::stoi(s);
    return sum;
}

float sum_for_float(std::vector<std::string> const& v)
{
    float sum = 0.0;
    for (auto const& s : v)
        sum += std::stof(s);
    return sum;
}

int main()
{
	vector<string> isvec{"1","2","3"};
	cout << "sum for int: " << sum_for_int(isvec) << endl;
	vector<string> fsvec{"1.2", "2.4", "3.5"};
	cout << "sum for float: " << sum_for_float(isvec) << endl;
    return 0;
}