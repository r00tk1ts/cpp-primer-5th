#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using std::map; using std::set; using std::vector; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::remove_if;

string& strip(string &word)
{
	for(auto &c : word)
		c = tolower(c);
	word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
	return word;
}

int main()
{
	map<string, size_t> word_count;
	for(string word; cin >> word;){
		++word_count[strip(word)];
	}	
	
	for(const auto &e : word_count){
		cout << e.first << " occurs " << e.second << "times" << endl;
	}
	return 0;
}
