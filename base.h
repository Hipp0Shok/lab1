#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <cstring>
#include "fstream"
enum Kind {BASE, DISH, SETLUNCH};

class Base
{

public:
    Base();
    virtual ~Base();
    virtual float getEnergyValueTotal() const = 0;
    virtual Kind getKind() const {return BASE;}
    void writeKind(std::ofstream &) const;
    static Kind readKind(std::ifstream &);
    virtual void write(std::ofstream &) const = 0;
    virtual void read(std::ifstream &) = 0;
    virtual Base& operator = (Base const &) = 0;
};


#endif // BASE_H