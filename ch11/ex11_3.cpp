#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::map; using std::vector; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	map<string, size_t> word_count;
	for(string word; cin >> word; ++word_count[word]);
	
	for(const auto &e : word_count){
		cout << e.first << " occurs " << e.second << "times" << endl;
	}
	return 0;
}
