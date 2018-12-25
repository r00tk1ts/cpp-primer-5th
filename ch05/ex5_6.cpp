#include <iostream>
#include <vector>
#include <string>

using std::cout; 
using std::endl; 
using std::cin;
using std::vector; 
using std::string; 

int main()
{
	vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
    int score = 0;
    while (cin >> score)
    {
        string letter = score < 60 ? scores[0] : scores[(score - 50) / 10];
        letter += (score == 100 || score < 60) ? "" : (score % 10 > 7) ? "+" : (score % 10 < 3) ? "-" : "";
        cout << letter << endl;
    }

    return 0;
}
