#include <iterator>
#include <iostream>
#include <string>
#include <fstream>

using std::cout; 
using std::endl; 
using std::string;
using std::ifstream;

int main()
{
    ifstream ifs("text.txt");
	if (!ifs) 
		return -1;
	
	string none("aceimnorsuvwxz");
	string result;

    for (string str; ifs >> str; )
	{
		if(str.find_first_not_of(none) != string::npos)
		{
			if(str.size() > result.size())
				result = str;
		}
	}
    cout << result << endl;
    return 0;
}