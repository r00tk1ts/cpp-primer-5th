#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>

using std::vector; using std::string; using std::list;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::ifstream; using std::ofstream; using std::istream_iterator; using std::ostream_iterator;
using std::copy; using std::sort; using std::unique_copy;

int main(int argc, char **argv)
{
	if (argc != 4) {
		cerr << "Wrong param numbers." << endl;
		return -1;
	}
	ifstream ifs(argv[1]);
    ofstream ofs_odd(argv[2]), ofs_even(argv[3]);
	
	istream_iterator<int> in(ifs), in_eof;
	ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");
	
	std::for_each(in, in_eof, [&out_odd, &out_even](const int i){
        *(i % 2 ? out_odd : out_even)++ = i;
    });
	
	return 0;
}