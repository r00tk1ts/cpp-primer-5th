#include "ex12_27.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(ifstream &ifs) : input(new vector<string>)
{
    LineNo lineNo{0};
    for(string line; std::getline(ifs, line); ++lineNo){
        input->push_back(line);
        std::istringstream line_stream(line);
        for(string text, word;line_stream >> text; word.clear()){
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            auto &nos = result[word];
            if(!nos) 
                nos.reset(new set<LineNo>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    static shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>);
    auto found = result.find(str);
    if(found == result.end())
        return QueryResult(str, nodata, input);
    else
        return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for(auto i : *qr.nos)
    {
        out << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
    }
    return out;
}


