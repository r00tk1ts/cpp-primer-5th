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
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    while (getline(cin, text))
    {
        for(auto c : text)
		{
			if(c == 'a' || c == 'A')
				++aCnt;
			else if(c == 'e' || c == 'E')
				++eCnt;
			else if(c == 'i' || c == 'I')
				++iCnt;
			else if(c == 'o' || c == 'O')
				++oCnt;
			else if(c == 'u' || c == 'U')
				++uCnt;
		}
    }

    return 0;
}
