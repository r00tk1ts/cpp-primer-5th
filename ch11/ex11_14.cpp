#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <utility>

using std::map; using std::set; using std::vector; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::pair;

int main()
{
	map<string, vector<pair<string, string>>> family;
	string last;
	cout << "Input last name of family:" << endl;
	cin >> last;
	family[last] = {};
	
	cout << "Input children's first name and birthday:" << endl;
	for(string child, birth; cin >> child >> birth; )
		family[last].push_back(make_pair(child, birth));
	
	for(const auto &e : family)
	{
		cout << "Family: " << e.first << endl;
		for(const auto &children : e.second)
		{
			cout << children.first << " " << children.second << endl;
		}
	}
	return 0;
}
