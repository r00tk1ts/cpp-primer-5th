#include <iostream>
#include <vector>
#include <string>
#include <exception>

using std::cout; 
using std::endl; 
using std::cin;
using std::vector; 
using std::string; 
using std::getline;
using std::runtime_error;

int main()
{	
	int i, j;
	
	for (; cout << "Input two integers:\n", cin >> i >> j; )
    {
        try 
        {
            if (j == 0) 
                throw runtime_error("divisor is 0");
            cout << i / j << endl;
        }
        catch (runtime_error err) 
        {
			string str;
            cout << err.what() << "\n" << "Continue?[EOF to end]" << endl;
			cin >> str;
			if(cin.eof())
				break;
        }
    }
    return 0;
}
