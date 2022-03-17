#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int FILAS = 3;
const int COLUMNAS = 30;


int GenerarEnteroAleatorio(int min, int max)
{
	int enteroAleatorio = 0;
	int aux = 0;
	
	if(max < min)
	{
		max = aux;
		max = min;
		min = aux;
	}
	enteroAleatorio = min + rand() % (max + 1 - min);
		
	return enteroAleatorio;
}




void CargarMatrizAleatoria(int mat[FILAS][COLUMNAS], int col, int max, int min)
{
	for(int f = 0; f < FILAS; f++)
	{
		
		for(int c = 0; c < col; c++)
		{
			mat[f][c] = GenerarEnteroAleatorio(min, max);
		}
		
		printf("\n");
	}
}


void CalcularYMostrarProduccionDePrendas(int mat[FILAS][COLUMNAS], int col)
{
	int suma = 0;
	
	for(int f=0; f<FILAS; f++)
	{
		suma = 0;
		
		for(int c=0; c<col; c++)
		{
			
			suma = suma + mat[f][c];
			
			
			printf("  %d", mat[f][c]);
			
		}
		
		
		if(f == 0)printf("  Pantalones ==> %d", suma);
		if(f == 1)printf("  Camisas ==> %d", suma);
		if(f == 2)printf("  Remeras ==> %d", suma);
		
		printf("\n");
		
	}
	
}




int CalcularTallerConMayorProduccion(int mat[FILAS][COLUMNAS], int col, int &max)
{
	int mejorTaller = 0;
	
	int suma = 0;
	
	
	for(int c=0; c<col; c++)
	{
		suma = 0;
		
		for(int f=0; f<FILAS; f++)
		{
			
			suma = suma + mat[f][c];
			
			
		}
		
		if(suma > max)
		{
			max = suma;
			
			mejorTaller = c;
		}
		
	}
	
	
	return mejorTaller;
}

main()
{
	
	int matriz[FILAS][COLUMNAS];
	int talleres = 0;
	
	int valorMinimo = 0;
	int valorMaximo = 0;
	
	int mejorTaller = 0;
	int maximo = -1000;
	
	srand(time(NULL));
	
	printf("\nIngrese cantidad de talleres: ");
	scanf("%d", &talleres);
	
	printf("\nIngrese valor minimo de produccion: ");
	scanf("%d", &valorMinimo);
	
	printf("\nIngrese valor maximo de produccion: ");
	scanf("%d", &valorMaximo);
	
	system("cls");
	
	CargarMatrizAleatoria(matriz, talleres, valorMaximo, valorMinimo);
	
	printf("\n");
	
	CalcularYMostrarProduccionDePrendas(matriz, talleres);
	
	printf("\n");
	
	mejorTaller = CalcularTallerConMayorProduccion(matriz, talleres, maximo);
	
	printf("\nEl taller mas productivo fue el nro %d con %d ventas", mejorTaller+1, maximo);
	
	printf("\n\n\n");
	system("pause");
	
	
}






