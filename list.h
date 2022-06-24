#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


#include <algorithm>
#include "proceso.h"
#include "Contador.h"
HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

proceso myProceso;
Contador myConta;

int contadorG=0;
int contadorPrint=0;
int inicioPrint=0;
template<class T>
class List
{
private:
    class Node
    {
    private:
        T data;
        Node* prev;
        Node* next;
        Node* last;

    public:
        Node();
        Node(const T&);

        T getData()const;
        Node* getPrev() const;
        Node* getNext() const;

        void setData(const T&);
        void setNext(Node*);
        void setPrev(Node*);
    };
    Node* anchor;

    void copyAll(const List<T>&);

    bool isValidPos(Node*) const;

public:

    typedef Node* Position;
    class Exception : public std::exception
    {
    private:
        std::string msg;
    public:
        explicit Exception(const char* message) : msg (message) {}

        explicit Exception(const std::string& message):msg(message) {}

        virtual ~Exception() throw () {}

        virtual const char* what() const throw ()
        {
            return msg.c_str();
        }
    };

    List();

    List(const List<T>&);

    ~List();

    bool isEmpty()const;
    void insertData(Node*, const T&);
    void deleteData(Node*);

    Node* getFirstPos() const;
    Node* getLastPos() const;
    Node* getPrevPos(Node*)const;
    Node* getNextPos(Node*) const;

    Node* findData(const T&) const;
    Node*  buscarUltimo(Node*)const;
    Node* procesos(T) ;
    Node* datos(T) ;

    T retrieve(Node*) const;

    std::string toString() const;

    void deletAll();
    void gotoxy(  int,  int ) ;
    void recta();


    List<T>& operator = (const List<T>&);
};

template<class T>
bool List<T>::isValidPos(Node* p)const
{

    if(!isEmpty())
    {
        Node* aux(anchor);

        do
        {
            if(aux==p)
            {
                return true;
            }
            aux=aux->getNext();
        }
        while(aux!=anchor);
    }
    return false;
}

template<class T>
void List<T>::copyAll(const List<T>&l)
{

    if(l.isEmpty())
    {
        return;
    }
    Node* aux(l.anchor);
    Node* last(nullptr);
    Node* newNode;

    do
    {
        if((newNode= new Node(aux->getData())) ==nullptr)
        {
            throw Exception ("Memoria no disponible, copyAll");
        }
        if(last == nullptr)
        {
            anchor= newNode;
        }
        else
        {
            newNode->setPrev(last);
            last->setNext(newNode);
        }
        last=newNode;
        aux= aux->getNext();
    }
    while(aux != l.anchor);
    anchor->setPrev(last);
    last->setNext(anchor);
}
//Nodo

template<class T>
List<T>::Node::Node():next(nullptr) {}

template<class T>
List<T>::Node::Node(const T& e):data(e),next(nullptr) {}

template<class T>
T List<T>::Node::getData()const
{
    return data;
}

template<class T>
typename List<T>::Node* List<T>::Node::getNext() const
{
    return next;
}

template<class T>
typename List<T>::Node* List<T>::Node::getPrev() const
{
    return prev;
}

template<class T>
void List<T>::Node::setData(const T& e)
{
    data = e;
}

template<class T>
void List<T>::Node::setNext(Node* p)
{
    next = p;
}

template<class T>
void List<T>::Node::setPrev(Node* p)
{
    prev = p;
}
//Lista

template<class T>
List<T>::List():anchor(nullptr) {}

template<class T>
List<T>::List(const List<T>& l): anchor(nullptr)
{
    copyAll(l);
}

template<class T>
List<T>::~List()
{
    deletAll();
}

template<class T>
bool List<T>::isEmpty()const
{
    return anchor == nullptr;
}

template<class T>
void List<T>::insertData(Node* p, const T& e)
{
    if  (p != nullptr && !isValidPos(p))
    {
        throw Exception ("Posicion invalida, InsertData");
    }
    Node* aux(new Node (e));

    if(aux == nullptr)
    {
        throw Exception("Memoria no disponible, insertData");
    }
    if(p == nullptr)
    {
        if(anchor ==nullptr)
        {
            aux->setPrev(aux);
            aux->setNext(aux);
        }
        else
        {
            aux->setPrev(anchor->getPrev());
            aux->setNext(anchor);

            anchor->getPrev()->setNext(aux);
            anchor->setPrev(aux);
        }
        anchor=aux;
    }
    else
    {
        aux->setPrev(p);
        aux->setNext(p-> getNext());

        p->getNext()->setPrev(aux);
        p->setNext(aux);
    }
}

template<class T>
void List<T>::deleteData(Node* p)
{
    if(!isValidPos(p))
    {
        throw Exception ("Posicion invalida, deleteData");
    }
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    if(p == anchor)
    {
        if(p->getNext()==p)
        {
            anchor=nullptr;
        }
        else
        {
            anchor=anchor->getNext();
        }
    }
    delete p;
}

template<class T>
typename List<T>::Node* List<T>::getFirstPos() const
{
    return anchor;
}

template<class T>
typename List<T>::Node* List<T>::getLastPos() const
{
    if(isEmpty())
    {
        return nullptr;
    }
    return anchor->getPrev();
}

template<class T>
typename List<T>::Node* List<T>::getPrevPos(Node* p) const
{
    if(p==anchor || !isValidPos(p))
    {
        return nullptr;
    }
    return p->getPrev();
}

template<class T>
typename List<T>::Node* List<T>::getNextPos(Node* p) const
{
    if(!isValidPos(p) || p == anchor->getPrev())
    {
        return nullptr;
    }
    return p->getNext();
}

