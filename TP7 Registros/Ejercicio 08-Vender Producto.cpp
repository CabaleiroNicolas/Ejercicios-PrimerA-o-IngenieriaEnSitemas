#include<stdio.h>
#include<stdlib.h>
#include<string.h>


const int MIN_PRODUCTOS = 2;
const int MAX_PRODUCTOS = 100;
const int MAX_STRING = 80;


struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct Producto 
{
    int codigo;
    char articulo[MAX_STRING];
    int cantidadMinima;
    fecha fechaUltimaCompra;
    int existenciaActual;
    float precio;
};

int Menu () 
{
    int opcion = 0;

    printf("MENU");
    printf("\n----\n");
    printf("\n1- Cargar productos (minimo 10).");
    printf("\n2- Buscar producto.");
    printf("\n3- Vender producto.");
    printf("\n0- Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int MenuModificacion ()
{
    int opcion = 0;
    printf("\n1- Articlo.");
    printf("\n2- Cantidad Minima.");
    printf("\n3- Fecha de ultima compra.");
    printf("\n4- Existencia actual.");
    printf("\n5- Precio.");
    printf("\n0- Volver");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void cargarProductos (Producto inventario[MAX_PRODUCTOS], int &n) 
{ 
    int salir = false; 
    do{
        system("cls");
        printf("\n----- CARGA DE PRODUCTOS -----");
        printf("\nA continuacion cargue productos (codigo = 0 para salir):");
        int restantes = MIN_PRODUCTOS - n;
        printf("\nIngrese como minimo 10 productos ");
        if(restantes <= 0){
            printf("(ya puede salir): ");
        }else{
            printf("(%d restantes): ", restantes);
        }

        int codigoAuxiliar = 0;

        printf("\nCodigo: ");
        scanf("%d", &codigoAuxiliar);

        if(codigoAuxiliar == 0)
		{
            //hilo de salida.
            if(n >= MIN_PRODUCTOS)
			{
                printf("\nCarga de productos finalizada.");
                salir = true;
            }else{
                char opcion[0];
                printf("\nAtencion! No alcanzo el minimo de productos. Los productos cargados se borraran.\n¿Esta seguro que desea continuar? (s/n): ");
                _flushall();
                gets(opcion);
                strlwr(opcion);

                if(strcmp(opcion, "s") == 0)
				{
                    salir = true;
                    n = 0;
                }
            }
        }else{
            //hilo de entrada.
            inventario[n].codigo = codigoAuxiliar;
            printf("Articulo: ");
            _flushall();
            gets(inventario[n].articulo);
            printf("Cantidad Minima: ");
            scanf("%d", &inventario[n].cantidadMinima);
            printf("Fecha de ultima compra.");
            printf("\n\tDia: ");
            scanf("%d", &inventario[n].fechaUltimaCompra.dia);
            printf("\tMes: ");
            scanf("%d", &inventario[n].fechaUltimaCompra.mes);
            printf("\tAño: ");
            scanf("%d", &inventario[n].fechaUltimaCompra.anio);
            printf("\nCantidad disponible: ");
            scanf("%d", &inventario[n].existenciaActual);
            printf("\nPrecio unitario: $");
            scanf("%f", &inventario[n].precio);
            printf("\n");
            n++;
        }

    }while(!salir);
}

void buscarProducto (Producto inventario[MAX_PRODUCTOS], int tope) 

{
    int codigoBusqueda;
    int idx = 0;
    bool encontrado = false;

    printf("\n----- BUSCAR PRODUCTO -----");
    printf("\nCodigo: ");
    scanf("%d", &codigoBusqueda);

    for (int i = 0; i < tope; i++)
	{
        if(inventario[i].codigo == codigoBusqueda)
		{
            encontrado = true;   
            idx = i;             
        }
    }
    if(!encontrado)
	{
        printf("\nLos sentimos. El codigo de producto no existe.");
    }
	else
	{
            int op = 0;
            do
			{
                system("cls");
                printf("\n----- ACTUALIZACION DEL PRODUCTO %d -----", codigoBusqueda);
                op = MenuModificacion();
                system("cls");

                printf("\n----- ACTUALIZACION DEL PRODUCTO %d -----", codigoBusqueda);
                switch(op)
				{
                    case 1:
                        printf("\nArticulo: ");
                        fputs(inventario[idx].articulo, stdout);
                        printf("\nNuevo Articulo: ");
                        _flushall();
                        gets(inventario[idx].articulo);
                        break;
                    case 2:
                        printf("\nCantidad Minima: %d",inventario[idx].cantidadMinima);
                        printf("\nNueva Cantidad Minima: %d");
                        scanf("%d", &inventario[idx].cantidadMinima);
                        break;
                    case 3:
                        printf("Fecha anterior: %d/%d/%d", inventario[idx].fechaUltimaCompra.dia,inventario[idx].fechaUltimaCompra.mes,inventario[idx].fechaUltimaCompra.anio);
                        printf("Nueva Fecha de ultima compra.");
                        printf("\n\tDia: ");
                        scanf("%d", &inventario[idx].fechaUltimaCompra.dia);
                        printf("\tMes: ");
                        scanf("%d", &inventario[idx].fechaUltimaCompra.mes);
                        printf("\tAño: ");
                        scanf("%d", &inventario[idx].fechaUltimaCompra.anio);
                        break;
                    case 4:
                        printf("\nExistencia anteror: %d", inventario[idx].cantidadMinima);
                        printf("\nNueva Existencia actual: %d");
                        scanf("%d", &inventario[idx].cantidadMinima);
                        break;
                    case 5:
                        printf("\nAntroir Precio unitario: $%.2f", inventario[idx].precio);
                        printf("\nPrecio unitario: $");
                        scanf("%f", &inventario[idx].precio);
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }

            }while(op != 0); 
    }
}

void venderProducto (Producto inventario[MAX_PRODUCTOS], int tope){
    int cantidadComprada = 0;
    float montoPagar = 0.0;
    int codigoBusqueda = 0;
    bool encontrado = 0;
    int idx = 0;
    printf("\n----- VENTA DE PRODUCTO -----");
    printf("\nIngrese el codigo del producto a vender: ");
    scanf("%d", &codigoBusqueda);

    for (int i = 0; i < tope; i++){
         if(inventario[i].codigo == codigoBusqueda){
            encontrado = true;  
            idx = i;            
        }
    }

    if(!encontrado){
        printf("\nLos sentimos. El codigo de producto no existe.");
    }else{
        bool excedeStock = true;
        do{
            printf("\nIngrese la cantidad de compra: ");
            scanf("%d", &cantidadComprada);
            
            if(cantidadComprada > inventario[idx].existenciaActual){
                printf("\nError. La cantidad comprada excede el stock. (hay %d unidades)", inventario[idx].existenciaActual);
            }else{
                inventario[idx].existenciaActual -= cantidadComprada;
                montoPagar = cantidadComprada * inventario[idx].precio;
                printf("\nSe vendieron: %d", cantidadComprada);
                printf("\nQuedan en stock: %d unidades", inventario[idx].existenciaActual);
                printf("\nCantidad a pagar: $%.2f", montoPagar);
                excedeStock = false;
            }
        }while(excedeStock);
    }
}

main () {
    int op = 0;
    int n = 0;
    Producto inventario[MAX_PRODUCTOS];

    do {
        system("cls");
        op = Menu();
        system("cls");

        switch(op){
            case 1:
                cargarProductos(inventario, n);
                break;
            case 2:
                buscarProducto(inventario, n);
                break;
            case 3: 
                venderProducto(inventario, n);
            default:
                break;
        }

        printf("\n");
        system("pause");
    }while(op != 0);

    system("cls");
}
