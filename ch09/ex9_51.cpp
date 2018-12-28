#include <iterator>
#include <iostream>
#include <string>
#include <vector>

using std::cout; 
using std::endl; 
using std::string;
using std::vector;

class Date{
public:
  	Date() = default;
  	Date(const string &s);
  	void print(){
        cout << "day:" << day << " " << "month: " << month << " " << "year: " << year;
    }
private:
  	unsigned year = 1970;
  	unsigned month = 1;
  	unsigned day = 1;
};

Date::Date(const string& s)
{
  	vector<string> mon{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  
	if(s.find_first_of("/") != string::npos)
    {
        day = stoi(s.substr(0, s.find_first_of("/")));
      	month = stoi(s.substr(s.find_first_of("/")+1, s.find_last_of("/")-s.find_first_of("/")));
      	year = stoi(s.substr(s.find_last_of("/")+1, 4));
    } else if(s.find_first_of(",") != string::npos){
        day = stoi(s.substr(s.find_first_of("123456789"), s.find_first_of(",")-s.find_first_of("123456789")));
      	year = stoi(s.substr(s.find_first_of(",")+1));
      	for(size_t index=0;index<mon.size();++index)
        {
            if(s.find_first_of(mon[index]) != string::npos){
              	month = index+1;
              	break;
            }
        }
    } else{
        for(size_t index=0;index<mon.size();++index)
        {
            if(s.find_first_of(mon[index]) != string::npos){
              	month = index+1;
              	break;
            }
        }
      	day = stoi(s.substr(s.find_first_of("123456789"), s.find_last_of(" ")-s.find_first_of("123456789")));
      	year = stoi(s.substr(s.find_last_of(" ")));
    }        
}

int main()
{
    Date d("Feb 5 1989");
    d.print();
    return 0;
}