#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>

using std::vector; using std::string; using std::list;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::ifstream; using std::istream_iterator; using std::ostream_iterator;
using std::copy; using std::sort;

int main()
{
	vector<int> v;
	istream_iterator<int> in(cin), eof;
	
	copy(in, eof, back_inserter(v));
	sort(v.begin(),v.end());
	copy(v.cbegin(),v.cend(), ostream_iterator<int>(cout, " "));
	return 0;
}