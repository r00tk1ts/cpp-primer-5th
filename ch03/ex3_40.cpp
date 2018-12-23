#include <iostream>
#include <string>
#include <cstring>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
    char s1[] = "hello ";
    char s2[] = "world!";
    char s3[13];

    strcpy(s3, s1);
    strcat(s3, s2);

    cout << s3 << endl;
    return 0;
}
