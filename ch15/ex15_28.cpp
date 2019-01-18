#include "ex15_26.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<Quote> v;
	for(auto i=0;i!=10;++i)
		v.push_back(Bulk_quote("sss", i*10.1, 10, 0.3));
	
	double total = 0;
	for(const auto &b : v)
	{
		total += b.net_price(20);
	}
	std::cout << total << std::endl;
	
	return 0;
}
