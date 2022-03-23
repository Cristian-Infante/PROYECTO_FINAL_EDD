#ifndef SECCION_H
#define SECCION_H
#include "PRODUCTO.h"
#include "PEDIDOS.h"

//ARBOL AVL DE NODOS
class SECCION{
    private:
        PEDIDOS *Pedidos = new PEDIDOS();
        string Nombre;
        int Codigo;
        PRODUCTO *Cabecera;
        SECCION *Siguiente;
    public:
        SECCION(int, string);
        virtual ~SECCION();
        void destruirSeccion(PRODUCTO *);
        void setNombre(string);
        void setCabecera(PRODUCTO *);
        void setCodigo(int);
        void setSig(SECCION *);
        string getNombre();
        PRODUCTO *getCabecera();
        int getCodigo();
        SECCION *getSig();
        bool estaVacio();
        void insertarProducto(string, int, int, int, int);
        int Altura(PRODUCTO *);
        PRODUCTO *RD(PRODUCTO *);
        PRODUCTO *RI(PRODUCTO *);
        PRODUCTO *DRD(PRODUCTO *);
        PRODUCTO *DRI(PRODUCTO *);
        PRODUCTO *Balanceo(PRODUCTO *);
        void Imprimir();
        void ImpTree(PRODUCTO *, const string&);
        int Imprimir2(PRODUCTO *, int);
        PRODUCTO *Eliminar(int);
        PRODUCTO *BuscarReemp(PRODUCTO *);
        int Grado(int);
        PRODUCTO *Buscar(int);
        void ventaProducto(int, int);
        void reponerProducto(int, int);
        void cambiarPrecio(int);
};

#endif // SECCION_H
