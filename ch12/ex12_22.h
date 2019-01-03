#ifndef _EX12_22_H
#define _EX12_22_H 

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using std::string;
using std::vector;
class ConstStrBlobPtr;
class StrBlob {
	friend class ConstStrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob() : data(std::make_shared<vector<string>>()) { }
    StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) { }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const std::string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
	
    const std::string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }
	
	ConstStrBlobPtr begin() const;
	
	ConstStrBlobPtr end() const;
	
private:
    void check(size_type i, const string &msg) const {
        if (i >= data->size()) throw std::out_of_range(msg);
    }

private:
    std::shared_ptr<vector<string>> data;
};

class ConstStrBlobPtr{
public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
	const std::string& deref() const{
		auto p = check(curr, "dereference past end");
        return (*p)[curr];
	}
	ConstStrBlobPtr& incr(){
		check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
	}
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const{
		auto ret = wptr.lock();
        if (!ret) 
			throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) 
			throw std::out_of_range(msg);
        return ret;
	}
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
#endif