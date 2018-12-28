#include <iostream>
#include <vector>
#include <list>

using std::vector; using std::list; 
using std::cout; using std::endl; using std::end; using std::begin;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    vector<int> vec(begin(ia), end(ia));
    list<int> lst(vec.begin(), vec.end());

    for(auto it = lst.begin(); it != lst.end();)
	{
        if(*it % 2 == 1) 
			it = lst.erase(it);
        else 
			++it;
	}
 
    for(auto it = vec.begin(); it != vec.end();)
	{
        if(*it % 2 == 0) 
			it = vec.erase(it);
        else 
			++it;
	}
    
	cout << "list : ";
    for(auto i : lst)  
		cout << i << " ";
    cout << "\nvector: ";
    for(auto i : vec)   
		cout << i << " ";
    cout << std::endl;

    return 0;
}