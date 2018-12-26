#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int add(int a, int b){return a + b;}
int sub(int a, int b){return a - b;}
int mul(int a, int b){return a * b;}
int divide(int a, int b){return b != 0 ? a / b : 0;}
int func(int a, int b);
int main()
{
	vector<decltype(func)*> vec{add, sub, mul, divide};
	for(auto f : vec)
		cout << f(10, 2) << endl;
	return 0;
}
