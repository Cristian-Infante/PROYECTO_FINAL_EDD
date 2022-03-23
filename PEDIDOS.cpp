#include "PEDIDOS.h"

PEDIDOS::PEDIDOS(){
    Cabecera = NULL;
    
}

PEDIDOS::~PEDIDOS(){
    PRODUCTOP *aux = Cabecera; 
    while(Cabecera!=NULL){
        Cabecera = aux->getSig();
        delete aux; 
    }
}

void PEDIDOS::setCabecera(PRODUCTOP *nuevo){
    Cabecera = nuevo; 
}

PRODUCTOP *PEDIDOS::getCabecera(){
    return Cabecera;
}

bool PEDIDOS::estaVacio(){
    if(Cabecera == NULL){
        return true; 
    }
    else{
        return false;
    }
}

bool PEDIDOS::buscarNodo(int codigo){
    PRODUCTOP *aux = Cabecera;
    while(aux!=NULL && aux->getCodigo() != codigo){
        aux = aux->getSig();
    }
    if(aux != NULL){
        return true;
    }
    return false;
}

void PEDIDOS::Insertar(string nombre,int codigo, int cantidad){
    PRODUCTOP *nuevo = new PRODUCTOP(nombre,codigo,cantidad);
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

void PEDIDOS::Imprimir(){
    PRODUCTOP *aux = this->getCabecera();
    gotoxy(15,2); cout<<"LISTA DE PEDIDOS"<<endl;
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

void PEDIDOS::Eliminar(int Codigo, int cantidad){
    PRODUCTOP *act = Cabecera; 
    PRODUCTOP *ant = NULL;
    if(estaVacio()){
        cout<<"No hay elementos"<<endl;
    }
    while(act!=NULL&& act->getCodigo()!=Codigo){
        ant = act; 
        act = act->getSig();
    }
    if(act!=NULL){
        if(act->getCantidad() > cantidad){
            int n = act->getCantidad() - cantidad;
            act->setCantidad(n);
        }
        else{
            ant->setSig(act->getSig());
        }
    }
}