#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

class Account{
public:
    Account(const string& o, double a):owner(o), amount(a) {}
    double calculate(){ amount += amount * interestRate; return amount; }
    static double rate() { return interestRate; }
    static void rate(double newRate){ interestRate = newRate; }
private:
    std::string owner;
    double amount;
    static double interestRate;
};

double Account::interestRate = 42.42;

int main()
{
    Account m("Tony", 1.1);
    cout << m.calculate() << endl;
    cout << "rate: " << Account::rate() << endl;
    Account::rate(24.24);
    cout << m.calculate() << endl;
    return 0;
}