#ifndef TIENDA_H
#define TIENDA_H
#include "SECCION.h"
#include "PRODUCTO.h"

class TIENDA{
    private:
        SECCION *Cabecera;
    public:
        TIENDA();
        virtual ~TIENDA();
        void setCabecera(SECCION *);
        SECCION *getCabecera();
        bool estaVacio();
        void insertarSeccion(int, string);
        void EliminarSeccion(int);
        void insertarProducto(int, string, int, int, int, int);
        void EliminarProducto(int);
        PRODUCTO *buscarProducto(int);
        bool buscarSeccion(int);
        void ventaProducto(int, int);
        void imprimir(SECCION *, int);
        void imprimirSecciones();
        void reponerProducto(int, int);
        void cambiarPrecio(int);
};

#endif // TIENDA_H
