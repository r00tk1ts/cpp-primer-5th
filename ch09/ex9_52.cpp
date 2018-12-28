#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using std::cin;
using std::cout; 
using std::endl; 
using std::string;
using std::vector;
using std::stack;

int main()
{
	string str("(abc)de(fgh)");
	
	stack<char> stk;
	bool begin = false;
	for(auto c : str)
	{
		if(c == '('){
			begin = true;
		}else if(c == ')'){
			begin = false;
			string result;
			while(stk.top() != '('){
				stk.pop();
			}
			stk.pop();		// pop off the '('
			stk.push('#');	// # means one result
		}
		if(begin)
			stk.push(c);
	}
    return 0;
}