#include <iterator>
#include <iostream>
#include <string>
#include <cstddef>

using std::cout; 
using std::endl; 
using std::string;

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
    for (size_t cur = 0; cur <= s.size() - oldVal.size(); )
        if (oldVal == s.substr(cur, oldVal.size())){
            s.replace(cur, oldVal.size(), newVal);
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