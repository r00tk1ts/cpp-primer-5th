#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

using std::vector; using std::string; 
using std::pair; using std::make_pair;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::find;

int main()
{
	vector<pair<string, int>> vec;
	int i;
	string str;
	while(cin >> str >> i)
	{
		vec.push_back(make_pair(str, i));
		vec.push_back({str, i});
		vec.push_back(pair<string, int>(str, i));
	}
	return 0;
}
