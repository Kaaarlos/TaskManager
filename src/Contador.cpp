#include "Contador.h"
#include <ostream>
using namespace std;

Contador::Contador(){}

Contador::Contador(const Contador&s):cont(s.cont){}

Contador & Contador::operator=(const Contador&s){
    cont = s.cont;

    return *this;
}

void Contador::SetCont(const int& c)
{
    this->cont=c;
}


int Contador::GetCont() const
{
    return cont;
}

std::string Contador::toString() const {
    char result[100];

    sprintf(result," /%i/ ",cont);

    return result;
}

ostream& operator << (ostream& os, Contador& s){
    os<<s.cont<<endl;
    return os;
}

istream& operator >> (istream& is, Contador& s){
    string myStr;

    getline(is,myStr);
    s.cont= atoi(myStr.c_str());

    return is;

}

bool Contador::operator > (const Contador& s) const{
     return toString() > s.toString();
}
bool Contador::operator == (const Contador& s) const{
     return toString() == s.toString();
}

bool Contador::operator != (const Contador& s) const{
     return toString() != s.toString();
}

bool Contador::operator < (const Contador& s) const{
     return toString() < s.toString();
}

bool Contador::operator <= (const Contador& s) const{
     return toString() <= s.toString();
}

bool Contador::operator >= (const Contador& s) const{
     return toString() >= s.toString();
}
