#include <iostream>

/*
 * balabala.../* */
 * wrong for nested annotaion
 */
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << v1;
    std::cout << " * ";
    std::cout << v2;
    std::cout << " is "; 
    std::cout << v1 * v2; 
    std::cout << std::endl;

    return 0;
}