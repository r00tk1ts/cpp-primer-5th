#include <iostream>
#include <vector>
#include <string>

using std::cout; 
using std::endl; 
using std::cin;
using std::vector; 
using std::string; 
using std::getline;

int main()
{	
    string text;
	int count = 0;
    while (getline(cin, text))
    {
        for(auto c : text)
		{
			if(c == 'a')
				++count;
			else if(c == 'e')
				++count;
			else if(c == 'i')
				++count;
			else if(c == 'o')
				++count;
			else if(c == 'u')
				++count;
		}
    }

    return 0;
}
