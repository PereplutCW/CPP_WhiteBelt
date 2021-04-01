#pragma once

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "date.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& os) const;
    string Last(const Date& date) const;

    template<typename Functor>
    int RemoveIf(const Functor& func);
    template<typename Functor>
    vector<pair<Date, string>> FindIf(const Functor& func) const;    
private:
    map<Date, pair<set<string>, vector<set<string>::iterator>>> dates;
};

#endif