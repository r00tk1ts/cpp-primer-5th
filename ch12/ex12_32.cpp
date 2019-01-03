#include "ex12_32.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs)
{
    StrBlob::size_type lineNo{ 0 };
    for (string line; std::getline(ifs, line); ++lineNo) {
        file.push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            auto &nos = result[word];
            if (!nos) nos.reset(new std::set<StrBlob::size_type>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    static shared_ptr<std::set<StrBlob::size_type>> nodate(new std::set<StrBlob::size_type>);
    auto found = result.find(str);
    if (found == result.end()) return QueryResult(str, nodate, file);
    else return QueryResult(str, found->second, file);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos) {
        ConstStrBlobPtr p(qr.file, i);
        out << "\t(line " << i+1 << ") " << p.deref() << std::endl;
    }
    return out;
}