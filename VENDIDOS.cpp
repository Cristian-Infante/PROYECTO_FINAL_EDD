#include "VENDIDOS.h"

VENDIDOS::VENDIDOS(){
    Cabecera = NULL;
}

VENDIDOS::~VENDIDOS(){
    while(Cabecera != NULL){
        PRODUCTOP *aux = Cabecera;
        Cabecera=Cabecera->getSig();
        aux->~PRODUCTOP();
    }
}

void VENDIDOS::setCabecera(PRODUCTOP *cabecera){
    Cabecera = cabecera;
}

PRODUCTOP *VENDIDOS::getCabecera(){
    return Cabecera;
}

bool VENDIDOS::estaVacio(){
    if(Cabecera == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool VENDIDOS::buscarNodo(int codigo){
    PRODUCTOP *aux = Cabecera;
    while(aux!=NULL && aux->getCodigo() != codigo){
        aux = aux->getSig();
    }
    if(aux != NULL){
        return true;
    }
    return false;
}

void VENDIDOS::Insertar(string nombre, int codigo, int cantidad){
    PRODUCTOP *nuevo = new PRODUCTOP(nombre, codigo, cantidad);
    if(estaVacio()){
        Cabecera = nuevo;
    }
    else if(buscarNodo(codigo) == true){
        PRODUCTOP *aux = Cabecera;
        while(aux !=NULL && aux->getCodigo() != codigo){
            aux = aux->getSig();
        }
        if(aux != NULL){
            int n = aux->getCantidad() + cantidad;
            aux->setCantidad(n);
        }
    }
    else{
        nuevo->setSig(Cabecera);
        Cabecera=nuevo;
    }
}

void VENDIDOS::Imprimir(){
    PRODUCTOP *aux = this->getCabecera();
    gotoxy(15,2); cout<<"LISTA DE VENDIDOS"<<endl;
    gotoxy(8,4); cout<<"Codigo";
    gotoxy(24,4); cout<<"Nombre";
    gotoxy(48,4); cout<<"Cantidad";
    int y = 6;
    while (aux!= nullptr){
        aux->Imprimir(y);
        aux = aux->getSig();
        y++;
    }
}

void VENDIDOS::articulomasVendido(){
    PRODUCTOP *aux = Cabecera;
    int cont = 0;
    while(aux!=NULL){
        if(aux->getCantidad() > cont){
            cont = aux->getCantidad();
        }
        aux = aux->getSig();
    }
    aux = Cabecera;
    gotoxy(8,2); cout<<"Codigo";
    gotoxy(24,2); cout<<"Nombre";
    gotoxy(48,2); cout<<"Cantidad";
    int y = 4;
    while(aux != NULL){
        if(aux->getCantidad() == cont){
            aux->Imprimir(y);
            y++;
        }
        aux = aux->getSig();
    }
}
