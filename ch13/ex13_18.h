#include <iostream>

class Employee
{
public:
	Employee() { id = genUniqueId(); }
	Employee(const string& _name) : name(_name) { id = genUniqueId(); }
	Employee(const Employee& rhs) : name(rhs.name) { id = genUniqueId(); }
	Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
	static int genUniqueId() { return s_increment++; }
private:
	string name;
	int id;
	static int s_increment = 0;
};