#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Quote.h"

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& b, double p, std::size_t q, double disc) : 
		Quote(b, p), min_qty(q), discount(disc) { }
	double net_price(size_t cnt) const override
	{
		if(cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	void debug() const override
	{
		Quote::debug();
		std::cout << "min_qty=" << min_qty << " discount=" << discount << std::endl;
	}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};
#endif