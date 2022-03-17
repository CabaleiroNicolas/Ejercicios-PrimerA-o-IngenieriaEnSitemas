#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void OrdenarVector(int vec[50], int tamano)
{
	for(int i=0; i < tamano; i++)
	{
		printf("\nIngrese valor de vec[%d]: ", i);
		scanf("%d", &vec[i]);
	}//for	
}


int MinDelVector( int vec[50], int tamano)
{
	int minimo = 1000;
	
	for(int i = 0; i < tamano; i++)
	{
		if(vec[i] < minimo)
		{
			minimo = vec[i];
			
		}//if
		
	}//for
	
	return minimo;
}


void ListarVector(int vec[50], int tamano)
{
	printf("\nVector:");
	
	for(int i = 0; i < tamano; i++)
	{
		printf("  vec[%d]=%d", i, vec[i]);	
	}//for
	
	
	
}

main()
{
	int vector[50] = {0};
	int tamanoVector = 0;
	int minimo = 0;
	
	printf("\nIngrese tamaño del vector: ");
	scanf("%d", &tamanoVector);
	
	OrdenarVector(vector, tamanoVector);
	
	system("cls");
	
	minimo = MinDelVector(vector, tamanoVector);
	
	ListarVector(vector, tamanoVector);
	
	printf("\n\nEl menor numero del vector es: %d\n\n", minimo);
	
	system("pause");
}



