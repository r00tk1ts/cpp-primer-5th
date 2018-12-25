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
	string str, prevstr;
	while(cin >> str)
	{
		if(str == prevstr)
			break;
		prevstr = str;
	}
	if(cin.eof())
		cout << str << endl;
	else
		cout << "No repeated words" << endl;
    return 0;
}
