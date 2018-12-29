#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::find;

int main()
{
	vector<string> dict;
	for(string str; cin >> str; )
	{
		if(find(dict.begin(), dict.end(), str) != dict.end())
			continue;
		else
			dict.push_back(str);
	}
	return 0;
}
