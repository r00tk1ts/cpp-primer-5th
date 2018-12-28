#include <iterator>
#include <iostream>
#include <string>

using std::cout; 
using std::endl; 
using std::string;

int main()
{
    string str = "ab2c3d7R4E6";
	string numbers = "123456789";
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	cout << "numeric characters: ";
    for (size_t pos = 0; (pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)
	{
        cout << str[pos] << " ";
	}
    cout << "\nalphabetic characters: ";
    for (size_t pos = 0; (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)
	{
        cout << str[pos] << " ";
	}
    cout << endl;

	// extremely adaptable for this case
	cout << "numeric characters: ";
    for (int pos = 0; (pos = str.find_first_not_of(alphabet, pos)) != string::npos; ++pos)
	{
        cout << str[pos] << " ";
	}
    cout << "\nalphabetic characters: ";
    for (int pos = 0; (pos = str.find_first_not_of(numbers, pos)) != string::npos; ++pos)
	{
        cout << str[pos] << " ";
	}
    cout << endl;
    
    return 0;
}