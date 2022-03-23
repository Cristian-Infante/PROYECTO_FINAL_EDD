#include "PRODUCTOP.h"

PRODUCTOP::PRODUCTOP(string nombre, int codigo, int cantidad){
    Nombre = nombre;
    Codigo = codigo;
    Cantidad = cantidad;
    Siguiente = NULL;
}

PRODUCTOP::~PRODUCTOP(){
    Nombre = "";
    Codigo = NULL;
    Cantidad = NULL;
    Siguiente = NULL;
}

void PRODUCTOP::setNombre(string nombre){
    Nombre = nombre;
}

void PRODUCTOP::setCodigo(int codigo){
    Codigo = codigo;
}

void PRODUCTOP::setCantidad(int cantidad){
    Cantidad = cantidad;
}

void PRODUCTOP::setSig(PRODUCTOP *siguiente){
    Siguiente = siguiente;
}

string PRODUCTOP::getNombre(){
    return Nombre;
}

int PRODUCTOP::getCodigo(){
    return Codigo;
}

int PRODUCTOP::getCantidad(){
    return Cantidad;
}

PRODUCTOP *PRODUCTOP::getSig(){
    return Siguiente;
}

void PRODUCTOP::Imprimir(int y){
    gotoxy(8,y); cout<<Codigo;
    gotoxy(24,y); cout<<Nombre;
    gotoxy(48,y); cout<<Cantidad;
}
