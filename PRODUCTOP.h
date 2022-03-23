#ifndef PRODUCTOP_H
#define PRODUCTOP_H
#include "PRODUCTO.h"

class PRODUCTOP{
    private:
        string Nombre;
        int Codigo, Cantidad;
        PRODUCTOP *Siguiente;
    public:
        PRODUCTOP(string, int, int);
        virtual ~PRODUCTOP();
        void setNombre(string);
        void setCodigo(int);
        void setCantidad(int);
        void setSig(PRODUCTOP *);
        string getNombre();
        int getCodigo();
        int getCantidad();
        PRODUCTOP *getSig();
        void Imprimir(int);
};

#endif // PRODUCTOP_H
