#include "ex14_5.h"

std::istream& operator>>(std::istream& is, Book& book)
{
	is >> book.no >> book.name >> book.author >> book.pubdate; 
	if(!is)
		book = Book(0, "none", "none", "none");
	return is;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.no << " " << book.name << " " << book.author << " " << book.pubdate;
	return os;
}

bool operator==(const Book& lhs, const Book& rhs)
{
	return lhs.no == rhs.no;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
	return !(lhs == rhs);
}