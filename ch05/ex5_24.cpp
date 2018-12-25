#include <iostream>
#include <vector>
#include <string>

using std::cout; 
using std::endl; 
using std::cin;
using std::vector; 
using std::string; 
using std::getline;

int main()
{	
	int i, j; 
    cin >> i >> j;
	if (j == 0)
        throw std::runtime_error("divisor is 0");
    cout << i / j << endl;
    return 0;
}