template<class T>
typename List<T>::Node* List<T>::findData(const T& e) const
{
    if(!isEmpty())
    {
        Node* aux(anchor);
        do
        {
            if(aux->getData()==e)
            {
                return aux;
            }
            aux= aux->getNext();
        }
        while(aux!=anchor);
    }
    return nullptr;
}

template<class T>
typename List<T>::Node* List<T>::procesos(T e)
{

    int i=0;
    int j=0;
    int o=0;
    int lote=1;
    int lote2=1;
    int total=0;
    int color=1;
    int restante=0;


    Node* aux;
    aux=anchor;

    while(j < aux->getData().GetId())
    {
        if(lote==5 )
        {
            lote=0;
            lote2++;
        }

        restante=aux->getData().GetDuracion()-aux->getData().GetInicio();

        if (aux->getData().GetInicio()>aux->getData().GetDuracion())
        {
            int recorrido=aux->getData().GetInicio()-aux->getData().GetDuracion();
            int rest=recorrido;

            while(i < recorrido)
            {
                myProceso.gotoxy(1,aux->getData().GetId()+6);
                printf("|    %i    |    %i   |   %i     |    |    %i    |   %i    |",aux->getData().GetId(),aux->getData().GetInicio(),aux->getData().GetDuracion(),aux->getData().GetId(),aux->getData().GetInicio()+i);

                myProceso.gotoxy(20,33);
                printf("Global: %i Restante: %i ",total++,rest--);

                SetConsoleTextAttribute(hConsole, aux->getData().GetId());

                myProceso.gotoxy(63+aux->getData().GetInicio()+i,aux->getData().GetId());
                printf("%c",219);

                i++;
                Sleep(100);

                //lote
                myProceso.gotoxy(1,33);
                printf(" lote:%i ",lote2);
            }
            SetConsoleTextAttribute(hConsole, aux->getData().GetId());
            myProceso.gotoxy(64+aux->getData().GetInicio()+recorrido,aux->getData().GetId());
            printf(" IDD:%i Duracion:%i ",aux->getData().GetId(),(aux->getData().GetDuracion()-aux->getData().GetInicio())*-1);
        }
        else
        {
            while(i < aux->getData().GetDuracion()-aux->getData().GetInicio())
            {
                myProceso.gotoxy(1,aux->getData().GetId()+6);
                printf("|    %i    |    %i   |   %i     |    |    %i    |   %i    |",aux->getData().GetId(),aux->getData().GetInicio(),aux->getData().GetDuracion(),aux->getData().GetId(),aux->getData().GetInicio()+i);

                myProceso.gotoxy(20,33);
                printf("Global: %i Restante: %i ",total++,restante--);

                SetConsoleTextAttribute(hConsole, aux->getData().GetId());

                myProceso.gotoxy(62+aux->getData().GetInicio()+i,aux->getData().GetId());
                printf("%c",219);

                i++;
                Sleep(100);

                SetConsoleTextAttribute(hConsole, aux->getData().GetId());
                myProceso.gotoxy(64+aux->getData().GetDuracion(),aux->getData().GetId());
                printf(" IDD+:%i Duracion:%i ",aux->getData().GetId(),aux->getData().GetDuracion()-aux->getData().GetInicio());

                myProceso.gotoxy(1,33);
                printf(" lote:%i ",lote2);
            }
        }
        lote++;
        i=0;
        j++;
        aux=aux->getNext();
    }
}

template<class T>
void List<T>::recta()
{

    myProceso.gotoxy(63,35);
    printf("%i",inicioPrint);

    myProceso.gotoxy(63+(contadorG/2),35);
    printf("--%i--",contadorG/2);

    myProceso.gotoxy(63+contadorG,35);
    printf("%i",contadorG);
}

template<class T>
typename List<T>::Node* List<T>::datos(T e)
{
    Node* aux;
    Node* aux2;
    aux=anchor;
    aux2=anchor;
    int i =0;

    int maxx=0;

    while(i<aux->getData().GetId())
    {

        if (aux->getData().GetInicio()>aux->getData().GetDuracion())
        {
            int recorrido=aux->getData().GetInicio()+(aux->getData().GetInicio()-aux->getData().GetDuracion());
            if (recorrido>maxx)
            {
                maxx=recorrido;
                contadorG=maxx;
                contadorPrint=maxx;
            }
        }
        else
        {
            if(aux->getData().GetInicio()+aux->getData().GetDuracion()>maxx){
            maxx=(aux->getData().GetDuracion()+aux->getData().GetInicio());
            contadorG=maxx;
            contadorPrint=maxx;
            }
        }
        aux=aux->getNext();
        i++;
    }

}


template<class T>
T List<T>::retrieve(Node* p)const
{
    if(!isValidPos(p))
    {
        throw Exception("Posicion invalida, retrieve");
    }
    return p->getData();
}

template<class T>
std::string List<T>::toString() const
{
    std::string result;
    if(!isEmpty())
    {
        Node* aux(anchor);
        do
        {
            result+= aux->getData().toString()+"\n\n";
            aux=aux->getNext();
        }
        while (aux!=anchor);
    }
    return result;
}

template<class T>
void List<T>::deletAll()
{
    if(isEmpty())
    {
        return;
    }
    Node* aux;
    Node* mark(anchor);

    do
    {
        aux= anchor;
        anchor=anchor->getNext();
        delete aux;
    }
    while(anchor!=mark);
    anchor=nullptr;
}

template<class T>
List<T>& List<T>::operator = (const List<T>&l)
{
    deletAll();
    copyAll(l);

    return *this;
}

#endif // LIST_H_INCLUDED
