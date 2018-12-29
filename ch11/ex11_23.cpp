#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using std::map; using std::set; using std::vector; using std::string; using std::multimap;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	multimap<string, string> family;
	string last;
	cout << "Input last name of family:" << endl;
	cin >> last;
	
	cout << "Input children's first name:" << endl;
	for(string child; cin >> child; )
		family.insert({last, child});
	
	for(const auto &e : family)
	{
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}
