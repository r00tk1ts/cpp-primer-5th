#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>

using std::vector; using std::string; using std::list;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::ifstream; using std::ofstream; using std::istream_iterator; using std::ostream_iterator;
using std::copy; using std::sort; using std::unique_copy;


void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main(int argc, char **argv)
{
	list<string> words;
	for(string str; cin >> str; words.push_back(str));
	elimDups(words);
	for (const auto& e : words)
        std::cout << e << " ";
    std::cout << std::endl;
	return 0;
}