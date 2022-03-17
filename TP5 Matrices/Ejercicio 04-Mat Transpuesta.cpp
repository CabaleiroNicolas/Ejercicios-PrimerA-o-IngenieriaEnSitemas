#include <stdio.h>
#include <stdlib.h>


const int FILAS = 30;
const int COLUMNAS = 30;


void CargarMatriz(int matA[FILAS][COLUMNAS], int matB[FILAS][COLUMNAS], int fil, int col)
{
	
	for(int f = 0; f < fil; f++)
	{
		
		for(int c = 0; c < col; c++)
		{
			printf("A[%d][%d]= " , f, c);
			scanf("%d", &matA[f][c]);
			
			
			matB[c][f] = matA[f][c];
		}
		
		printf("\n");
	}
}


void MostrarMatrizA(int mat[FILAS][COLUMNAS], int fil, int col)
{
	printf("\nMatriz A:\n");
	for(int f = 0; f < fil; f++)
	{
		
		for(int c = 0; c < col; c++)
		{
			printf(" %d", mat[f][c]);	
			
		}
		
		printf("\n");	

	}	
}



void MostrarMatrizB(int mat[FILAS][COLUMNAS], int fil, int col)
{
	printf("\nMatriz B (A transpuesta):\n");
	
	for(int f = 0; f < fil; f++)
	{
		
		for(int c = 0; c < col; c++)
		{
			printf(" %d", mat[f][c]);	
			
		}
		
		printf("\n");	

	}	
}


main()
{
	int A[FILAS][COLUMNAS];
	int B[FILAS][COLUMNAS];
	
	int filasA = 0;
	int columnasA = 0;
	
	int filasB = 0;
	int columnasB = 0;
	
	printf("\n\n");
	printf("Ingrese cantidad de filas: ");
	scanf("%d", &filasA);
	
	printf("\nIngrese cantidad de columnas: ");
	scanf("%d", &columnasA);
	
	filasB = columnasA;
	columnasB = filasA;
	
	
	CargarMatriz(A, B, filasA, columnasA);
	
	system("cls");
	printf("\n\n");
	
	MostrarMatrizA(A, filasA, columnasA);
	
	printf("\n\n");
	
	MostrarMatrizB(B, filasB, columnasB);
	
	printf("\n\n\n");
	system("pause");
	

}
