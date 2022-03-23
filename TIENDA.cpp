#include "TIENDA.h"

TIENDA::TIENDA(){
    Cabecera = NULL;
}

TIENDA::~TIENDA(){
    while(Cabecera != NULL){
        SECCION *aux = Cabecera;
        Cabecera = Cabecera->getSig();
        aux->~SECCION();
    }
}

void TIENDA::setCabecera(SECCION *cabecera){
    Cabecera = cabecera;
}

SECCION *TIENDA::getCabecera(){
    return Cabecera;
}

bool TIENDA::estaVacio(){
    if(Cabecera == NULL){
        return true;
    }
    else{
        return false;
    }
}

void TIENDA::insertarSeccion(int seccion, string nombre){
    SECCION *nuevo = new SECCION(seccion, nombre);
    if(estaVacio()){
        Cabecera = nuevo;
    }
    else{
        SECCION *ant = NULL;
        SECCION *aux = Cabecera;
        while((aux != nullptr) && (aux->getCodigo() < seccion)){
            ant = aux;
            aux = aux->getSig();
        }
        if(aux != NULL){
            if(ant == nullptr){
                nuevo->setSig(Cabecera);
                Cabecera = nuevo;
            }
            else{
                nuevo->setSig(aux);
                ant->setSig(nuevo);
            }
        }
        else{
            ant->setSig(nuevo);
        }
    }
}

void TIENDA::EliminarSeccion(int codigo){
    SECCION *padre = nullptr;
    SECCION *salir = Cabecera;
    while((salir != NULL) && (salir->getCodigo() != codigo)){
        padre = salir;
        salir = salir->getSig();
    }
    if(padre == NULL){
        Cabecera=Cabecera->getSig();
    }
    else if(salir != NULL){
        padre->setSig(salir->getSig());
        salir->~SECCION();
    }
}

void TIENDA::insertarProducto(int codS, string nombre, int codigo, int precio, int inventario, int inventarioM){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codS)){
        aux = aux->getSig();
    }
    if(aux == NULL){
        //cout<<endl<<"No existe la seccion";
    }
    else{
        aux->insertarProducto(nombre, codigo, precio, inventario, inventarioM);
    }
}

void TIENDA::EliminarProducto(int codigo){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codigo/1000)){
        aux = aux->getSig();
    }
    if(aux != NULL){
        aux->Eliminar(codigo);
    }
}

PRODUCTO *TIENDA::buscarProducto(int codigo){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codigo/1000)){
        aux = aux->getSig();
    }
    if(aux != NULL){
        PRODUCTO *aux2 = aux->Buscar(codigo);
        return aux2;
    }
}

bool TIENDA::buscarSeccion(int codigoS){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codigoS)){
        aux = aux->getSig();
    }
    if(aux->getCodigo() == codigoS){
        return true;
    }
    else{
        return false;
    }
}

void TIENDA::ventaProducto(int codigo, int cantidad){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codigo/1000)){
        aux = aux->getSig();
    }
    if(aux != NULL){
        aux->ventaProducto(codigo, cantidad);
    }
}

void TIENDA::imprimir(SECCION *aux, int y){
    if(aux != NULL){
        gotoxy(35,y); cout<<aux->getNombre();
        gotoxy(8,y+2); cout<<"Codigo";
        gotoxy(24,y+2); cout<<"Nombre    ";
        gotoxy(48,y+2); cout<<"Precio";
        gotoxy(64,y+2); cout<<"Inventario";
        y = y +4;
        int y2;
        y2 = aux->Imprimir2(aux->getCabecera(), y)+1;
        imprimir(aux->getSig(), y2);
    }
}

void TIENDA::imprimirSecciones(){
    SECCION *aux = Cabecera;
    int y = 3;
    while (aux != NULL){
        gotoxy(8,y); cout<<"["<<aux->getCodigo()<<"]  "<<aux->getNombre();
        aux = aux->getSig();
        y++;
    }

}

void TIENDA::reponerProducto(int codigo, int cantidad){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codigo/1000)){
        aux = aux->getSig();
    }
    if(aux != NULL){
        aux->reponerProducto(codigo, cantidad);
    }
}

void TIENDA::cambiarPrecio(int codigo){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codigo/1000)){
        aux = aux->getSig();
    }
    if(aux!=NULL){
        aux->cambiarPrecio(codigo);
    }
}
