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
	int ffCnt = 0, flCnt = 0, fiCnt = 0;
    while (getline(cin, text))
    {
		bool prefix = false;
        for(auto c : text)
		{
			if(prefix == true)
			{
				if(c == 'f')
					++ffCnt;
				else if(c == 'l')
					++flCnt;
				else if(c == 'i')
					++fiCnt;
			}
			
			if(c == 'f')
				prefix = true;
			else
				prefix = false;
		}
    }
	cout << "ff: " << ffCnt << "\n"
		<< "fl: " << flCnt << "\n"
		<< "fi: " << fiCnt << endl;
    return 0;
}
