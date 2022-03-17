#include <stdio.h>
#include <stdlib.h>


const int FILAS = 30;
const int COLUMNAS = 30;


void CargarMatriz(int mat[FILAS][COLUMNAS], int fil, int col)
{
	for(int f = 0; f < fil; f++)
	{
		
		for(int c = 0; c < col; c++)
		{
			printf("mat[%d][%d]= " , f, c);			
			scanf("%d", &mat[f][c]);
			
		
			
			while(mat[f][c] <= 0)
			{
				printf("\nEl valor no puede ser menor o igual a 0, porfavor ingrese nuevamente el elemento.\n\n");
				
				printf("mat[%d][%d]= " , f, c);			
				scanf("%d", &mat[f][c]);
			}
			
			
		}
	}
}


void MostrarMatriz(int mat[FILAS][COLUMNAS], int fil, int col)
{
	
	for(int f = 0; f < fil; f++)
	{
		
		for(int c = 0; c < col; c++)
		{
			printf(" %d", mat[f][c]);	
			
		}
		
		printf("\n");	

	}	
}


void CambiarElemento(int mat[FILAS][COLUMNAS], int fil, int col)
{	
	mat[fil-1][col-1] = 0;
}

void MostrarFila(int mat[FILAS][COLUMNAS], int filPivote, int col)
{
	for(int c=0; c<col; c++)
	{
		printf(" %d", mat[filPivote-1][c]);
		
	}
	
}


void MostrarColumna(int mat[FILAS][COLUMNAS], int fil, int colPivote)
{
	for(int f=0; f<fil; f++)
	{
		printf(" %d", mat[f][colPivote-1]);
		
		printf("\n");
		
	}
	
}


main()
{
	int matriz[FILAS][COLUMNAS];
	
	int filas = 0;
	int columnas = 0;
	
	int filaCambiar = 0;
	int columnaCambiar = 0;
	
	int filaPivote = 0;
	int columnaPivote = 0;
	
	printf("\nIngrese cantidad de filas: ");
	scanf("%d", &filas);
	
	printf("\nIngrese cantidad de columnas: ");
	scanf("%d", &columnas);
	
	
	CargarMatriz(matriz, filas, columnas);
	
	system("cls");
	printf("\n\n");
		
	MostrarMatriz(matriz, filas, columnas);
	
	printf("\n\n");
	
	printf("Ingrese elemento a cambiar por 0 Fila: ");
	scanf("%d", &filaCambiar);
	
	printf("Columna: ");
	scanf("%d", &columnaCambiar);
	
	CambiarElemento(matriz, filaCambiar, columnaCambiar);
	
	while(filaCambiar > filas | filaCambiar <= 0)
	{
		printf("\nEse elemnto no se encuentra en la matriz.\n\n");
		
		printf("Ingrese elemento a cambiar por 0 Fila: ");
		scanf("%d", &filaCambiar);
	
		printf("Columna: ");
		scanf("%d", &columnaCambiar);
		
		CambiarElemento(matriz, filaCambiar, columnaCambiar);
		
	}
	
	while(columnaCambiar > columnas | columnaCambiar <= 0)
	{
		printf("\nEse elemnto no se encuentra en la matriz.\n\n");
		
		printf("Ingrese elemento a cambiar por 0 Fila: ");
		scanf("%d", &filaCambiar);
	
		printf("Columna: ");
		scanf("%d", &columnaCambiar);
		
		CambiarElemento(matriz, filaCambiar, columnaCambiar);
		
	}
	
	printf("\n\n");
	
	MostrarMatriz(matriz, filas, columnas);
	
	printf("\n\n");
	
	printf("Que fila desea mostrar: ");
	scanf("%d", &filaPivote);
	
	while(filaPivote <= 0 | filaPivote > filas)
	{
		printf("\nEsa fila no se encuentra en la matriz, ingresar nuevamente.\n");
		
		printf("Que fila desea mostrar: ");
		scanf("%d", &filaPivote);	
	}
	
	
	printf("\n\n");
	
	MostrarFila(matriz, filaPivote, columnas);
	
	printf("\n\n");
	
	printf("Que columna desea mostrar: ");
	scanf("%d", &columnaPivote);
	
	while(columnaPivote <= 0 | columnaPivote > columnas)
	{
		printf("\nEsa columna no se encuentra en la matriz, ingresar nuevamente.\n");
		
		printf("Que fila desea mostrar: ");
		scanf("%d", &columnaPivote);	
	}
	
	printf("\n\n");
	
	MostrarColumna(matriz, filas, columnaPivote);
	
	printf("\n\n");
	system("pause");
}






