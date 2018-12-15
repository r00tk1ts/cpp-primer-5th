#include <iostream>
#include "../include/Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    Sales_item sum;
    if(cin >> sum)
    {
        Sales_item temp;
        while(cin >> temp)
        {
            if(sum.isbn() == temp.isbn())
                sum += temp;
            else
            {
                cout << "Meet different ISBN, break out." << endl;
                break;
            }
        }
        cout << sum << endl;
    }
    return 0;
}