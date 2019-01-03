#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

using vecPtr = vector<int>*;
 
void populate(vecPtr pv)
{
	for (int i; cin >> i; pv->push_back(i));
}

void print(vecPtr pv)
{
	for(auto e : *pv)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vecPtr pv = new vector<int>{};
	populate(pv);
	print(pv);
	delete pv;
	return 0;
}