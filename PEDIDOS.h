#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "PRODUCTOP.h"

class PEDIDOS{
    PRODUCTOP *Cabecera;
    public:
        PEDIDOS();
        virtual ~PEDIDOS();
        void setCabecera(PRODUCTOP *);
        PRODUCTOP *getCabecera();
        bool estaVacio();
        bool buscarNodo(int);
        void Insertar(string, int, int);
        void Eliminar(int, int);
        void Imprimir();
};

#endif // PEDIDOS_H
