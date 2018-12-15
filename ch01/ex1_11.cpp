#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    
    if(v2 < v1)
    {
        v2 = v1 ^ v2;
        v1 = v1 ^ v2;
        v2 = v1 ^ v2;
    }
    std::cout << "Numbers between " << v1 << " and " << v2 << std::endl;
    for(;v1<=v2;++v1)
    {
        std::cout << v1 << std::endl;
    }
    return 0;
}