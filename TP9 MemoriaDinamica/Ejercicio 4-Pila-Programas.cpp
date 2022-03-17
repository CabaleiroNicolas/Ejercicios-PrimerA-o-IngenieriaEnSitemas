#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct Programa
{
	char nombrePrograma[50];
	int cantLineas;
	
};

struct Nodo
{
	Programa dato;
	Nodo *sig;
		
};


int Menu()
{
	int opc = 0;
	
	printf("\n    --MENU--\n");
	printf("\n(1)- Ingresar Nuevo Programa");
	printf("\n(2)- Mostrar Programas");
	printf("\n(3)- Eliminar Programa");
	printf("\n(0)- SALIR.");
	
	printf("\n\nIngrese opcion: ");
	scanf("%d", &opc);
	
	return opc;
}


void AgregarPrograma(Nodo *&tope, Programa &reg)
{
	Nodo *nuevo_nodo;
	
	if(nuevo_nodo != NULL)
	{
		nuevo_nodo = new Nodo;
		
		nuevo_nodo->dato = reg;
		nuevo_nodo->sig = tope;
		tope = nuevo_nodo;	
	}
	else
	{
		printf("\nImposible Crear Nuevo Nodo...");
	}	
}



void ListarProgramas(Nodo *&tope)
{
	Nodo *p = tope;
	
	while(p != NULL)
	{
		printf("\n\nNombre: %s", p->dato.nombrePrograma);
		printf("\nCantida de Lineas: %d", p->dato.cantLineas);
		
		p = p->sig;
	}	
}



void BorrarPrograma(Nodo *&tope, Programa &reg)
{
	Nodo *p = tope;
	
	if(p != NULL)
	{
		reg = p->dato;
		
		tope = p->sig;
		
		delete p;
		
		printf("\n\nSe Elimino el Programa: %s\n\n", reg.nombrePrograma);
	}
	else
	{
		printf("\n\nNo se Registraron Programas.\n");
	}	
}

main()
{
	int opcion = 0;
	Programa reg;
	
	Nodo *pila = NULL;
	
	do
	{
		system("cls");
		opcion = Menu();
		system("cls");
		
		switch(opcion)
		{
			case 1:
				{
					printf("\n      -Ingresar Programa");
					
					printf("\n\nNombre del Programa: ");
					_flushall();
					gets(reg.nombrePrograma);
					
					printf("Cantidad de Lineas: ");
					scanf("%d", &reg.cantLineas);
					
					AgregarPrograma(pila, reg);
					break;
				}
			case 2:
				{
					printf("\n      -Lista de Programas-\n");
					ListarProgramas(pila);
					printf("\n\nPresione una Tecla para volver al Menu...");
					getch();
					break;
				}
			case 3:
				{
					printf("\n      -Borrar Ultimo Programa-");
					BorrarPrograma(pila, reg);
					system("pause");
					break;
				}
			case 0:
				{
					printf("\n\nCerrando Programa...\n");
					break;
				}
			default:
				{
					printf("\n\nOpcion no se encuentra en el Menu.");
					printf("\nPresione una tecla para regresar...");
					getch();
					break;
				}
		}
		
	}while(opcion != 0);
	
	
	
}








