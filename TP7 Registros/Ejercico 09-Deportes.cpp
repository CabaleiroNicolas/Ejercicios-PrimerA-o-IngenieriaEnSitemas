#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Articulo
{
	int codigo;
	char descripcion[30];
	int stock;
	float precio;
	bool borrado;
		
};

int Menu()
{
	int opc = 0;
	
	printf("\n(1)- Ingresar Articulo");
	printf("\n(2)- Buscar y Mostrar Articulo");
	printf("\n(3)- Mostrar Articulos Ordenados Alfabeticamente");
	printf("\n(4)- Mostrar Articulos Ordenados por Stock");
	printf("\n(0)- SALIR");
	printf("\n\nIngrese Opcion: ");
	scanf("%d", &opc);
	
	return opc;
}


void Agregar(Articulo art[20], int &cont)
{
		
	printf("\nCodigo: ");
	scanf("%d", &art[cont].codigo);
		
	printf("\nDescripcion: ");
	_flushall();
	gets(art[cont].descripcion);
		
	printf("\nStock: ");
	scanf("%d", &art[cont].stock);
	
	printf("\nPrecio: ");
	scanf("%f", &art[cont].precio);
	
	art[cont].borrado = false;
	
	printf("\n\nArticulo ingresado con Exito!!");
		
	cont++;		
}

void BuscarYMostrar(Articulo art[20], int &cont)
{
	int aBuscar = 0;
	int pos = 0;
	bool encontrado = false;
	char opcion[3];
	
	printf("\Ingrese Codigo a Buscar: ");
	scanf("%d", &aBuscar);
	
	for(int i = 0; i < cont; i++)
	{
		if(art[i].codigo == aBuscar)
		{
			pos = i;
			encontrado = true;
			
		}	
	}
	
	if((encontrado == true) && (art[pos].borrado == false))
	{
		printf("\nCodigo: %d", art[pos].codigo);
		printf("\nDescripcion: %s", art[pos].descripcion);
		printf("\nStock: %d", art[pos].stock);
		printf("\nPrecio: $%.2f", art[pos].precio);
		
		printf("\n\nDesea Eliminar este Articulo si/no: ");
		_flushall();
		scanf("%s", &opcion);
		strlwr(opcion);
		
		if(strcmp(opcion, "si") == 0)
		{
			for(int i = pos; i < cont; i++)
			{
				art[i] = art[i+1];
				
				
			}
			
			cont--;
			
			printf("\nArticulo Eliminado con Exito!!");
			
		}
		else
		{
			printf("\nNo se elimino el articulo...");
		}		
	}
	else
	{
		printf("\nEl codigo de articulo no se encuentra registrado...");
	}	
}


void OrdenarAlfabeticamente(Articulo reg[20], int cont)
{
	Articulo aux;
	int L = cont-1;
	bool band = false;
	
	do
	{
		band = false;
		
		for(int i = 0; i < L; i++)
		{
			if(strcmp(reg[i].descripcion, reg[i+1].descripcion) < 1)
			{
				aux = reg[i];
				reg[i] = reg[i+1];
				reg[i+1] = aux;
			}
			
			band = true;
		}
		L--;
		
	}while (band == true);	
}


void OrdenarPorStock(Articulo reg[20], int cont)
{
	Articulo aux;
	int L = cont-1;
	bool band = false;
	
	do
	{
		band = false;
		
		for(int i = 0; i < L; i++)
		{
			if(reg[1].stock < reg[i+1].stock)
			{
				aux = reg[i];
				reg[i] = reg[i+1];
				reg[i+1] = aux;
			}
			
			band = true;
		}
		L--;
		
	}while (band == true);	
}

void MostrarOrdenado(Articulo reg[20], int cont)
{
	for(int i = 0; i < cont; i++)
	{
		printf("\n\nDescripcion: %s", reg[i].descripcion);
		printf("\nCodigo: %d", reg[i].codigo);
		printf("\nStock: %d", reg[i].stock);
		printf("\nPrecio: %.2f", reg[i].precio);
	
	}	
}

main()
{
	Articulo articulos[20];
	
	int opcion = 0;
	int contador = 0;
	
	do
	{
		system("cls");
		opcion = Menu();
		system("cls");
		
		switch(opcion)
		{
			case 1: system("cls");
					printf("\n-Ingresar Articulo-\n\n");
					Agregar(articulos, contador);
					printf("\n\n");
					system("pause");
				break;
				
			case 2: system("cls");
					printf("\n-Buscar y Mostrar Articulo-\n\n");
					BuscarYMostrar(articulos, contador);
					printf("\n\n");
					system("pause");
				break;
				
			case 3: system("cls");
					printf("\n-Registro Oredenado Alfabeticamente-\n\n");
					OrdenarAlfabeticamente(articulos, contador);
					MostrarOrdenado(articulos, contador);
					printf("\n\n");
					system("pause");
				break;
				
			case 4: system("cls");
					printf("\n-Registro Oredenado Por Stock-\n\n");
					OrdenarPorStock(articulos, contador);
					MostrarOrdenado(articulos, contador);
					printf("\n\n");
					system("pause");
				break;
			
			case 0: system("cls");
					printf("\n\nCerrando Programa...\n\n\n");
				break;
				
			default: printf("\nOpcion ingresada NO se encuentra en el MENU...\n\n");
					 system("pause");
		}
		
		
	}while(opcion != 0);
	
}






