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
	string s1, s2;
	string test;
    do{
		cout << "Enter two strings: " << endl;
		cin >> s1 >> s2;
		cout << (s1.size() <= s2.size() ? s1 : s2) << "\n";
		cout << "More test? [EOF to end]" << endl;
	}while(cin >> test);
    return 0;
}
