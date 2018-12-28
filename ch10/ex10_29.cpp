#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>

using std::vector; using std::string; using std::list;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::ifstream; using std::istream_iterator; using std::ostream_iterator;
using std::copy;

int main()
{
	ifstream ifs("text.txt");
	vector<string> v;
	istream_iterator<string> in(ifs), eof;	
	copy(in, eof, back_inserter(v));
	
	copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, "\n"));
	return 0;
}