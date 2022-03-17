#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

const int N = 100;

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



void CargarVector(int vec[N], int min , int max)
{
	for(int i = 0; i < N; i++)
	{	
		vec[i] = GenerarEnteroAleatorio(min, max);	
	}	
}

void MostrarVector(int vec[N])
{
	printf("\nVector:\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	
	for(int i = 0; i < N; i++)
	{
	printf(" %d  ", vec[i]);
	}

}


float PromedioPares(int vec[N])
{
	float promedio = 0.0;
	int par = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(vec[i] % 2 == 0)
		{
			par = par + vec[i];
		}
		
	}
	
	promedio = (float) par / N;
	return promedio;
}

float PromedioImpares(int vec[N])
{
	float promedio = 0.0;
	int impar = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(vec[i] % 2 != 0)
		{
			impar = impar + vec[i];
		}
		
	}
	
	promedio = (float) impar / N;
	return promedio;
}


int SumaPares(int vec[N])
{
	int par = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(vec[i] % 2 == 0)
		{
			par = par + vec[i];
		}	
	}

	return par;
}


int SumaImpares(int vec[N])
{
	int impar = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(vec[i] % 2 != 0)
		{
			impar = impar + vec[i];
		}	
	}
	return impar;
}


main()
{
	int vector[N] = {0};
	int maximo = 0;
	int minimo = 0;
	float promedioNumPares = 0.0;
	float promedioNumImpares = 0.0;
	int sumaPares = 0;
	int sumaImpares = 0;
	
	printf("\nIngrese el minimo y el maximo numero del arreglo: ");
	scanf("%d %d",&minimo ,&maximo);
	
	system("cls");
	
	srand(time(NULL));
	
	CargarVector(vector, minimo, maximo);
	
	MostrarVector(vector);
	printf("\n------------------------------------------------------------------------------------------------------------------------");
	
	promedioNumPares = PromedioPares(vector);
	printf("\n\nEl promedio de los numeros pares es: %.2f", promedioNumPares);
	
	
	promedioNumImpares = PromedioImpares(vector);
	printf("\n\nEl promedio de los numeros impares es: %.2f", promedioNumImpares);
	
	printf("\n\n");
	
	sumaPares = SumaPares(vector);
	printf("La suma de los numeros pares es: %d", sumaPares);
	
	printf("\n\n");
	
	sumaImpares = SumaImpares(vector);
	printf("La suma de los numeros impares es: %d", sumaImpares);
	
	printf("\n\n");
	system("pause");
	
	
}
