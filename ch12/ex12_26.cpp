#include <iostream>
#include <string>
#include <memory>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::allocator;

int main()
{
    allocator<string> alloc;
    const auto p = alloc.allocate(10);
    auto q = p;
    for(string s;q != p + 10; cin >> s)
    {
        alloc.construct(q++, s);
    }

    while(q != p)
    {
        cout << *--q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, 10);
    return 0;
}