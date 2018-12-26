#include "Chapter6.h"
#include <iostream>

int fact(int i)
{
    if (i == 0 || i == 1) return 1;
    else return i * fact(i-1);
}

void myabs(int v)
{
    if(v < 0)
      	std::cout << -v << std::endl;
  	else
      	std::cout << v << std::endl;
}	

int func()
{
    static int cnt = 0;
  	return cnt++;
}