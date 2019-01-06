#include "ex13_30.h"
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::vector<HasPtr> v;
	v.push_back(HasPtr("hello"));
	v.push_back(HasPtr("world"));
	v.push_back(HasPtr("oops"));
	std::sort(v.begin(), v.end());
	for(auto &e : v){
		e.show();
	}
}