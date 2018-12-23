#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

int main()
{
    int arr[3][4] = 
    { 
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };

    // range for
    for (auto &row : arr)
        for (auto col : row) cout << col << " ";
    cout << endl;

    // for loop
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j) cout << arr[i][j] << " ";
    cout << endl;

    // using pointers.
    for (auto row = arr; row != arr + 3; ++row)
        for (auto col = *row; col != *row + 4; ++col) cout << *col << " ";
    cout << endl;
    return 0;
}
