#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote();
    Disc_quote(const std::string& b, double p, std::size_t q, double d) :
        Quote(b, p), quantity(q), discount(d)   { }

    virtual double net_price(std::size_t n) const override = 0;

protected:
    std::size_t quantity = 0;
    double      discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
        Disc_quote(b, p, q, disc) {   }

    double net_price(std::size_t n) const override;
    void  debug() const override;


};
#endif