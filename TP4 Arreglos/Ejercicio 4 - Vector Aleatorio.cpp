#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

const int MAX = 432;
const int MIN = 1;
const int N = 100;

void GenerarNumerosAleatorios(int vec[N], int max, int min)
{
	srand(time(NULL));
	for(int i = 0; i < N; i++)
	{
		vec[i] = min + rand() % (max + 1 - min);
		
	}
	
}


void MostarVector(int vec[N])
{
	printf("\n\nContenido del vector: \n\n");
	for(int i = 0; i < N; i++)
	{

		printf(" %d  ",vec[i]);
	}
}


int MultiplosDeK(int vec[N], int k)
{
	int cantMultiplosK = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(vec[i] % k == 0)
		{
			cantMultiplosK++;	
		}

	}
	return cantMultiplosK;
}



main()
{
	int vector[N] = {0};	int n = 100;
	int k = 0;
	int multiplos = 0;
	
	
	GenerarNumerosAleatorios(vector, MAX, MIN);
	
	MostarVector(vector);
	
	printf("\n\nIngrese escalar: ");
	scanf("%d", &k);
	
	if(k > 0)
	{
		
	multiplos = MultiplosDeK(vector, k);
		
	printf("\nLa cantidad de multiplos de %d en el vector son: %d", k, multiplos);
	
	}
	else
	{
		printf("\nEl valor de k no puede ser 0 ni negativo...");
	}
	
	printf("\n\n");
	system("pause");
}
