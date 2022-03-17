#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int FILAS = 30;
const int COLUMNAS = 30;
const int PLANOS = 30;


void Cargar(int mat[PLANOS][FILAS][COLUMNAS], int fil, int col, int pla)
{
	for(int p = 0; p < pla; p++)
	{
		for(int f = 0; f < fil; f++)
		{
			for(int c = 0; c < col; c++)
			{	
				mat[p][f][c] = 1 + rand() % (3 + 1 - 1);
			}		
		}
	}
}


void Mostrar(int mat[PLANOS][FILAS][COLUMNAS], int fil, int col, int pla)
{
	
	for(int p = 0; p < pla; p++)
	{
		printf("\n\nHotel %d\n\n", p+1);

		for(int f = 0; f < fil; f++)
		{
			printf("Piso %d: ", f+1);
			
			for(int c = 0; c < col; c++)
			{
				printf(" %d", mat[p][f][c]);
			
				
			}
				printf("\n");
		
		}
	}
}

void DeterminarMejorHotel(int mat[PLANOS][FILAS][COLUMNAS], int fil, int col, int pla)
{
	int max = -1000;
	int suma = 0;
	int mejorHotel = 0;
	int huespedesMejorHotel = 0;
	
	for(int p = 0; p < pla; p++)
	{
		suma = 0;

		for(int f = 0; f < fil; f++)
		{	
			for(int c = 0; c < col; c++)
			{	
				suma = suma + mat[p][f][c];	
			}
		}
			
		if(suma > max)
		{	
			max = suma;
			mejorHotel = p;
			huespedesMejorHotel = suma;
			
		}
		
	}
	
	printf("\nEl hotel con mas huespedes fue el Nro %d con %d Personas.", mejorHotel+1, huespedesMejorHotel);	
}


main()
{
	
	srand(time(NULL));
	
	int matriz[PLANOS][FILAS][COLUMNAS];
	
	int hoteles = 0;
	int habitaciones = 0;
	int pisos= 0;
	
	printf("\nIngrese cantidad de Hoteles: ");
	scanf("%d", &hoteles);
	
	printf("\nIngrese cantidad de Pisos: ");
	scanf("%d", &pisos);
	
	printf("\nIngrese cantidad de Habitaciones: ");
	scanf("%d", &habitaciones);
	
	Cargar(matriz, pisos, habitaciones, hoteles);
	
	system("cls");
	
	Mostrar(matriz, pisos, habitaciones, hoteles);
	
	DeterminarMejorHotel(matriz, pisos, habitaciones, hoteles);
	
	printf("\n\n\n");
	system("pause");	
}

