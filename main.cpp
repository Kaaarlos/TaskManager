#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include<stdio.h>
#include "proceso.h"
#include "list.h"
#include "Contador.h"
#include <time.h>


using namespace std;

void gotoxy(int x,int y);
void pedirDatos(int);
int validar_numero (char numero[]);
void menu();
void procesosTabla();
void dibujarProc(int,int );
void AltEnter();

List<proceso> myProce;
List<Contador> Mycont;
string myStr;
List<proceso>::Position pos;

int comprobar;

int main()
{
    AltEnter();
    char numero[5];
    int n;
    int valido=0;
    do{
        printf("Cuantos procesos deseas introducir?: ");
        scanf("%s",numero);
        n=validar_numero(numero);
    }while(n==0);
    valido  = atoi(numero);
    pedirDatos(valido);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    getchar();
    return 0;
}

void menu()
{
    system("cls");
    printf("%c",201);
    for(int x=0; x<60; x++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);
    for(int j=0; j<36; j++)
    {
        printf("%c                                                            %c%c                                                                                                        %c\n",186,186,186,186);
    }
    printf("%c",200);
    for(int x=0; x<60; x++)
    {
        printf("%c",205);
    }
    printf("%c",188);

    myProceso.gotoxy(62,0);
    printf("%c",201);
    for(int x=0; x<104; x++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);
    myProceso.gotoxy(62,37);
    printf("%c",200);
    for(int x=0; x<104; x++)
    {
        printf("%c",205);
    }
    printf("%c",188);

    SetConsoleTextAttribute(hConsole, 2);
    myProceso.gotoxy(1,2);
    printf("CONTROL DE PROCESOS");
    myProceso.gotoxy(1,3);
    printf("Datos de los procesos:");
    myProceso.gotoxy(35,3);
    printf("Orden de ejecucion:");
    myProceso.gotoxy(1,5);
    printf("| Proceso | Inicio | Duracion |");
    myProceso.gotoxy(35,5);
    printf("| Proceso | Ejecucion |");
    myProceso.gotoxy(22,32);
    printf("| TIEMPO GLOBAL |");
}

void pedirDatos(int n)
{
    int i=1;
    int id=1;
    int cantidad = n;
    int resp;
    srand( (unsigned)time( NULL ) );

    cout<<"Desea que sean numeros random? (1 = si, 2 = no) : ";
    cin>>resp;
    system("cls");

    if(resp==1){
        while (i<=cantidad){
            myProceso.SetId(id);
            myProceso.SetColor(id);
            myProceso.SetInicio(rand()%40+1);
            myProceso.SetDuracion(rand()%40+1);
            i++;
            id++;
            myProce.insertData(myProce.getLastPos(),myProceso);
        }
        menu();
        myProce.datos(myProceso);
        myProce.recta();
        myProce.procesos(myProceso);
    }
    else{
    while(i<=cantidad)
        {
            system("cls");
            fflush(stdin );
            //id
            myProceso.SetId(id);
            myProceso.SetColor(id);
            myConta.SetCont(0);

            cout<<"introduce el inicio del  proceso "<<i<<":"<<endl;
            getline(cin,myStr);
            myProceso.SetInicio(atoi(myStr.c_str()));

            cout<<"introduce la duracion del  proceso "<<i<<":"<<endl;
            getline(cin,myStr);
            myProceso.SetDuracion(atoi(myStr.c_str()));

            myProce.insertData(myProce.getLastPos(),myProceso);
            i++;
            id++;
        }
        menu();
        myProce.datos(myProceso);
        myProce.recta();
        myProce.procesos(myProceso);
    }
}

int validar_numero (char numero[])
{
    int i;
    for (i=0; i<strlen(numero); i++)
    {
        if(! (isdigit (numero[i])))
        {
            printf("\INGRESA SOLO NUMEROS\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}
