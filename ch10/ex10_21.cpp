#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::vector; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	int i = 10;
	auto f = [&i](){return --i ? false : true;};
	while(f());
	cout << i << endl;
	return 0;
}