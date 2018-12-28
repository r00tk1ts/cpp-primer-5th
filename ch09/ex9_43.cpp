#include <iterator>
#include <iostream>
#include <string>
#include <cstddef>

using std::cout; 
using std::endl; 
using std::string;

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); )
        if (oldVal == string(cur, cur + oldVal.size())){
            cur = s.erase(cur, cur + oldVal.size()),
            cur = s.insert(cur, newVal.begin(), newVal.end()),
            cur += newVal.size();
		}
        else  
            ++cur;
}

int main()
{
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    cout << s << endl;

    return 0;
}