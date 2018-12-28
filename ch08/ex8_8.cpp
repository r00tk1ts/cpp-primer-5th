#include <fstream>
#include <iostream>
#include "Sales_data.h"

using std::cout; using std::endl; using std::cerr;
using std::ifstream; using std::ofstream;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2], std::ostream::app);
	
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
				print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}