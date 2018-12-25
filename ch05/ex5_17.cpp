#include <iostream>
#include <vector>
#include <string>

using std::cout; 
using std::endl; 
using std::cin;
using std::vector; 
using std::string; 
using std::getline;

bool is_prefix(vector<int> const& lhs, vector<int> const& rhs)
{
    if(lhs.size() > rhs.size())
        return is_prefix(rhs, lhs);
    for(int i = 0; i != lhs.size(); ++i)
        if(lhs[i] != rhs[i]) 
			return false;
    return true;
}

int main()
{	
    vector<int> v1{0,1,1,2}, v2{0,1,1,2,3,5,8};
	
	cout << is_prefix(v1, v2) << endl;
    return 0;
}
