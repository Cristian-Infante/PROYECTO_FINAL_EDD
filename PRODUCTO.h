#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "string"
#include "iostream"
#include "iomanip"
#include "conio.h"
#include <stdio.h>  
#include <windows.h>
#include <locale.h>
using namespace std;

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 

//NODO
class PRODUCTO{
    private:
        string Nombre;
        int Codigo, Precio, Inventario, InventarioI, InventarioM;
        PRODUCTO *Izquierda;
        PRODUCTO *Derecha;
    public:
        PRODUCTO(string, int, int, int, int);
        virtual ~PRODUCTO();
        void setNombre(string);
        void setCodigo(int);
        void setPrecio(int);
        void setInventario(int);
        void setInventarioM(int);
        void setDer(PRODUCTO *);
        void setIzq(PRODUCTO *);
        string getNombre();
        int getCodigo();
        int getPrecio();
        int getInventario();
        int getInventarioI();
        int getInventarioM();
        PRODUCTO *getDer();
        PRODUCTO *getIzq();
};

#endif // PRODUCTO_H
