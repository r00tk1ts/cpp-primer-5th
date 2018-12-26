#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;
using std::cerr;

class Screen {
    public:
        using pos = std::string::size_type;

        Screen() = default;
  		Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' '){}
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }
		Screen& move(pos r, pos c) { cursor = r * width + c; return *this; }
		Screen& set(char c) { contents[cursor] = c; return *this; }
		Screen& set(pos r, pos c, char ch) { contents[r*width+c] = ch; return *this; }
		const Screen& display(std::ostream& os) const { os << contents; return *this; }
		
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

int main()
{
    Screen myScreen(5, 5, 'X');
	myScreen.move(4,0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
    return 0;
}