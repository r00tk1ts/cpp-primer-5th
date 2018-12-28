#include <iostream>
#include <sstream>

std::istream& func(std::istream &is)
{
    std::string str;
  	while(is >> str)
      	std::cout << str << std::endl;
  	is.clear();
  	return is;
}

int main()
{
    std::istringstream iss("hello");
    func(iss);
    return 0;
}