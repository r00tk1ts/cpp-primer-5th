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
	int spaceCnt = 0, tableCnt = 0, newlineCnt = 0;
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
			else if(c == ' ')
				++spaceCnt;
			else if(c == '\t')
				++tableCnt;
			else if(c == '\n')
				++newlineCnt;
		}
    }
	
	cout << "a: " << aCnt << "\n"
		<< "e: " << eCnt << "\n"
		<< "i: " << iCnt << "\n"
		<< "o: " << oCnt << "\n"
		<< "u: " << uCnt << "\n"
		<< "space: " << spaceCnt << "\n"
		<< "table: " << tableCnt << "\n"
		<< "newline: " << newlineCnt << endl;
    return 0;
}
