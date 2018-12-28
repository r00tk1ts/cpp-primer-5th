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

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	printWords(words);
	//sort(words.begin(), words.end());
	stable_sort(words.begin(), words.end(), isShorter);
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
	return 0;
}