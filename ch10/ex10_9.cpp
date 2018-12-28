#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using std::vector; using std::list; using std::string;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::sort; using std::unique;
void printWords(vector<string> &words)
{
	for(auto s : words)
	{
		cout << s << " ";
	}
	cout << endl;
}
void elimDups(vector<string> &words)
{
	printWords(words);
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	printWords(words);
	words.erase(end_unique, words.end());
	printWords(words);
}

int main()
{
	vector<string> words;
	for(string str; cin >> str; words.push_back(str));
	elimDups(words);
	for (const auto& e : words)
        std::cout << e << " ";
    std::cout << std::endl;
	return 0;
}