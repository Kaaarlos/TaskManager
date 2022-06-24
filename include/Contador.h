#ifndef CONTADOR_H
#define CONTADOR_H

#include <string>
#include <iostream>

class Contador
{
private:
    int cont;
public:
    Contador();
    Contador(const Contador&);

    Contador& operator = (const Contador&);

    int GetCont()const;

    std::string toString() const;

    void SetCont(const int&);

	bool operator == (const Contador&) const;
	bool operator != (const Contador&) const;
	bool operator < (const Contador&) const;
	bool operator <= (const Contador&) const;
	bool operator > (const Contador&) const;
	bool operator >= (const Contador&) const;

    friend std::ostream& operator << (std::ostream&, Contador&);
    friend std::istream& operator >> (std::istream&, Contador&);
};
#endif // CONTADOR_H
