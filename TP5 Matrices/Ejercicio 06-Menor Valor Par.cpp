#include <stdio.h>
#include <stdlib.h>


const int FILAS = 30;
const int COLUMNAS = 30;
const int PLANOS = 30;

void CargarMatrizTridimensional(float mat[PLANOS][FILAS][COLUMNAS], int fil, int col, int pla)
{


	for(int p = 0; p < pla; p++)
	{
		printf("\n");

		for(int f = 0; f < fil; f++)
		{
		
			for(int c = 0; c < col; c++)
			{
				printf("mat[%d][%d][%d]= ", p, f, c);
			
				scanf("%f", &mat[p][f][c]);
				
			}

		}
	}
}



float EncontrarMenorValor(float mat[PLANOS][FILAS][COLUMNAS], int pla, int fil, int col)
{
	
	float min = 10000.00;
	
	for(int p = 0; p < pla; p++)
	{

		for(int f = 0; f < fil; f++)
		{
		
			for(int c = 0; c < col; c++)
			{
				if(mat[p][f][c] < min)
				{
					min = mat[p][f][c];
					
				}
			}

		}
	}
	
	return min;
}


int MenorEsPar(int valor)
{
	int par = 0;
	
	if(valor % 2 == 0)
	{
		par = 1;
	}
	
	return par;	
}

main()
{
	float matriz[PLANOS][FILAS][COLUMNAS];
	
	int planos = 0;
	int filas = 0;
	int columnas = 0;
	
	float menorValor = 0.0;
	int par = 0;
	
	printf("\nIngrese cantidad de planos: ");
	scanf("%d", &planos);
	
	printf("\nIngrese cantidad de filas: ");
	scanf("%d", &filas);
	
	printf("\nIngrese cantidad de columnas: ");
	scanf("%d", &columnas);
	
	system("cls");
	printf("\n");
	
	CargarMatrizTridimensional(matriz, filas, columnas, planos);
	
	menorValor = EncontrarMenorValor(matriz, planos, filas, columnas);
	
	par = MenorEsPar(menorValor);
	
	if(par == 1)
	{	
		printf("\nEl menor valor %.2f es par", menorValor);
	}
	else
	{
		printf("\nEl menor valor %.2f es impar", menorValor);
	}
	
	
	
	
}









