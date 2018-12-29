#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using std::map; using std::set; using std::vector; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	map<string, vector<string>> family;
	string last;
	cout << "Input last name of family:" << endl;
	cin >> last;
	family[last] = {};
	
	cout << "Input children's first name:" << endl;
	for(string child; cin >> child; )
		family[last].push_back(child);
	
	cout << "Input last name of family to add children:" << endl;
	cin >> last;
	cout << "Input children's first name to append:" << endl;
	if(family.find(last) != family.end())
	{
		for(string child; cin >> child;)
			family[last].push_back(child);
	}
	
	for(const auto &e : family)
	{
		cout << "Family: " << e.first << endl;
		for(const auto &name : e.second)
			cout << name << " ";
	}
	cout << endl;
	return 0;
}
