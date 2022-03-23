#ifndef VENDIDOS_H
#define VENDIDOS_H
#include "PRODUCTOP.h"

class VENDIDOS{
    private:
    PRODUCTOP *Cabecera;
    public:
        VENDIDOS();
        virtual ~VENDIDOS();
        void setCabecera(PRODUCTOP *);
        PRODUCTOP *getCabecera();
        bool estaVacio();
        bool buscarNodo(int);
        void Insertar(string, int, int);
        void Imprimir();
        void articulomasVendido();
};

#endif // VENDIDOS_H
