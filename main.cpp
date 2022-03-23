#include "PRODUCTO.cpp"
#include "SECCION.cpp"
#include "TIENDA.cpp"
#include "PRODUCTOP.cpp"
#include "VENDIDOS.cpp"
#include "PEDIDOS.cpp"

TIENDA *Tienda = new TIENDA();
VENDIDOS *Vendidos = new VENDIDOS();
PEDIDOS *Pedidos = new PEDIDOS();

void venderProducto();
void reponerProducto();
void Menu();
void ImprimirTienda();
void ArticuloMasVendido();
void AgregarProducto();
void EditarProducto();
void EliminarProducto();
void AgregarSeccion();
void EliminarSeccion();

main(){
    //setlocale(LC_CTYPE, "Spanish");
    Tienda->insertarSeccion(4, "Dulces");
    Tienda->insertarSeccion(3, "Aseo");
    Tienda->insertarSeccion(2, "Bebidas");
    Tienda->insertarSeccion(1, "Alimentos");

    Tienda->insertarProducto(1, "Queso_lb", 1405, 8000, 30, 20);
    Tienda->insertarProducto(1,"Arroz_lb", 1601, 2000, 50, 20);
    Tienda->insertarProducto(1, "Aceite_500ml", 1202, 8000, 70, 20);
    Tienda->insertarProducto(1, "Frijoles_lb", 1107, 4500, 30, 20);
    Tienda->insertarProducto(1, "Papa_lb", 1363, 3000, 45, 20);
    Tienda->insertarProducto(1, "Jamon_lb", 1854, 3000, 25, 20);
    Tienda->insertarProducto(1, "Lentejas_lb", 1696, 4500, 30, 20);
    Tienda->insertarProducto(1, "Garbanzos_lb", 1918, 4500, 30, 20);

    Tienda->insertarProducto(2, "Cocacola_1.5l", 2941, 3500, 30, 20);
    Tienda->insertarProducto(2, "Agua_sin_gas", 2983, 2000, 30, 20);
    Tienda->insertarProducto(2, "Agua_con_gas", 2384, 2000, 30, 20);
    Tienda->insertarProducto(2, "Cocacola_lata", 2912, 2000, 30, 20);

    Tienda->insertarProducto(3, "Clorox_250ml", 3672, 5000, 20, 19);
    Tienda->insertarProducto(3, "Escoba", 3971, 5000, 20, 10);
    Tienda->insertarProducto(3, "Fab_lb", 3363, 5000, 20, 19);

    Tienda->insertarProducto(4, "Chocolatina_jet", 4712, 500, 30, 20);
    Tienda->insertarProducto(4, "Bombombun", 4911, 500, 30, 20);
    Tienda->insertarProducto(4, "Bubalu", 4343, 300, 30, 20);

    ImprimirTienda();

    getch();

    venderProducto();
    system("cls");
    gotoxy(50,10); cout<<"...Saliendo..."<<endl<<endl<<endl<<endl<<endl<<endl;
}

void Menu(){
    int OPC;
    do{
        system("cls");
        gotoxy(20,0); cout<<"MENU";
        gotoxy(8,2); cout<<"[00]  Salir del programa";
        gotoxy(8,3); cout<<"[01]  Vender";
        gotoxy(8,4); cout<<"[02]  Solicitud de producto";
        gotoxy(8,5); cout<<"[03]  Imprimir Tienda";
        gotoxy(8,6); cout<<"[04]  Imprimir lista de vendidos";
        gotoxy(8,7); cout<<"[05]  Imprimir lista de pedidos";
        gotoxy(8,8); cout<<"[06]  Articulos mas vendidos";
        gotoxy(8,9); cout<<"[07]  Agregar producto";
        gotoxy(8,10); cout<<"[08]  Editar precio de producto";
        gotoxy(8,11); cout<<"[09]  Eliminar producto";
        gotoxy(8,12); cout<<"[10]  Agregar seccion";
        gotoxy(8,13); cout<<"[11]  Eliminar seccion";

        gotoxy(13,15); cout<<"Ingrese opcion: "; cin>>OPC;

        while(OPC > 11 && OPC < 0){
            Menu();
        }

        switch(OPC){
            case 0:
                break;
            case 1:
                venderProducto();
                break;
            case 2:
                reponerProducto();
                break;
            case 3:
                ImprimirTienda();
                getch();
                break;
            case 4:
                system("cls");
                Vendidos->Imprimir();
                getch();
                break;
            case 5:
                system("cls");
                Pedidos->Imprimir();
                getch();
                break;
            case 6:
                system("cls");
                ArticuloMasVendido();
                getch();
                break;
            case 7:
                system("cls");
                AgregarProducto();
                getch();
                break;
            case 8:
                system("cls");
                EditarProducto();
                getch();
                break;
            case 9:
                system("cls");
                EliminarProducto();
                getch();
                break;
            case 10:
                system("cls");
                AgregarSeccion();
                getch();
                break;
            case 11:
                system("cls");
                EliminarSeccion();
                getch();
                break;
        }
    }while(OPC != 0);
}

