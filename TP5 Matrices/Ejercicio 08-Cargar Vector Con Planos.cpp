#include <stdio.h>
#include <stdlib.h>


const int FILAS = 30;
const int COLUMNAS = 30;
const int PLANOS = 30;

const int TAMANO = PLANOS;


void CargarMatriz(int mat[PLANOS][FILAS][COLUMNAS], int fil, int col, int pla)
{

	int elemento = 0;

	for(int p = 0; p < pla; p++)
	{
		printf("\n");

		for(int f = 0; f < fil; f++)
		{
		
			for(int c = 0; c < col; c++)
			{
				printf("mat[%d][%d][%d]= ", p, f, c);
			
				scanf("%d", &mat[p][f][c]);
				
			}

		}
	}

}





void CargarVector(int mat[PLANOS][FILAS][COLUMNAS], int vec[TAMANO], int fil, int col, int pla)
{

	
	for(int p = 0; p < pla; p++)
	{
		

		for(int f = 0; f < fil; f++)
		{
		
			for(int c = 0; c < col; c++)
			{
				
				vec[p] = vec[p] + mat[p][f][c];
				
			}

		}
	}	
}



void MostrarVector(int vec[20], int planos)
{	
	printf("Vector:");
	
	for(int i = 0; i < planos; i++)
	{
		
		printf(" %d", vec[i]);
		
	}	
}






main()
{
	int matriz[PLANOS][FILAS][COLUMNAS];
	int vector[TAMANO];
	
	int planos = 0;
	int filas = 0;
	int columnas = 0;
	
	printf("\nIngrese cantidad de planos: ");
	scanf("%d", &planos);
	
	printf("\nIngrese cantidad de filas: ");
	scanf("%d", &filas);
	
	printf("\nIngrese cantidad de columnas: ");
	scanf("%d", &columnas);
	
	system("cls");
	printf("\n");
	
	CargarMatriz(matriz, filas, columnas, planos);
	
	system("cls");
	printf("\n");
	
	CargarVector(matriz, vector, filas, columnas, planos);
	
	printf("\n");
	
	MostrarVector(vector, planos);
	
	printf("\n\n");
	system("pause");

}


