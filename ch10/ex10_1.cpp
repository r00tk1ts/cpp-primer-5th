#include <iostream>
#include <algorithm>
#include <vector>

using std::vector; using std::count;
using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
	vector<int> v;

	cout << "Input integers into vector." << endl;
	for(int temp; cin >> temp; )
		v.push_back(temp);
	
	cout << "Input specific interger: ";
	int n;cin >> n;
	cout << "Occurs " << count(v.begin(), v.end(), n) << " times" << endl;
	
	return 0;
}