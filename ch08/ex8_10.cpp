#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::vector; using std::string; using std::ifstream; using std::istringstream; 
using std::cout; using std::endl; using std::cerr;

int main()
{
    ifstream ifs("text.txt");
    if (!ifs)
    {
        cerr << "No data?" << endl;
        return -1;
    }
    
    vector<string> v;
    string line;
    while (getline(ifs, line))
        v.push_back(line);
    
    for (auto &s : v)
    {
        istringstream iss(s);
        string word;
        while (iss >> word)
            cout << word << endl;
    }
    
    return 0;
}
