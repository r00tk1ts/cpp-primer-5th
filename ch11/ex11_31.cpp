#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using std::map; using std::set; using std::vector; using std::string; using std::multimap;
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
	
	string author = "B";
    string work = "bb";
    
    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count) {
        if (found->second == work) {
            authors.erase(found);
            break;   
        }
        ++found;
        --count;
    }
    
    for (const auto &author : authors)
        cout << author.first << " " << author.second << endl;
	return 0;
}
