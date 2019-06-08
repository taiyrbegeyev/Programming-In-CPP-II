/*
CH08-320143
Access.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _ACCESS_H
#define _ACCESS_H
#include <set>

class Access {
    private:
        std::set <unsigned int> codes;
    public:
        void activate(unsigned int);
        void deactivate(unsigned int);
        bool isactive(unsigned int) const;
};

#endif