void venderProducto(){
    system("cls");
    int Codigo = 0, cantidad =0;
    int n = 6, total = 0;
    gotoxy(8,4); cout<<"Codigo";
    gotoxy(24,4); cout<<"Nombre    ";
    gotoxy(48,4); cout<<"Precio";
    gotoxy(60,4); cout<<"Cantidad";
    gotoxy(74,4); cout<<"Subtotal";
    do{
        gotoxy(65,2); cout<<"|  TOTAL: $"<<total;
        gotoxy(8,2); cout<<"Ingrese el codigo del producto: ";
        gotoxy(47,2); cout<<"Cantidad: ";
        gotoxy(40,2); cin>>Codigo;
        if(Codigo == 1){
            venderProducto();
        }
        if(Codigo != 0){
            gotoxy(57,2);cin>>cantidad;
            PRODUCTO *aux = Tienda->buscarProducto(Codigo);
            if(aux != NULL){
                if(aux->getInventario() != 0){
                    if(aux->getInventario() >= cantidad){
                        if(aux->getInventario() == cantidad){
                            gotoxy(90,2); cout<<"|...PRODUCTO AGOTADO...|";
                            getch();
                        }
                        Tienda->ventaProducto(Codigo, cantidad);
                        Vendidos->Insertar(aux->getNombre(), aux->getCodigo(), cantidad);
                        if(aux->getInventario() < aux->getInventarioM()){
                            int dif = aux->getInventarioM() - aux->getInventario();
                            Pedidos->Insertar(aux->getNombre(), aux->getCodigo(), dif);
                        }

                        gotoxy(8,n); cout<<aux->getCodigo();
                        gotoxy(24,n); cout<<aux->getNombre();
                        gotoxy(48,n); cout<<aux->getPrecio();
                        gotoxy(60,n); cout<<cantidad;
                        gotoxy(74,n); cout<<"$"<<aux->getPrecio()*cantidad;
                        total = total + aux->getPrecio()*cantidad;
                        n++;
                    }
                    else{
                        gotoxy(86,2); cout<<"|...Solo hay "<<aux->getInventario()<<" unidades...|";
                        getch();
                    }
                }
                else{
                    gotoxy(90,2); cout<<"|...PRODUCTO AGOTADO...|";
                    getch();
                }
            }
            gotoxy(40,2); cout<<"      ";
            gotoxy(57,2); cout<<"      ";
            gotoxy(86,2); cout<<"                              ";
        }
    }while(Codigo != 0);
    Menu();
}

void reponerProducto(){
    system("cls");
    int Cod, Cant;
    gotoxy(8,2); cout<<"REPONER PRODUCTO";
    gotoxy(8,4); cout<<"Ingrese Codigo: "; cin>>Cod;
    if(Cod != 0){
        PRODUCTO *aux = Tienda->buscarProducto(Cod);
        if(aux != NULL){
            gotoxy(8,5); cout<<"Ingrese Cantidad: "; cin>>Cant;
            Tienda->reponerProducto(Cod, Cant);
            Pedidos->Eliminar(aux->getCodigo(), Cant);
            getch();
        }
    }
    Menu();
}

void ImprimirTienda(){
    system("cls");
    int n = 1;
    Tienda->imprimir(Tienda->getCabecera(), n);
}

void ArticuloMasVendido(){
    Vendidos->articulomasVendido();
    Menu();
}

void AgregarProducto(){
    string nombre; int codigo, precio, cantidad, codS, stock;
    Tienda->imprimirSecciones();
    gotoxy(8,1); cout<<"Codigo seccion: "; cin>>codS;
    system("cls");
    if(Tienda->buscarSeccion(codS)){
        gotoxy(8,3); cout<<"Codigo: "; cin>>codigo;
        if(Tienda->buscarProducto(codigo) == NULL){
            gotoxy(8,4); cout<<"Nombre: "; cin>>nombre;
            gotoxy(8,5); cout<<"Precio: "; cin>>precio;
            gotoxy(8,6); cout<<"Cantidad: "; cin>>cantidad;
            gotoxy(8,7); cout<<"Stock minimo: "; cin>>stock;
            Tienda->insertarProducto(codS, nombre, codigo, precio, cantidad, stock);
        }
    }
    Menu();

}

void EditarProducto(){
    int codigo;
    gotoxy(8,1); cout<<"Ingrese el codigo del producto: "; cin>>codigo;
    Tienda->cambiarPrecio(codigo);
    Menu();
}

void EliminarProducto(){
    int codigo;
    gotoxy(8,1); cout<<"Ingrese el codigo del producto: "; cin>>codigo;
    Tienda->EliminarProducto(codigo);
    Menu();
}

void AgregarSeccion(){
    int codigo; string nombre;
    gotoxy(8,1); cout<<"Ingrese el codigo de la seccion: "; cin>>codigo;
    gotoxy(8,2); cout<<"Ingrese el nombre de la seccion: "; cin>>nombre;
    Tienda->insertarSeccion(codigo, nombre);
    Menu();
}

void EliminarSeccion(){
    int codigo;
    gotoxy(8,1); cout<<"Ingrese el codigo de la seccion: "; cin>>codigo;
    Tienda->EliminarSeccion(codigo);
    Menu();
}
