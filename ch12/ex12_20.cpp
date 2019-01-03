#include <iostream>
#include <fstream>
#include "ex12_19.h"

int main()
{
    std::ifstream ifs("book.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); blob.push_back(str));
        
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
}