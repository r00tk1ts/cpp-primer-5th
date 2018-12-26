#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

int main()
{
	for(int n; cout << "Enter a number:\n", cin >> n;)
	{
		cout << fact(n) << endl;
	}
}