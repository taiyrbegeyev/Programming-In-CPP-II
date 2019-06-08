/*
CH08-320143
Access.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _ACCESS_H
#define _ACCESS_H
#include <map>

class Access {
    private:
        std::map <unsigned int, unsigned int> codes;
    public:
        void activate(unsigned int, unsigned int);
        void deactivate(unsigned int);
        bool isactive(unsigned int, unsigned int) const;
};

#endif