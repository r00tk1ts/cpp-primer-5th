#ifndef EX15_26_H
#define EX15_26_H

#include <string>
#include <iostream>

class Quote
{
    friend bool operator !=(const Quote& lhs, const Quote& rhs);
public:
    Quote() { std::cout << "default constructing Quote\n"; }
    Quote(const std::string &b, double p) :
        bookNo(b), price(p) { std::cout << "Quote : constructor taking 2 parameters\n"; }

    // copy constructor
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price)
    { std::cout << "Quote: copy constructing\n"; }

    // move constructor
    Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
    { std::cout << "Quote: move constructing\n"; }

    // copy =
    Quote& operator =(const Quote& rhs)
    {
        if(*this != rhs)
        {
            bookNo = rhs.bookNo;
            price  = rhs.price;
        }
        std::cout << "Quote: copy =() \n";

        return *this;
    }

    // move =
    Quote& operator =(Quote&& rhs)  noexcept
    {
        if(*this != rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price  = std::move(rhs.price);
        }
        std::cout << "Quote: move =!!!!!!!!! \n";

        return *this;
    }

    std::string     isbn() const { return bookNo; }
    virtual double  net_price(std::size_t n) const { return n * price; }
    virtual void    debug() const;

    virtual ~Quote()
    {
        std::cout << "destructing Quote\n";
    }

private:
    std::string bookNo;

protected:
    double  price = 10.0;
};

bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
    return lhs.bookNo != rhs.bookNo
           &&
           lhs.price  != rhs.price;
}


class Bulk_quote : public Quote
{

public:
    Bulk_quote() { std::cout << "default constructing Bulk_quote\n"; }
    Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
        Quote(b, p), n(q), discount(disc) { std::cout << "Bulk_quote : constructor taking 4 parameters\n"; }

    // copy constructor
    Bulk_quote(const Bulk_quote& bq) : Quote(bq)
    { std::cout << "Bulk_quote : copy constructor\n"; }

    // move constructor
    Bulk_quote(Bulk_quote&& bq) : Quote(std::move(bq)) noexcept
    {
        std::cout << "Bulk_quote : move constructor\n";
    }

    // copy =()
    Bulk_quote& operator =(const Bulk_quote& rhs)
    {
        Quote::operator =(rhs);
        std::cout << "Bulk_quote : copy =()\n";

        return *this;
    }


    // move =()
    Bulk_quote& operator =(Bulk_quote&& rhs) noexcept
    {
        Quote::operator =(std::move(rhs));
        std::cout << "Bulk_quote : move =()\n";

        return *this;
    }

    double net_price(std::size_t n) const override;
    void  debug() const override;

    ~Bulk_quote() override
    {
        std::cout << "destructing Bulk_quote\n";
    }
private:
	std::size_t n;
	double discount;
};
#endif // QUOTE_H