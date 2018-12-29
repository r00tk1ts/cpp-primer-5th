#include <unordered_map>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string; using std::unordered_map; using std::map; using std::set;
using std::cout; using std::cin; using std::endl; using std::cerr;
using std::ifstream; using std::ofstream; using std::istringstream; using std::ostringstream;

void wordCounting()
{
    unordered_map<string, size_t> word_count;
    for (string word; cin >> word; ++word_count[word]);
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << (w.second > 1 ? "times" : "time") << endl;
}

void wordTransformation()
{
    ifstream ifs_map("word_transformation.txt"), ifs_content("given_to_transform.txt");
    if (!ifs_map || !ifs_content) {
        cerr << "can't find the documents." << endl;
        return;
    }
    
    unordered_map<string, string> trans_map;
    for (string key, value; ifs_map >> key && getline(ifs_map, value); )
        if (value.size() > 1) 
			trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
    
    for (string text, word; getline(ifs_content, text); cout << endl)
        for (istringstream iss(text); iss >> word; ) {
            auto map_it = trans_map.find(word);
            cout << (map_it == trans_map.cend() ? word : map_it->second) << " ";
        }
}

int main()
{
    wordCounting();
    wordTransformation();
}
