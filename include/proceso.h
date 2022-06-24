#ifndef PROCESO_H
#define PROCESO_H

#include <iostream>
#include <string>


class proceso
{
private:
    int id;
    int inicio;
    int duracion;
    int color;
    int contadorG;
    int mayor;
    int menor;
    int lote;

public:
    proceso();
    proceso(const proceso&);

    proceso& operator = (const proceso&);

    int GetId()const;
    int GetInicio()const;
    int GetDuracion()const;
    int GetColor()const;
    int GetContadorG()const;
    int GetLote()const;
    std::string toString() const;

    void SetId(const int&);
    void SetInicio(const int&);
    void SetDuracion(const int&);
    void SetColor(const int&);
    void SetContadorG(const int&);
    void SetLote(const int&);
    void gotoxy(int,int);



	bool operator == (const proceso&) const;
	bool operator != (const proceso&) const;
	bool operator < (const proceso&) const;
	bool operator <= (const proceso&) const;
	bool operator > (const proceso&) const;
	bool operator >= (const proceso&) const;

    friend std::ostream& operator << (std::ostream&, proceso&);
    friend std::istream& operator >> (std::istream&, proceso&);
};

#endif // PROCESO_H
