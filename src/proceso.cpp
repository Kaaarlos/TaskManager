#include "proceso.h"
#include <windows.h>
#include <ostream>

using namespace std;

proceso::proceso(){}

proceso::proceso(const proceso&s):id(s.id),inicio(s.inicio),duracion(s.duracion),color(s.color),contadorG(s.contadorG),lote(s.lote){}

proceso & proceso::operator=(const proceso&s){
    id = s.id;
    inicio = s.inicio;
    duracion = s.duracion;
    color = s.color;
    contadorG = s.contadorG;
    lote = s.lote;
    return *this;
}

void proceso::SetId(const int& i)
{
    this->id=i;
}

void proceso::SetInicio(const int& i)
{
    this->inicio=i;
}

void proceso::SetDuracion(const int& d)
{
    this->duracion=d;
}

void proceso::SetColor(const int& c)
{
    this->color=c;
}

void proceso::SetContadorG(const int& c)
{
    this->contadorG=c;
}

void proceso::SetLote(const int& l)
{
    this->lote=l;
}

int proceso::GetId()const
{
    return id;
}

int proceso::GetInicio()const
{
    return inicio;
}

int proceso::GetDuracion()const
{
    return duracion;
}

int proceso::GetColor()const
{
    return color;
}

int proceso::GetContadorG()const
{
    return contadorG;
}
int proceso::GetLote()const
{
    return lote;
}

std::string proceso::toString() const {
    char result[100];

    sprintf(result," |  %i  |  %i  |  %i  |\t\t\t %i ", id, inicio, duracion,id);

    return result;
}

ostream& operator << (ostream& os, proceso& s){
    os<<s.id<<endl;
    os<<s.inicio<<endl;
    os<<s.duracion<<endl;
    os<<s.color<<endl;
    os<<s.contadorG<<endl;
    os<<s.lote<<endl;
    return os;
}
istream& operator >> (istream& is, proceso& s){
    string myStr;

    getline(is,myStr);
    s.id= atoi(myStr.c_str());

    getline(is,myStr);
    s.inicio= atoi(myStr.c_str());

    getline(is,myStr);
    s.duracion= atoi(myStr.c_str());

    getline(is,myStr);
    s.contadorG= atoi(myStr.c_str());

    getline(is,myStr);
    s.lote= atoi(myStr.c_str());

    return is;

}

bool proceso::operator > (const proceso& s) const{
     return toString() > s.toString();
}
bool proceso::operator == (const proceso& s) const{
     return toString() == s.toString();
}

bool proceso::operator != (const proceso& s) const{
     return toString() != s.toString();
}

bool proceso::operator < (const proceso& s) const{
     return toString() < s.toString();
}

bool proceso::operator <= (const proceso& s) const{
     return toString() <= s.toString();
}

bool proceso::operator >= (const proceso& s) const{
     return toString() >= s.toString();
}


void proceso::gotoxy(  int x,  int y)
{
    HANDLE hcon;
    hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

