#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[30];


int Menu()
{
	int opc = 0;
	
	printf("\n       --MENU--");
	printf("\n\n(1)- Ingresar dato de Socio");
	printf("\n(2)- Listar Socios");
	printf("\n(3)- Ordenar Decreciente");
	printf("\n(4)- Ordenar Creciente");
	printf("\n(5)- Buscar Socio");
	printf("\n(0)- SALIR.");
	
	printf("\n\nIngrese Opcion: ");
	scanf("%d", &opc);
	
	return opc;
}


void IngresarSocio(cadena socio[10], int &cont)
{	
		printf("\n\nNombre y Apellido: ");
		_flushall();
		gets(socio[cont]);
		cont++;	
}

void ListarSocios(cadena socio[10], int cont)
{
	for(int i = 0; i < cont; i++)
	{
		printf("\n%s", socio[i]);
	}
}


void OrdenarDecreciente(cadena socio[10], cadena aux,int cont)
{
	bool band;
	int L = cont - 1;
	
	do
	{
		band = false;
		
		for(int i = 0; i < L; i++)
		{
			if(strcmp(socio[i], socio[i+1]) < 0)
			{
				strcpy(aux, socio[i]);
				strcpy(socio[i], socio[i+1]);
				strcpy(socio[i+1], aux);
				
				band = true;
			}
			
		}
		L--;
		
	}while(band == true);
	
	printf("\nSocios Ordenados: \n");
	for(int i = 0; i < cont; i++)
	{
		printf("\n%s", socio[i]);
	}
}



void OrdenarCreciente(cadena socio[10], cadena vec[10], cadena aux,int cont)
{
	bool band;
	int L = cont - 1;
	

		for(int i = 0; i < cont; i++)
		{	
			strcpy(vec[i], socio[i]);
		}
	
	do
	{
		band = false;
		
		for(int i = 0; i < L; i++)
		{
			if(strcmp(socio[i], socio[i+1]) > 0)
			{
				strcpy(aux, vec[i]);
				strcpy(vec[i], vec[i+1]);
				strcpy(vec[i+1], aux);
				
				band = true;
			}
			
		}
		L--;
		
	}while(band == true);
	
	
	printf("\nSocios Ordenados: \n");
	for(int i = 0; i < cont; i++)
	{
		printf("\n%s", vec[i]);
	}
}



void BuscarApellido(cadena socio[10], int cont)
{
	char aBuscar[30];
	int veces = 0;
	int tamano = 0;
	
	char vector[200];
	
	
	printf("\nApellido a Buscar: ");
	_flushall();
	gets(aBuscar);
	
	for(int i = 0; i < cont; i++)
	{
		tamano = strlen(socio[i]);
		
		for(int j = 0; j < tamano; j++)
		{
			vector[j] = socio[j];
		}
		
		if(strcmp(aBuscar, vector[i]) == 0)
		{
			veces++;
		}
	}
	
	printf("\nEl Apellido %s se encuentra '%d' veces en la Lista.", aBuscar, veces);
}

main()
{
	int contador = 1;
	cadena socio[10];
	cadena aux;
	cadena array[10];
	
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
					printf("\n     -Ingresar Socio-");
					IngresarSocio(socio, contador);
					printf("\n\n");
					system("pause");
					break;
				}
			case 2:
				{
					printf("\n     -Lista de Socios-");
					ListarSocios(socio, contador);
					printf("\n\n");
					system("pause");
					break;
				}
			case 3:
				{
					printf("\n     -Ordenar Decreciente-");
					OrdenarDecreciente(socio, aux, contador);
					printf("\n\n");
					system("pause");
					break;
				}
			case 4:
				{
					printf("\n     -Ordenar Creciente-");
					OrdenarCreciente(socio, array, aux, contador);
					printf("\n\n");
					system("pause");
					break;
				}
			case 5:
				{
					printf("\n     -Buscar-");
					BuscarApellido(socio, contador);
					printf("\n\n");
					system("pause");
					break;
				}
		}
		
		
		
	}while(opcion != 0);
	
}
