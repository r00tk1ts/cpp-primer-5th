#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using std::vector; using std::count; using std::list; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	list<string> lst;

	cout << "Input strings into list." << endl;
	for(string str; cin >> str; )
		lst.push_back(str);
	
	cout << "Input specific string: ";
	string s;cin >> s;
	cout << "Occurs " << count(lst.begin(), lst.end(), s) << " times" << endl;
	
	return 0;
}