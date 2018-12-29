#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using std::map; using std::set; using std::vector; using std::string; using std::multimap; using std::multiset;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	multimap<string, string> authors{
		{"A", "aaa"},
		{"B", "bbb"},
		{"B", "bb"},
		{"C", "ccc"},
		{"C", "cc"},
		{"C", "c"}
	};
	
	map<string, multiset<string>> ordered;
    for (const auto &author : authors)
        ordered[author.first].insert(author.second);
	for(const auto &author : ordered)
	{
		cout << author.first << ": ";
		for(const auto &work : author.second)
			cout << work << " ";
		cout << endl;
	}
	return 0;
}
