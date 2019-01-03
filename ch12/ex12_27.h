#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <memory>

using std::string; using std::vector; using std::shared_ptr; using std::map; using std::set;
using std::ifstream; using std::ostream;

class QueryResult;
class TextQuery{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> input;
    map<string, shared_ptr<set<LineNo>>> result;
};

class QueryResult{
    friend ostream& print(ostream &, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v) 
        : word(s), nos(set), input(v) { }
private:
    string word;
    shared_ptr<set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};


