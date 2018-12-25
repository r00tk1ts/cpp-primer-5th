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
    for (int score; cin >> score;)
    {
        string letter;
        if (score < 60)
        {
            letter = scores[0];
        }
        else
        {
            letter = scores[(score - 50) / 10];
            if (score != 100)
                letter += score % 10 > 7 ? "+" : score % 10 < 3 ? "-" : "";
            cout << letter << endl;
        }
    }

    return 0;
}
