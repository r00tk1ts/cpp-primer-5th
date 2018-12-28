#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::vector; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::bind;

bool check_size(int n, const string &str)
{
	return n > str.size();
}

int main()
{
	string s("hello");
	vector<int> v{1,2,3,4,5,6,7,8,9};
	
	auto it = find_if(v.begin(), v.end(), bind(check_size, std::placeholders::_1, s));
	if (it != v.cend())
		cout << *it << endl;
	else
		cout << "Sorry, no enough length integer found" << endl;
	return 0;
}