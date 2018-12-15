#include <iostream>
#include "../include/Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    Sales_item item;
    if(cin >> item)
    {
        int cnt = 1;
        Sales_item temp;
        while(std::cin >> temp)
        {
            if(item.isbn() == temp.isbn())
                ++cnt;
            else
            {
                cout << item << " occurs " << cnt << " times" << endl;
                cnt = 1;
                item = temp;
            }
        }
        cout << item << " occurs " << cnt << " times" << endl;
    }
    return 0;
}