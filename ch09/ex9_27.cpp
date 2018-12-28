#include <iostream>
#include <forward_list>

using std::forward_list; 
using std::cout; using std::cin; using std::endl;

int main()
{
    forward_list<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = data.before_begin();
	for(auto iter = data.begin();iter != data.end(); )
	{
		if(*iter % 2 == 1)
			iter = data.erase_after(prev);
		else{
			prev = iter;
			++iter;
		}
	}
    for (auto i : data) 
        cout << i << " ";
	cout << endl;
    return 0;
}
