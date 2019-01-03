#include <iostream>
#include <vector>
#include <memory>

using std::vector;
using std::cout; using std::cin; using std::endl;
using std::shared_ptr; using std::make_shared;

using vecPtr = shared_ptr<vector<int>>;

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
	vecPtr pv = make_shared<vector<int>>();
	populate(pv);
	print(pv);
	return 0;
}