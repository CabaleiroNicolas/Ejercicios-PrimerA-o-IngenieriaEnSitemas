#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Articulo
{
	int codigo;
	char nombre[20];
	float importe;	
};

struct Nodo
{
	Articulo info;
	Nodo *sig;	
};



int Menu()
{
	int opc = 0;
	
	printf("\n   -MENU-");
	printf("\n\n1)- Ingresar");
	printf("\n2)- Listar Articulos");
	printf("\n3)- Eliminar Articulo");
	printf("\n0)- Salir...");
	
	printf("\n\nOpcion :");
	scanf("%d", &opc);
	
	return opc;
}


void InsertarArticulo(Nodo *&frente, Nodo *&fondo, Articulo reg)
{

	Nodo *p;
	p = new Nodo;
	
	if(p != NULL)
	{
		p->info = reg;
		p->sig = NULL;
		
		if(frente == NULL)
		{
			frente = p;
		}
		else
		{
			fondo->sig = p;
			fondo = p;
		}
		
		fondo = p;		
	}	
}



void ListarArticulos(Nodo *&frente)
{
	Nodo *p;
	
	p = frente;
	
	printf("\n");
	
	if(p == NULL)
	{
		printf("\nNo hay Articulos");
	}
	
	printf("\n\n");
	
	while(p != NULL)
	{
		printf("Articulo: %s", p->info.nombre);
		printf("\nCodigo: %d", p->info.codigo);
		printf("\nImporte: %.2f\n\n", p->info.importe);
		
		p = p->sig;
	}
}


void BorrarArticulo(Nodo *&frente, Nodo *&fondo)
{
	Nodo *p;
	Articulo aux;
	bool eliminado = false;
	
	if(frente != NULL)
	{
		p = frente;
		aux = frente->info;
		eliminado = true;
		
		frente = frente->sig;
		
		delete p;
		
	}
	else
	{
		fondo = NULL;
	}
	
	if(eliminado == true)
	{
		printf("\nSe Elimino el Articulo: %s\n\n", aux.nombre);	
	}
	else
	{
		printf("\nNo hay Articulos para Eliminar...\n\n");
	}
}


main()
{
	
	Articulo reg;
	Nodo *frente;
	Nodo *fondo;
	
	frente = NULL;
	fondo = NULL;
	
	
	int opcion = 0;
	
	do
	{
		system("cls");
		opcion = Menu();
		system("cls");
		
		switch(opcion)
		{
			case 1:
				{
					
					printf("\nCodigo: ");
					scanf("%d", &reg.codigo);
	
					printf("\nNombre: ");
					_flushall();
					gets(reg.nombre);
					
					printf("\nImporte: ");
					scanf("%f", &reg.importe);
					
					InsertarArticulo(frente,fondo, reg);
					printf("\n\nArticulo Ingresado con Exito!!...\n");
					system("pause");
					break;
				}
			case 2:
				{
					printf("\n    -Lista de Articulos-");
					printf("\n******************************");
					ListarArticulos(frente);
					printf("\n\n");
					system("pause");
					break;
				}
			case 3:
				{
					BorrarArticulo(frente, fondo);
					system("pause");
					break;
				}
			case 0: 
				{
					printf("\nCerrando Programa...");
					 break;
				}	
		}
		
		
	}while(opcion != 0);
	
}
