#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::cout; 
using std::endl; 
using std::cin;
using std::vector; 
using std::string; 
using std::getline;
using std::pair;

int main()
{	
    string text;
	pair<string, int> max;
	int count = 0;
	
	for(string str, prevstr; cin >> str; prevstr = str)
	{
		if(str == prevstr)
		{
			++count;
			if(count > max.second)
				max = {str, count};
		}
		else
			count = 0;
	}
	
	cout << max.first << " : " << max.second << endl;
    return 0;
}
