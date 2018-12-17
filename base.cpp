#include "base.h"
#include "iostream"
#include "string.h"
#include "fstream"

Base::Base()
{

}

Base::~Base()
{

}

void Base::writeKind(std::ofstream &file) const
{
    Kind temp = getKind();
    file.write(reinterpret_cast<char*>(&temp), sizeof (Kind));
}

Kind Base::readKind(std::ifstream &file)
{
    Kind answer;
    file.read(reinterpret_cast<char*>(&answer), sizeof (Kind));
    return answer;
}
