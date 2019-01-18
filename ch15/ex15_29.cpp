#include "ex15_26.h"
#include <iostream>
#include <vector>
#include <memory>

int main()
{
	std::vector<std::shared_ptr<Quote>> pv;
	for(auto i=0;i!=10;++i)
		pv.push_back(std::make_shared<Bulk_quote>("sss", i*10.1, 10, 0.3));
	
	double total = 0;
	for(auto p : pv)
	{
		total += b->net_price(20);
	}
	std::cout << total << std::endl;
	
	return 0;
}
