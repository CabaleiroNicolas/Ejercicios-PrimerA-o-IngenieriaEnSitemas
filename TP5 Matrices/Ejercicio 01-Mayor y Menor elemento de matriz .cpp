#include <stdio.h>
#include <stdlib.h>


const int FILAS = 3;
const int COLUMNAS = 2;



void CargarMatriz(float mat[FILAS][COLUMNAS])
{
	for(int f = 0; f < FILAS; f++)
	{
		
		for(int c = 0; c < COLUMNAS; c++)
		{
			printf("mat[%d][%d]= " , f, c);
			
			scanf("%f", &mat[f][c]);
		}
	}
}



void MostrarMatriz(float mat[FILAS][COLUMNAS])
{
	
	for(int f = 0; f < FILAS; f++)
	{
		
		for(int c = 0; c < COLUMNAS; c++)
		{
			printf(" %.2f", mat[f][c]);	
			
		}	
		
		printf("\n");

	}	
}



float MayorYMenorElemento(float mat[FILAS][COLUMNAS], float &min)
{
	float max = -10000;
	
	for(int f=0; f<FILAS; f++)
	{
		for(int c=0; c<COLUMNAS; c++)
		{
			if(mat[f][c] > max)
			{
				max = mat[f][c];
			}	
		}
		
		for(int c=0; c<COLUMNAS; c++)
		{
			if(mat[f][c] < min)
			{
				min = mat[f][c];
			}	
		}
	}

	return max;
}


main()
{
	
	float matriz[FILAS][COLUMNAS];
	
	float valorMinimo = 100000;
	float valorMaximo = 0;
	
	
	printf("\n\n");
	
	CargarMatriz(matriz);
	
	system("cls");
	printf("\n\n");
	
	MostrarMatriz(matriz);
	
	valorMaximo = MayorYMenorElemento(matriz, valorMinimo);
	
	printf("\nEl valor maximo de la matriz es: %2.f", valorMaximo);
	printf("\nEl valor minimo de la matriz es: %2.f", valorMinimo);
	
	printf("\n\n");
	system("pause");
}
