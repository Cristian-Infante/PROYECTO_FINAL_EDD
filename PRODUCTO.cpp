#include "PRODUCTO.h"

PRODUCTO::PRODUCTO(string nombre, int codigo, int precio, int inventario, int inventarioM){
    Nombre = nombre;
    Codigo = codigo;
    Precio = precio;
    Inventario = inventario;
    InventarioI = inventario;
    InventarioM = inventarioM;
    Derecha = NULL;
    Izquierda = NULL;
}

PRODUCTO::~PRODUCTO(){
    Nombre = "";
    Codigo = NULL;
    Precio = NULL;
    Inventario = NULL;
    Derecha = NULL;
    Izquierda = NULL;
}

void PRODUCTO::setNombre(string nombre){
    Nombre = nombre;
}

void PRODUCTO::setCodigo(int codigo){
    Codigo = codigo;
}

void PRODUCTO::setPrecio(int precio){
    Precio = precio;
}

void PRODUCTO::setInventario(int inventario){
    Inventario = inventario;
    InventarioI = inventario;
}

void PRODUCTO::setInventarioM(int inventario){
    InventarioM = inventario;
}

void PRODUCTO::setDer(PRODUCTO *derecha){
    Derecha = derecha;
}

void PRODUCTO::setIzq(PRODUCTO *izquierda){
    Izquierda = izquierda;
}

string PRODUCTO::getNombre(){
    return Nombre;
}

int PRODUCTO::getCodigo(){
    return Codigo;
}

int PRODUCTO::getPrecio(){
    return Precio;
}

int PRODUCTO::getInventario(){
    return Inventario;
}

int PRODUCTO::getInventarioI(){
    return InventarioI;
}

int PRODUCTO::getInventarioM(){
    return InventarioM;
}

PRODUCTO* PRODUCTO::getDer(){
    return Derecha;
}

PRODUCTO* PRODUCTO::getIzq(){
    return Izquierda;
}
