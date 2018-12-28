#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::vector; using std::string; using std::list;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
    std::vector<int> v1, v2;
	std::list<int> v3;
    
    copy(vec.begin(), vec.end(), inserter(v1, v1.begin()));
	copy(vec.begin(), vec.end(), back_inserter(v2));
	copy(vec.begin(), vec.end(), front_inserter(v3));
	for(auto e:v1)
		cout << e << " ";
	cout << endl;
	
	for(auto e:v2)
		cout << e << " ";
	cout << endl;
	
	for(auto e:v3)
		cout << e << " ";
	cout << endl;
	return 0;
}