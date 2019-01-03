#include <iostream>
#include <string>
#include <memory>

using std::string; using std::unique_ptr;

int main()
{
    unique_ptr<string> p1(new string("hello"));
    unique_ptr<string> p2(p1); // error for copy

    unique_ptr<string> p3 = p1; // error for assignment

    std::cout << *p1 << std::endl;
    p1.reset(nullptr);
}